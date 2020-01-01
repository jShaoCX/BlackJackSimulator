/*
 * Shoe.cpp
 *
 *  Created on: Dec 27, 2019
 *      Author: Joe
 */

#include <algorithm>
#include <time.h>
#include <chrono>

#include <iostream>

#include "Shoe.h"
#include "Constants.h"

Shoe::Shoe(int num_decks) :
	cut_off_(0),
	num_decks_(num_decks),
	running_count_(0) {
	PopulateShoe();
	Reset();
}

int Shoe::GetTrueCount() const {
	int decks_left = (unused_cards_.size() / kDeckSize);
	if(decks_left == 0) {
		decks_left = 1;
	}
	return running_count_ / decks_left;
}

bool Shoe::AtCutOff() const {
	return unused_cards_.size() <= cut_off_;
}

void Shoe::BurnCard() {
	unused_cards_.erase(unused_cards_.begin());
}

void Shoe::Reset() {
	unused_cards_.clear();
	PopulateShoe();

	// can't just use time(0), srand based on time can potentially
	// get the same time seed, need millisecond precision.
	auto ms = std::chrono::time_point_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now()).time_since_epoch().count();
	srand(ms);

	cut_off_ = rand() % kDeckSize + kDeckSize / 2;
	std::random_shuffle(unused_cards_.begin(), unused_cards_.end());
	running_count_ = 0;
}

Card Shoe::GetNextCard() {
	Card next = unused_cards_.front();

	switch (next.type) {
	case CardType::k2:
	case CardType::k3:
	case CardType::k4:
	case CardType::k5:
	case CardType::k6:
		running_count_++;
		break;
	case CardType::k10:
	case CardType::kJack:
	case CardType::kQueen:
	case CardType::kKing:
	case CardType::kAce:
		running_count_--;
		break;
	case CardType::k7:
	case CardType::k8:
	case CardType::k9:
	case CardType::kUnknown:
		break;
	}

	BurnCard();
	return next;
}

void Shoe::PopulateShoe() {
	unused_cards_.reserve(num_decks_ * kDeckSize);

	int deck_num = 0;
	while(deck_num < num_decks_) {
		for (int i = 0; i < kTypeNumPerDeck; i++) {
			unused_cards_.push_back(CardFactory::Create2());
			unused_cards_.push_back(CardFactory::Create3());
			unused_cards_.push_back(CardFactory::Create4());
			unused_cards_.push_back(CardFactory::Create5());
			unused_cards_.push_back(CardFactory::Create6());
			unused_cards_.push_back(CardFactory::Create7());
			unused_cards_.push_back(CardFactory::Create8());
			unused_cards_.push_back(CardFactory::Create9());
			unused_cards_.push_back(CardFactory::Create10());
			unused_cards_.push_back(CardFactory::CreateJack());
			unused_cards_.push_back(CardFactory::CreateQueen());
			unused_cards_.push_back(CardFactory::CreateKing());
			unused_cards_.push_back(CardFactory::CreateAce());
		}
		deck_num++;
	}
}

std::string Shoe::ToString() const {
	std::string to_return = "Shoe has " +
		std::to_string(unused_cards_.size()) + " more cards, running count of " +
		std::to_string(running_count_) + ", cut off of " + std::to_string(cut_off_);

	return to_return;
}
