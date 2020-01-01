
#ifndef CARD_H_
#define CARD_H_

#include <string>

enum class CardType {
	kUnknown,
	k2,
	k3,
	k4,
	k5,
	k6,
	k7,
	k8,
	k9,
	k10,
	kJack,
	kQueen,
	kKing,
	kAce
};

struct Card {
	Card(int value, int alt_value, CardType type);

	int value = 0;
	int alternate_value = 0;
	CardType type;

	std::string ToString() const;
};

class CardFactory {
public:
	static Card Create2();
	static Card Create3();
	static Card Create4();
	static Card Create5();
	static Card Create6();
	static Card Create7();
	static Card Create8();
	static Card Create9();
	static Card Create10();
	static Card CreateJack();
	static Card CreateQueen();
	static Card CreateKing();
	static Card CreateAce();
	static Card CreateUnknown();
};

#endif /* CARD_H_ */
