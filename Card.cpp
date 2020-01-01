/*
 * Card.cpp
 *
 *  Created on: Dec 27, 2019
 *      Author: Joe
 */

#include "Card.h"

Card::Card(int value, int alt_value, CardType type) :
	value(value),
	alternate_value(alt_value),
	type(type) {
}

std::string Card::ToString() const {
	switch (type) {
		case CardType::kUnknown:
			return "Unknown";
		case CardType::k2:
			return "2";
		case CardType::k3:
			return "3";
		case CardType::k4:
			return "4";
		case CardType::k5:
			return "5";
		case CardType::k6:
			return "6";
		case CardType::k7:
			return "7";
		case CardType::k8:
			return "8";
		case CardType::k9:
			return "9";
		case CardType::k10:
			return "10";
		case CardType::kJack:
			return "Jack";
		case CardType::kQueen:
			return "Queen";
		case CardType::kKing:
			return "King";
		case CardType::kAce:
			return "Ace";
	}
	return "";
}

Card CardFactory::Create2() {
	return Card(2, 2, CardType::k2);
}

Card CardFactory::Create3() {
	return Card(3, 3, CardType::k3);
}

Card CardFactory::Create4() {
	return Card(4, 4, CardType::k4);
}

Card CardFactory::Create5() {
	return Card(5, 5, CardType::k5);
}

Card CardFactory::Create6() {
	return Card(6, 6, CardType::k6);
}

Card CardFactory::Create7() {
	return Card(7, 7, CardType::k7);
}

Card CardFactory::Create8() {
	return Card(8, 8, CardType::k8);
}

Card CardFactory::Create9() {
	return Card(9, 9, CardType::k9);
}

Card CardFactory::Create10() {
	return Card(10, 10, CardType::k10);
}

Card CardFactory::CreateJack() {
	return Card(10, 10, CardType::kJack);
}

Card CardFactory::CreateQueen() {
	return Card(10, 10, CardType::kQueen);
}

Card CardFactory::CreateKing() {
	return Card(10, 10, CardType::kKing);
}

Card CardFactory::CreateAce() {
	return Card(1, 11 , CardType::kAce);
}

Card CardFactory::CreateUnknown() {
	return Card(0, 0 , CardType::kUnknown);
}
