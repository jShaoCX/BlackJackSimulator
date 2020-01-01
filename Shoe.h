/*
 * Shoe.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#ifndef SHOE_H_
#define SHOE_H_


/*
 * Shoe.cpp
 *
 *  Created on: Dec 27, 2019
 *      Author: Joe
 */
#include <vector>
#include <random>
#include <string>

#include "Card.h"

class Shoe {
public:
	explicit Shoe(int num_decks);

	void BurnCard();

	bool AtCutOff() const;

	int GetRunningCount() const {
		return running_count_;
	}

	int GetTrueCount() const;

	Card GetNextCard();

	// put all cards back, pick cutoff, shuffle
	void Reset();

	std::string ToString() const;

private:
	void PopulateShoe();

	std::vector<Card> unused_cards_;
	std::vector<Card> used_cards_;
	size_t cut_off_;
	int num_decks_;
	int running_count_;
};


#endif /* SHOE_H_ */
