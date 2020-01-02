/*
 * Dealer.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#ifndef DEALER_H_
#define DEALER_H_

#include "Rules.h"
#include "Hand.h"
#include "Defs.h"

#include <memory>

class Dealer {
public:
	explicit Dealer(std::shared_ptr<DealerStrategy> strategy);

	Card GetUpCard() const {
		return hand_.GetSecondCard();
	}

	void AddCard(const Card& card) {
		hand_.AddCard(card);
	}

	Action Go();

	const Hand& GetHand() const {
		return hand_;
	}

	bool HasBlackJack() const;

	void Clear();

	std::string ToString() const;

private:
	Hand hand_;
	std::shared_ptr<DealerStrategy> strategy_;
};

#endif /* DEALER_H_ */
