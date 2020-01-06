/*
 * GameCreator.cpp
 *
 *  Created on: Jan 1, 2020
 *      Author: Joe
 */

#include "GameCreator.h"
#include <memory>

#include <iostream>

std::unique_ptr<Game> GameCreator::PureBasicStrategy() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(
			std::unique_ptr<DealerStaysSoft17>(new DealerStaysSoft17())));

	std::unique_ptr<Player> player_s3 = std::unique_ptr<Player>(
		new Player("Perfect10KFlat", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));

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
		std::unique_ptr<Dealer>(new Dealer(
			std::unique_ptr<DealerStaysSoft17>(new DealerStaysSoft17())));

	std::unique_ptr<Player> player_s3 = std::unique_ptr<Player>(
		new Player("Perfect10KFlat", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));
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
		std::unique_ptr<Dealer>(new Dealer(
			std::unique_ptr<DealerStaysSoft17>(new DealerStaysSoft17())));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
		new Player("Perfect10KPerfect", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<ScalingWongingBetStrategy>(new ScalingWongingBetStrategy())));
	std::unique_ptr<Player> player_a2 = std::unique_ptr<Player>(
		new Player("Average10KAverage", 1000000,
			std::unique_ptr<AverageBasicStrategy>(new AverageBasicStrategy()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));
	std::unique_ptr<Player> player_d2 =std::unique_ptr<Player>(
		new Player("Poor10KFlat", 1000000, std::unique_ptr<PoorBasicStrategy>(new PoorBasicStrategy()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));

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
		std::unique_ptr<Dealer>(new Dealer(
			std::unique_ptr<DealerStaysSoft17>(new DealerStaysSoft17())));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
		new Player("Perfect10KPerfect", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<ScalingWongingBetStrategy>(new ScalingWongingBetStrategy())));
	std::unique_ptr<Player> player_a2 = std::unique_ptr<Player>(
		new Player("Average10KAverage", 1000000,
			std::unique_ptr<AverageBasicStrategy>(new AverageBasicStrategy()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));
	std::unique_ptr<Player> player_d2 =std::unique_ptr<Player>(
		new Player("Poor10KFlat", 1000000, std::unique_ptr<PoorBasicStrategy>(new PoorBasicStrategy()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));


	game->SetMinBet(kMinBet);
	game->SetBlackJackPays6To5();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_a2));
	game->AddPlayer(std::move(player_d2));
	return game;
}

std::unique_ptr<Game> GameCreator::OtherPerfectPlayerInterference() {
	std::unique_ptr<Game> game = std::unique_ptr<Game>(new Game());

	// In pennies
	int kMinBet = 1500;
	std::unique_ptr<Shoe> shoe = std::unique_ptr<Shoe>(new Shoe(8));

	std::unique_ptr<Dealer> dealer =
		std::unique_ptr<Dealer>(new Dealer(
			std::unique_ptr<DealerStaysSoft17>(new DealerStaysSoft17())));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
		new Player("Perfect10KPerfect", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<ScalingWongingBetStrategy>(new ScalingWongingBetStrategy())));
	std::unique_ptr<Player> player_s3 = std::unique_ptr<Player>(
		new Player("Perfect10KFlat", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));

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
		std::unique_ptr<Dealer>(new Dealer(
			std::unique_ptr<DealerStaysSoft17>(new DealerStaysSoft17())));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
		new Player("Perfect10KPerfect", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<ScalingWongingBetStrategy>(new ScalingWongingBetStrategy())));
	std::unique_ptr<Player> player_a2 = std::unique_ptr<Player>(
		new Player("Average10KAverage", 1000000,
			std::unique_ptr<AverageBasicStrategy>(new AverageBasicStrategy()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));

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
		std::unique_ptr<Dealer>(new Dealer(
			std::unique_ptr<DealerStaysSoft17>(new DealerStaysSoft17())));

	std::unique_ptr<Player> player_s2 = std::unique_ptr<Player>(
		new Player("Perfect10KPerfect", 1000000,
			std::unique_ptr<BasicStrategyDealerStaysSoft17>(new BasicStrategyDealerStaysSoft17()),
			std::unique_ptr<ScalingWongingBetStrategy>(new ScalingWongingBetStrategy())));
	std::unique_ptr<Player> player_d3 =std::unique_ptr<Player>(
		new Player("PoorMilFlat", 100000000, std::unique_ptr<PoorBasicStrategy>(new PoorBasicStrategy()),
			std::unique_ptr<FlatBetStrategy>(new FlatBetStrategy())));

	game->SetMinBet(kMinBet);
	game->SetBlackJackPays3To2();

	game->SetShoe(std::move(shoe));
	game->SetDealer(std::move(dealer));
	game->AddPlayer(std::move(player_s2));
	game->AddPlayer(std::move(player_d3));
	return game;
}
