/*
 * Hand.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <string>

#include "Card.h"

class Hand {
public:
	Hand(int bet);

	void AddCard(const Card& card);

	bool IsSplittable() const;

	bool IsBusted() const;

	bool IsSoftHand() const;

	bool HasTwoCards() const {
		return cards_.size() == 2;
	}

	Card GetFirstCard() const;
	Card GetSecondCard() const;
	Card GetHardCard() const;

	Card RemoveCardForSplit();

	void SetBet(int bet);
	int GetBet() const {
		return bet_;
	}

	int GetHandValue() const;

	std::string ToString() const;

private:
	std::vector<Card> cards_;
	// in pennies
	int bet_;
};

#endif /* HAND_H_ */
