/*
 * Simulation.h
 *
 *  Created on: Dec 31, 2019
 *      Author: Joe
 */

#ifndef SIMULATION_H_
#define SIMULATION_H_

#include <vector>
#include <unordered_map>

#include "Game.h"

class Simulation {
public:
	Simulation(int num_iterations, int shoes_per_iteration);

	void PureBasicStrategy();

	void ComparePlayerQuality();

	void PureBasicStrategy6To5();

	void ComparePlayerQuality6To5();

	void ComparePerfectPlayers();

	void OtherPerfectPlayerInterference();
	void OtherAveragePlayerInterference();
	void OtherPoorPlayerInterference();

private:
	void Start();
	void PrintResults();

	int num_iterations_;
	int shoes_per_iteration_;

	Game game_;
	std::vector<std::unordered_map<std::string, Player::Stats>> all_stats_;

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

#endif /* SIMULATION_H_ */
