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
	Simulation(int num_iterations, int shoes_per_iteration, Game* game);

	void Start();

private:
	void PrintResults();

	int num_iterations_;
	int shoes_per_iteration_;
	Game* game_;

	std::vector<std::unordered_map<std::string, Player::Stats>> all_stats_;
};

#endif /* SIMULATION_H_ */
