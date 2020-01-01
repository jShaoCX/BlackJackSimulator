/*
 * Game.cpp
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#include <iostream>

#include "Game.h"
#include "Constants.h"

Game::Game() :
	min_bet_(10),
	black_jack_pay_(kPay3To2) {
}

void Game::SetShoe(std::unique_ptr<Shoe> shoe) {
	shoe_ = std::move(shoe);
}

void Game::SetDealer(std::unique_ptr<Dealer> dealer) {
	dealer_ = std::move(dealer);
}

void Game::AddPlayer(std::unique_ptr<Player> player) {
	players_.push_back(std::move(player));
}

void Game::AddPlayers(std::vector<std::unique_ptr<Player>>* players) {
	for(size_t i = 0; i < players->size(); i++) {
		players_.push_back(std::move(players_[i]));
		players->erase(players->begin());
	}
}

void Game::SetMinBet(int min_bet) {
	min_bet_ = min_bet;
}

void Game::SetBlackJackPays3To2() {
	black_jack_pay_ = kPay3To2;
}

void Game::SetBlackJackPays6To5() {
	black_jack_pay_ = kPay6To5;
}

void Game::Start(int num_iter) {
	int i = 0;
	while(i < num_iter) {
		shoe_->Reset();
		while(!shoe_->AtCutOff() && AreAnyPlayersIn()) {
			Deal();
			Play();
			PayOut();
			ClearTable();
		}
		i++;
	}
}

bool Game::AreAnyPlayersIn() const {
	bool are_any_in = false;
	int true_count = shoe_->GetTrueCount();
	for (const auto& player : players_) {
		if (player->IsIn(min_bet_, true_count)) {
			are_any_in = true;
		}
	}
	return are_any_in;
}

void Game::Deal() {
	std::cout << "Dealing..." << std::endl;
	int true_count = shoe_->GetTrueCount();

	for (const auto& player : players_) {
		if (player->IsIn(min_bet_, true_count)) {
			player->PlaceBet(min_bet_, true_count);
			player->Hit(shoe_->GetNextCard());
		}
	}
	dealer_->AddCard(shoe_->GetNextCard());
	for (const auto& player : players_) {
		if (player->IsIn(min_bet_, true_count)) {
			player->Hit(shoe_->GetNextCard());
		}
		std::cout << player->ToString() << std::endl;
	}
	dealer_->AddCard(shoe_->GetNextCard());
	std::cout << dealer_->ToString() << std::endl;
	std::cout << "Done Dealing..." << std::endl;
}

void Game::Play() {
	std::cout << "Play..." << std::endl;
	if(dealer_->HasBlackJack()) {
		std::cout << "Dealer has BlackJack" << std::endl;
		return;
	}

	for (const auto& player : players_) {
		if (!player->GetHands().empty()) {
			Action act = player->Go(dealer_->GetUpCard(), shoe_->GetTrueCount());
			while(act != Action::kDone) {
				std::cout << player->ToString() <<  " - Action: " << ActionToString(act) << std::endl;
				switch (act) {
					case Action::kHit:
						player->Hit(shoe_->GetNextCard());
						break;
					case Action::kSplit:
						// Need to add CanSplit() based on money
						player->Split(shoe_->GetNextCard(), shoe_->GetNextCard());
						break;
					case Action::kDoubleDown:
						// Need to add CanDoubleDown() based on money
						player->DoubleDown(shoe_->GetNextCard());
						break;
					case Action::kStay:
						player->Stay();
						break;
					case Action::kDone:
						break;
				}
				act = player->Go(dealer_->GetUpCard(), shoe_->GetTrueCount());
			}
			std::cout << player->ToString() << std::endl;
		}
	}
	Action dealer_act = dealer_->Go();
	while(dealer_act != Action::kDone) {
		std::cout << dealer_->ToString() <<  " - Action: " << ActionToString(dealer_act) << std::endl;
		switch (dealer_act) {
			case Action::kHit:
				dealer_->AddCard(shoe_->GetNextCard());
				break;
			case Action::kSplit:
			case Action::kDoubleDown:
			case Action::kDone:
			case Action::kStay:
				break;
		}
		dealer_act = dealer_->Go();
	}
	std::cout << dealer_->ToString() << std::endl;
	std::cout << "Done Playing..." << std::endl;
}

void Game::PayOut() {
	std::cout << "Pay Out..." << std::endl;
	// Take care of blackjacks first
	if(dealer_->HasBlackJack()) {
		for (const auto& player : players_) {
			if(player->HasBlackJack()) {
				continue;
			}
			for (Hand hand : player->GetHands()) {
				player->LoseMoney(hand.GetBet());
			}
		}
		return;
	}

	// dealer bust
	if(dealer_->GetHand().IsBusted()) {
		for (const auto& player : players_) {
			for (Hand hand : player->GetHands()) {
				if(!hand.IsBusted()) {
					player->WinMoney(hand.GetBet());
				} else {
					player->LoseMoney(hand.GetBet());
				}
			}
		}
	} else {
		for (const auto& player : players_) {
			if(player->HasBlackJack()) {
				player->WinMoney(player->GetHands()[0].GetBet() * black_jack_pay_);
				continue;
			}

			for (Hand hand : player->GetHands()) {
				if(hand.IsBusted()) {
					player->LoseMoney(hand.GetBet());
					continue;
				}

				if(hand.GetHandValue() > dealer_->GetHand().GetHandValue()) {
					player->WinMoney(hand.GetBet());
				} else if (hand.GetHandValue() < dealer_->GetHand().GetHandValue()) {
					player->LoseMoney(hand.GetBet());
				}
			}
		}
	}
	std::cout << "Done Paying Out..." << std::endl;
}

void Game::ClearTable() {
	std::cout << "Clear Table..." << std::endl;
	for (const auto& player : players_) {
		player->Clear();
		std::cout << player->ToString() << std::endl;
	}
	dealer_->Clear();
	std::cout << shoe_->ToString() << std::endl;
	std::cout << "Done Clearing Table..." << std::endl;
}

std::unordered_map<std::string, Player::Stats> Game::GetEndGameStats() const {
	std::unordered_map<std::string, Player::Stats> stats;
	for (const auto& player : players_) {
		stats[player->GetName()] = player->GetStats();
	}
	return stats;
}

void Game::ResetCurrentGame() {
	for (const auto& player : players_) {
		player->Reset();
	}
	dealer_->Clear();
	shoe_->Reset();
}
