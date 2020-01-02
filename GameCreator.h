/*
 * GameCreator.h
 *
 *  Created on: Jan 1, 2020
 *      Author: Joe
 */

#ifndef GAMECREATOR_H_
#define GAMECREATOR_H_

#include <memory>

#include "Rules.h"
#include "Game.h"

class GameCreator {
public:
	GameCreator();

	// pre packed simulations
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
	std::shared_ptr<DealerStaysSoft17> dealer_strat_stay_soft_17_;
	std::shared_ptr<DealerHitsSoft17> dealer_strat_hit_soft_17_;

	// For Player
	std::shared_ptr<BasicStrategyDealerStaysSoft17> perfect_strat_stay_soft_17_;
	std::shared_ptr<BasicStrategyDealerHitsSoft17> perfect_strat_hit_soft_17_;
	std::shared_ptr<AverageBasicStrategy> average_strat_;
	std::shared_ptr<PoorBasicStrategy> poor_strat_;

	// For Betting
	std::shared_ptr<ScalingWongingBetStrategy> scaling_wonging_bet_;
	std::shared_ptr<AverageBetStrategy> average_bet_;
	std::shared_ptr<FlatBetStrategy> flat_bet_;
};

#endif /* GAMECREATOR_H_ */
