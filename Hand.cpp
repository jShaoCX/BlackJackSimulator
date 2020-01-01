/*
 * Hand.cpp
 *
 *  Created on: Dec 27, 2019
 *      Author: Joe
 */

#include <sstream>
#include <iomanip>

#include "Hand.h"
#include "Constants.h"

Hand::Hand(int bet) :
	bet_(bet) {
}

void Hand::AddCard(const Card& card) {
	cards_.push_back(card);
}

bool Hand::IsSplittable() const {
	return cards_.size() == 2 && (cards_.at(0).type == cards_.at(1).type);
}

bool Hand::IsBusted() const {
	return GetHandValue() > kHandLimit;
}

bool Hand::IsSoftHand() const {
	return cards_.size() == 2 &&
		(cards_[0].type == CardType::kAce || cards_[1].type == CardType::kAce);
}

Card Hand::GetFirstCard() const {
	if(cards_.size() == 0) {
		return CardFactory::CreateUnknown();
	}
	return cards_[0];
}

Card Hand::GetSecondCard() const {
	if(cards_.size() == 1) {
		return CardFactory::CreateUnknown();
	}
	return cards_[1];
}

Card Hand::GetHardCard() const {
	if(cards_.size() != 2) {
		return CardFactory::CreateUnknown();
	}
	if(cards_[0].type != CardType::kAce) {
		return cards_[0];
	}
	if(cards_[1].type != CardType::kAce) {
		return cards_[1];
	}
	return CardFactory::CreateUnknown();
}

Card Hand::RemoveCardForSplit() {
	Card back = cards_.back();
	cards_.pop_back();
	return back;
}

void Hand::SetBet(int bet) {
	bet_ = bet;
}

int Hand::GetHandValue() const {
	int total = 0;
	int num_aces = 0;
	for (Card card : cards_) {
		if (card.type == CardType::kAce) {
			num_aces++;
		}
		total += card.value;
	}
	for (int i = 0; i < num_aces; i++) {
		if(total + 10 > kHandLimit) {
			continue;
		}
		total += 10;
	}
	return total;
}

std::string Hand::ToString() const {
	std::stringstream ss;
	ss << "Hand ($" << std::fixed << std::setprecision(2) << bet_ / 100.0 << ") : ";

	for (size_t i = 0; i < cards_.size(); i++) {
		ss << cards_[i].ToString();
		if(i < cards_.size() - 1) {
			ss << ", ";
		}
	}
	return ss.str();
}


