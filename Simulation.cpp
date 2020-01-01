/*
 * Simulation.cpp
 *
 *  Created on: Dec 31, 2019
 *      Author: Joe
 */

#include "Simulation.h"

#include <iostream>

Simulation::Simulation(int num_iterations, int shoes_per_iteration) :
	num_iterations_(num_iterations),
	shoes_per_iteration_(shoes_per_iteration) {
}

void Simulation::PureBasicStrategy() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s3("Perfect10KFlat", 1000000, &perfect_strat_stay_soft_17_, &flat_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays3To2();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);

	std::vector<Player*> basic_strategy_test = {&player_s3};

	game_.AddPlayers(basic_strategy_test);
	Start();
	PrintResults();
}

void Simulation::PureBasicStrategy6To5() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s3("Perfect10KFlat", 1000000, &perfect_strat_stay_soft_17_, &flat_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays6To5();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);

	std::vector<Player*> basic_strategy_test = {&player_s3};

	game_.AddPlayers(basic_strategy_test);
	Start();
	PrintResults();
}

void Simulation::ComparePlayerQuality() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s2("Perfect10KPerfect", 1000000, &perfect_strat_stay_soft_17_, &scaling_wonging_bet_);
	Player player_a2("Average10KAverage", 1000000, &average_strat_, &average_bet_);
	Player player_d2("Poor10KFlat", 1000000, &poor_strat_, &flat_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays3To2();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);

	// Comparing player quality
	std::vector<Player*> quality_test = {&player_s2, &player_a2, &player_d2};

	game_.AddPlayers(quality_test);
	Start();
	PrintResults();
}

void Simulation::ComparePlayerQuality6To5() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s2("Perfect10KPerfect", 1000000, &perfect_strat_stay_soft_17_, &scaling_wonging_bet_);
	Player player_a2("Average10KAverage", 1000000, &average_strat_, &average_bet_);
	Player player_d2("Poor10KFlat", 1000000, &poor_strat_, &flat_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays6To5();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);

	// Comparing player quality
	std::vector<Player*> quality_test = {&player_s2, &player_a2, &player_d2};

	game_.AddPlayers(quality_test);
	Start();
	PrintResults();
}

void Simulation::ComparePerfectPlayers() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s1("Perfect2KPerfect", 200000, &perfect_strat_stay_soft_17_, &scaling_wonging_bet_);
	Player player_s2("Perfect10KPerfect", 1000000, &perfect_strat_stay_soft_17_, &scaling_wonging_bet_);
	Player player_s3("Perfect10KFlat", 1000000, &perfect_strat_stay_soft_17_, &flat_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays3To2();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);

	// Comparing perfect players
	std::vector<Player*> perfect_player_test = {&player_s1, &player_s2, &player_s3};

	game_.AddPlayers(perfect_player_test);
	Start();
	PrintResults();
}

void Simulation::OtherPerfectPlayerInterference() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s2("Perfect10KPerfect", 1000000, &perfect_strat_stay_soft_17_, &scaling_wonging_bet_);
	Player player_s3("Perfect10KFlat", 1000000, &perfect_strat_stay_soft_17_, &flat_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays3To2();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);


	// Comparing other player affect (other is perfect)
	std::vector<Player*> perfect_vs_perfect_test = {&player_s2, &player_s3};

	game_.AddPlayers(perfect_vs_perfect_test);
	Start();
	PrintResults();
}

void Simulation::OtherAveragePlayerInterference() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s2("Perfect10KPerfect", 1000000, &perfect_strat_stay_soft_17_, &scaling_wonging_bet_);
	Player player_a2("Average10KAverage", 1000000, &average_strat_, &average_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays3To2();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);

	// Comparing other player affect (other is average)
	std::vector<Player*> perfect_vs_average_test = {&player_s2, &player_a2};

	game_.AddPlayers(perfect_vs_average_test);
	Start();
	PrintResults();
}

void Simulation::OtherPoorPlayerInterference() {
	// In pennies
	const int kMinBet = 1500;

	Shoe shoe(8);

	Dealer dealer(&dealer_strat_stay_soft_17_);

	Player player_s2("Perfect10KPerfect", 1000000, &perfect_strat_stay_soft_17_, &scaling_wonging_bet_);
	Player player_d3("Poor100KFlat", 10000000, &poor_strat_, &flat_bet_);

	game_.SetMinBet(kMinBet);
	game_.SetBlackJackPays3To2();

	game_.SetShoe(&shoe);
	game_.SetDealer(&dealer);

	// Comparing other player affect (other is poor)
	std::vector<Player*> perfect_vs_poor_test = {&player_s2, &player_d3};

	game_.AddPlayers(perfect_vs_poor_test);
	Start();
	PrintResults();
}

void Simulation::Start() {
	for(int i = 0; i < num_iterations_; i++) {
		game_.Start(shoes_per_iteration_);
		all_stats_.push_back(game_.GetEndGameStats());
		game_.ResetCurrentGame();
	}
}

void Simulation::PrintResults() {
	// Should use sstream and return string
	std::unordered_map<std::string, int> times_ruined;
	std::unordered_map<std::string, std::vector<double>> rois;

	std::cout << "--- Stats From Simulation ---" << std::endl;

	for (int i = 0; i < num_iterations_; i++) {
		std::cout << "Iteration " << i << std::endl;
		for (auto player_stat_pair : all_stats_[i]) {
			std::string is_ruined = player_stat_pair.second.is_ruined ?
				"is RUINED" : "is OK";

			printf("%s %s - roi for %d shoes: %.2f - initial bank: %.2f - end bank: %.2f\n",
					player_stat_pair.first.c_str(), is_ruined.c_str(), shoes_per_iteration_, player_stat_pair.second.roi,
					player_stat_pair.second.initial_bank_roll / 100.0, player_stat_pair.second.end_bank_roll / 100.0);

			if(player_stat_pair.second.is_ruined) {
				if(times_ruined.find(player_stat_pair.first) == times_ruined.end()) {
					times_ruined[player_stat_pair.first] = 1;
				} else {
					times_ruined[player_stat_pair.first] = times_ruined.at(player_stat_pair.first) + 1;
				}
			}
			rois[player_stat_pair.first].push_back(player_stat_pair.second.roi);
		}
	}

	std::cout << "--- Ruin Rate ---" << std::endl;

	for(auto ruin_pair : times_ruined) {
		printf("%s has been ruined %d / %d times \n", ruin_pair.first.c_str(),
				ruin_pair.second, num_iterations_);
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
