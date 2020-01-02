/*
 * GameCreator.cpp
 *
 *  Created on: Jan 1, 2020
 *      Author: Joe
 */

#include "GameCreator.h"
#include <memory>

#include <iostream>

GameCreator::GameCreator() :
	dealer_strat_stay_soft_17_(new DealerStaysSoft17()),
	dealer_strat_hit_soft_17_(new DealerHitsSoft17()),
	perfect_strat_stay_soft_17_(new BasicStrategyDealerStaysSoft17()),
	perfect_strat_hit_soft_17_(new BasicStrategyDealerHitsSoft17()),
	average_strat_(new AverageBasicStrategy()),
	poor_strat_(new PoorBasicStrategy()),
	scaling_wonging_bet_(new ScalingWongingBetStrategy()),
	average_bet_(new AverageBetStrategy()),
	flat_bet_(new FlatBetStrategy()) {
}

std::unique_ptr<Game> GameCreator::PureBasicStrategy() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s3 = std::unique_ptr<Player>(
		new Player("Perfect10KFlat", 1000000, perfect_strat_stay_soft_17_, flat_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays3To2();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s3));
	return game;
}

std::unique_ptr<Game> GameCreator::PureBasicStrategy6To5() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s3 = std::unique_ptr<Player>(
			new Player("Perfect10KFlat", 1000000, perfect_strat_stay_soft_17_, flat_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays6To5();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s3));
	return game;
}

std::unique_ptr<Game> GameCreator::ComparePlayerQuality() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
			new Player("Perfect10KPerfect", 1000000, perfect_strat_stay_soft_17_, scaling_wonging_bet_));
	std::unique_ptr<Player> player_a2 = std::unique_ptr<Player>(
			new Player("Average10KAverage", 1000000, average_strat_, average_bet_));
	std::unique_ptr<Player> player_d2 = std::unique_ptr<Player>(
			new Player("Poor10KFlat", 1000000, poor_strat_, flat_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays3To2();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_a2));
	game->AddPlayer(std::move(player_d2));
	return game;
}

std::unique_ptr<Game> GameCreator::ComparePlayerQuality6To5() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
			new Player("Perfect10KPerfect", 1000000, perfect_strat_stay_soft_17_, scaling_wonging_bet_));
	std::unique_ptr<Player> player_a2 = std::unique_ptr<Player>(
			new Player("Average10KAverage", 1000000, average_strat_, average_bet_));
	std::unique_ptr<Player> player_d2 = std::unique_ptr<Player>(
			new Player("Poor10KFlat", 1000000, poor_strat_, flat_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays6To5();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_a2));
	game->AddPlayer(std::move(player_d2));
	return game;
}

std::unique_ptr<Game> GameCreator::ComparePerfectPlayers() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s1 = std::unique_ptr<Player>(
			new Player("Perfect2KPerfect", 200000, perfect_strat_stay_soft_17_, scaling_wonging_bet_));
	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
			new Player("Perfect10KPerfect", 1000000, perfect_strat_stay_soft_17_, scaling_wonging_bet_));
	std::unique_ptr<Player> player_s3 = std::unique_ptr<Player>(
			new Player("Perfect10KFlat", 1000000, perfect_strat_stay_soft_17_, flat_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays3To2();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s1));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_s3));
	return game;
}

std::unique_ptr<Game> GameCreator::OtherPerfectPlayerInterference() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
			new Player("Perfect10KPerfect", 1000000, perfect_strat_stay_soft_17_, scaling_wonging_bet_));
	std::unique_ptr<Player> player_s3 = std::unique_ptr<Player>(
			new Player("Perfect10KFlat", 1000000, perfect_strat_stay_soft_17_, flat_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays3To2();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_s3));
	return game;
}

std::unique_ptr<Game> GameCreator::OtherAveragePlayerInterference() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
			new Player("Perfect10KPerfect", 1000000, perfect_strat_stay_soft_17_, scaling_wonging_bet_));
	std::unique_ptr<Player> player_a2 = std::unique_ptr<Player>(
			new Player("Average10KAverage", 1000000, average_strat_, average_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays3To2();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_a2));
	return game;
}

std::unique_ptr<Game> GameCreator::OtherPoorPlayerInterference() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(dealer_strat_stay_soft_17_));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
			new Player("Perfect10KPerfect", 1000000, perfect_strat_stay_soft_17_, scaling_wonging_bet_));
	std::unique_ptr<Player> player_d3 =std::unique_ptr<Player>(
			new Player("Poor100KFlat", 10000000, poor_strat_, flat_bet_));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays3To2();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_d3));
	return game;
}
