/*
 * Simulation.cpp
 *
 *  Created on: Dec 31, 2019
 *      Author: Joe
 */

#include "Simulation.h"

#include <algorithm>
#include <iostream>

Simulation::Simulation(int num_iterations, int shoes_per_iteration, Game* game) :
	num_iterations_(num_iterations),
	shoes_per_iteration_(shoes_per_iteration),
	game_(game) {
}

Simulation::Simulation(int num_iterations, int shoes_per_iteration, GameCreator* creator) :
	num_iterations_(num_iterations),
	shoes_per_iteration_(shoes_per_iteration),
	creator_(creator) {
}

void Simulation::Start() {
	for(int i = 0; i < num_iterations_; i++) {
		game_->Start(shoes_per_iteration_);
		all_stats_.push_back(game_->GetEndGameStats());
		game_->ResetCurrentGame();
	}
	PrintResults();
}

void Simulation::StartMultiThreaded() {
	for(int i = 0; i < num_iterations_; i++) {
		workers_.push_back(std::thread([this, i](){
			auto game = creator_->OtherPoorPlayerInterference();
			game->Start(shoes_per_iteration_);
			all_stats_.push_back(game->GetEndGameStats());
			game->ResetCurrentGame();
			std::cout << "Done with iteration " << i << std::endl;
		}));
	}

	for (auto& worker : workers_) {
		if(worker.joinable()) {
			worker.join();
		}
	}
	PrintResults();
}

void Simulation::PrintResults() {
	// Should use sstream and return string
	std::unordered_map<std::string, int> times_ruined;
	std::unordered_map<std::string, std::vector<double>> rois;
	std::unordered_map<std::string, std::vector<std::vector<int>>> bank_roll_records;

	std::cout << "--- Stats From Simulation ---" << std::endl;

	for (int i = 0; i < num_iterations_; i++) {
//		std::cout << "Iteration " << i << std::endl;
		for (auto player_stat_pair : all_stats_[i]) {
//			std::string is_ruined = player_stat_pair.second.is_ruined ?
//				"is RUINED" : "is OK";
//
//			printf("%s %s - roi for %d shoes: %.2f - initial bank: %.2f - end bank: %.2f\n",
//					player_stat_pair.first.c_str(), is_ruined.c_str(), shoes_per_iteration_, player_stat_pair.second.roi,
//					player_stat_pair.second.initial_bank_roll / 100.0, player_stat_pair.second.end_bank_roll / 100.0);

			if(player_stat_pair.second.is_ruined) {
				if(times_ruined.find(player_stat_pair.first) == times_ruined.end()) {
					times_ruined[player_stat_pair.first] = 1;
				} else {
					times_ruined[player_stat_pair.first] = times_ruined.at(player_stat_pair.first) + 1;
				}
			}
			rois[player_stat_pair.first].push_back(player_stat_pair.second.roi);
			bank_roll_records[player_stat_pair.first].push_back(player_stat_pair.second.bank_roll_record);
		}
	}

	std::cout << "--- Ruin Rate ---" << std::endl;

	for(auto ruin_pair : times_ruined) {
		printf("%s has been ruined %d / %d times \n", ruin_pair.first.c_str(),
				ruin_pair.second, num_iterations_);
	}

	std::cout << "--- Variance ---" << std::endl;

	for(auto bank_roll_pair : bank_roll_records) {
		double ave_min = 0;
		double ave_max = 0;
		for(auto single_run : bank_roll_pair.second) {
			double min = *std::min_element(single_run.begin(), single_run.end()) / 100.0;
		    double max = *std::max_element(single_run.begin(), single_run.end()) / 100.0;
		    ave_min += min;
		    ave_max += max;
		}
		if(bank_roll_pair.second.size() > 0) {
			ave_min /= bank_roll_pair.second.size();
			ave_max /= bank_roll_pair.second.size();
		}

		double stdev_min = 0;
		double stdev_max = 0;

		for(auto single_run : bank_roll_pair.second) {
			double min = *std::min_element(single_run.begin(), single_run.end()) / 100.0;
		    double max = *std::max_element(single_run.begin(), single_run.end()) / 100.0;
		    stdev_min += std::pow((ave_min - min), 2.0);
		    stdev_max += std::pow((ave_max - max), 2.0);
		}

		if(bank_roll_pair.second.size() > 0) {
			stdev_min = std::sqrt(stdev_min / bank_roll_pair.second.size());
			stdev_max = std::sqrt(stdev_max / bank_roll_pair.second.size());
		}

		printf("%s min/max bank: (%.2f +/- %.2f, %.2f +/- %.2f)\n",
			bank_roll_pair.first.c_str(), ave_min, stdev_min, ave_max, stdev_max);
	}

	std::cout << "--- Mean ROI ---" << std::endl;

	for(auto roi_pair : rois) {
		if(roi_pair.second.size() != 0) {
			double ave = 0;
			for (double roi : roi_pair.second) {
				ave += roi;
			}
			ave = ave / roi_pair.second.size();
			printf("%s average roi per iteration per shoe %.2f%% \n", roi_pair.first.c_str(), ave / shoes_per_iteration_);
		}
	}
}
