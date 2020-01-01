/*
 * Player.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>

#include "Card.h"
#include "Defs.h"
#include "Rules.h"

class Player {
public:
	Player(const std::string& name, int bank_roll, Strategy* strategy, BetStrategy* bet_strategy);

	struct Stats {
		Stats();
		Stats(bool is_ruined, double roi, int initial_bank_roll, int end_bank_roll);
		bool is_ruined = false;
		double roi = 0.0;

		// Bank roll in pennies
		int initial_bank_roll = 0;
		int end_bank_roll = 0;
	};

	Action Go(const Card& up_card, int true_count);
	bool IsIn(int min_bet, int true_count);
	void PlaceBet(int min_bet, int true_count);

	const std::vector<Hand>& GetHands() const {
		return hands_;
	}

	bool HasBlackJack() const;

	void LoseMoney(int amount);
	void WinMoney(int amount);

	void Hit(const Card& card);
	void Stay();
	void Split(const Card& card_1, const Card& card_2);
	void DoubleDown(const Card& card);

	void Clear();

	int GetBankRoll() const {
		return bank_roll_;
	}

	int GetInitialBankRoll() const {
		return initial_bank_roll_;
	}

	Player::Stats GetStats() const;

	std::string GetName() const {
		return name_;
	}

	void Reset();

	std::string ToString() const;

private:
	const std::string name_;
	std::vector<Hand> hands_;
	size_t current_hand_idx_;

	// Bank roll is in pennies
	int bank_roll_;
	const int initial_bank_roll_;

	Strategy* strategy_;
	BetStrategy* bet_strategy_;
};

#endif /* PLAYER_H_ */
