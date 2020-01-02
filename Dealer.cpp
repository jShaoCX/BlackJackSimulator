/*
 * Dealer.cpp
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#include <iostream>

#include "Dealer.h"
#include "Constants.h"

Dealer::Dealer(std::shared_ptr<DealerStrategy> strategy) :
	hand_(0),
	strategy_(strategy) {}

Action Dealer::Go() {
	Action act = strategy_->Decide(hand_);
	if(act == Action::kHit) {
		return act;
	}
	return Action::kDone;
}

bool Dealer::HasBlackJack() const {
	return hand_.GetHandValue() == kHandLimit &&
			(hand_.GetFirstCard().type == CardType::kAce ||
			 hand_.GetSecondCard().type == CardType::kAce);
}

void Dealer::Clear() {
	hand_ = Hand(0);
}

std::string Dealer::ToString() const {
	return "Dealer - " + hand_.ToString() + " - up card " + GetUpCard().ToString();
}
