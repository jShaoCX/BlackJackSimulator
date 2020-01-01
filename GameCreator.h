/*
 * GameCreator.h
 *
 *  Created on: Jan 1, 2020
 *      Author: Joe
 */

#ifndef GAMECREATOR_H_
#define GAMECREATOR_H_

#include "Rules.h"
#include "Game.h"

class GameCreator {
public:
	std::unique_ptr<Game> PureBasicStrategy();
	std::unique_ptr<Game> PureBasicStrategy6To5();

	std::unique_ptr<Game> ComparePlayerQuality();
	std::unique_ptr<Game> ComparePlayerQuality6To5();

	std::unique_ptr<Game> ComparePerfectPlayers();

	std::unique_ptr<Game> OtherPerfectPlayerInterference();
	std::unique_ptr<Game> OtherAveragePlayerInterference();
	std::unique_ptr<Game> OtherPoorPlayerInterference();

private:
	// All available strategies

	// For Dealer
	DealerStaysSoft17 dealer_strat_stay_soft_17_;
	DealerHitsSoft17 dealer_strat_hit_soft_17_;

	// For Player
	BasicStrategyDealerStaysSoft17 perfect_strat_stay_soft_17_;
	BasicStrategyDealerHitsSoft17 perfect_strat_hit_soft_17_;
	AverageBasicStrategy average_strat_;
	PoorBasicStrategy poor_strat_;

	// For Betting
	ScalingWongingBetStrategy scaling_wonging_bet_;
	AverageBetStrategy average_bet_;
	FlatBetStrategy flat_bet_;
};

#endif /* GAMECREATOR_H_ */
