/*
 * CountingPlayer.cpp
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#include "Player.h"
#include "Constants.h"

#include <sstream>
#include <iomanip>

Player::Player(const std::string& name, int bank_roll,
		std::shared_ptr<Strategy> strategy, std::shared_ptr<BetStrategy> bet_strategy) :
	name_(name),
	current_hand_idx_(0),
	bank_roll_(bank_roll),
	initial_bank_roll_(bank_roll),
	strategy_(strategy),
	bet_strategy_(bet_strategy) {
}

Player::Stats::Stats(bool is_ruined, double roi, int initial_bank_roll, int end_bank_roll) :
	is_ruined(is_ruined),
	roi(roi),
	initial_bank_roll(initial_bank_roll),
	end_bank_roll(end_bank_roll) {
}

Player::Stats::Stats() :
	is_ruined(false),
	roi(0.0),
	initial_bank_roll(0),
	end_bank_roll(0) {
}

Action Player::Go(const Card& up_card, int true_count) {
	if (current_hand_idx_ >= hands_.size()) {
		return Action::kDone;
	}

	if(hands_[current_hand_idx_].IsBusted()) {
		current_hand_idx_++;
		return Action::kStay;
	}

	return strategy_->Decide(up_card, hands_[current_hand_idx_]);
}

bool Player::IsIn(int min_bet, int true_count) {
	int bet = min_bet * bet_strategy_->GetMultiplier(true_count);
	if(bet > bank_roll_) {
		return false;
	}
	return bet_strategy_->IsIn(true_count);
}

void Player::PlaceBet(int min_bet, int true_count) {
	hands_.push_back(Hand(min_bet * bet_strategy_->GetMultiplier(true_count)));
}

bool Player::HasBlackJack() const {
	if (hands_.size() != 1) {
		return false;
	}
	if (!hands_[0].HasTwoCards()) {
		return false;
	}

	return hands_[0].GetHandValue() == kHandLimit &&
			(hands_[0].GetFirstCard().type == CardType::kAce ||
			 hands_[0].GetSecondCard().type == CardType::kAce);
}

void Player::Hit(const Card& card) {
	hands_[current_hand_idx_].AddCard(card);
}

void Player::Stay() {
	current_hand_idx_++;
}

void Player::Split(const Card& card_1, const Card& card_2) {
	hands_.push_back(Hand(hands_[current_hand_idx_].GetBet()));
	hands_[current_hand_idx_ + 1].AddCard(hands_[current_hand_idx_].RemoveCardForSplit());

	hands_[current_hand_idx_].AddCard(card_1);
	hands_[current_hand_idx_ + 1].AddCard(card_2);
}

void Player::DoubleDown(const Card& card) {
	hands_[current_hand_idx_].AddCard(card);
	hands_[current_hand_idx_].SetBet(hands_[current_hand_idx_].GetBet() * 2);
	current_hand_idx_++;
}

void Player::Clear() {
	current_hand_idx_ = 0;
	hands_.clear();
}

void Player::WinMoney(int amount) {
	bank_roll_ += amount;
}

void Player::LoseMoney(int amount) {
	bank_roll_ -= amount;
}

std::string Player::ToString() const {
	std::stringstream ss;
	ss << name_ << " ($" << std::fixed << std::setprecision(2) << bank_roll_ / 100.0 << ")";
	if(hands_.empty()) {
		ss << " is sitting out";
		return ss.str();
	}

	ss << " is in";
	for (Hand hand : hands_) {
		ss << " - " << hand.ToString();
	}
	return ss.str();
}

Player::Stats Player::GetStats() const {
	return Stats(initial_bank_roll_ * 0.05 > bank_roll_,
		(bank_roll_ - initial_bank_roll_) /
			static_cast<double>(initial_bank_roll_) * 100.0,
		initial_bank_roll_, bank_roll_);
}

void Player::Reset() {
	bank_roll_ = initial_bank_roll_;
	hands_.clear();
	current_hand_idx_ = 0;
}
