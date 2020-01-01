/*
 * Rules.cpp
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#include "Rules.h"

Action BasicStrategyDealerStaysSoft17::Decide(const Card& up_card, const Hand& hand) {
	if(hand.IsSplittable()) {
		switch (hand.GetFirstCard().type) {
			case CardType::k2:
			case CardType::k3: {
				if(up_card.alternate_value <= 7) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k4: {
				if(up_card.alternate_value == 5 || up_card.alternate_value == 6) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k5: {
				if(up_card.alternate_value <= 9) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k6: {
				if(up_card.alternate_value <= 6) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k7: {
				if(up_card.alternate_value <= 7) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k8:
				return Action::kSplit;
			case CardType::k9: {
				if(up_card.alternate_value == 7 ||
						up_card.alternate_value == 10 ||
						up_card.alternate_value == 11) {
					return Action::kStay;
				}
				return Action::kSplit;
			}
			case CardType::k10:
			case CardType::kJack:
			case CardType::kQueen:
			case CardType::kKing:
				return Action::kStay;
			case CardType::kAce:
				return Action::kSplit;
			case CardType::kUnknown:
				return Action::kStay;
		}
	}
	if(hand.IsSoftHand()) {
		switch (hand.GetHardCard().type) {
			case CardType::k2:
			case CardType::k3: {
				if(up_card.alternate_value == 5 || up_card.alternate_value == 6) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k4:
			case CardType::k5: {
				if(up_card.alternate_value >= 4 && up_card.alternate_value <= 6) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k6: {
				if(up_card.alternate_value >= 3 && up_card.alternate_value <= 6) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k7:  {
				if(up_card.alternate_value >= 3 && up_card.alternate_value <= 6) {
					return Action::kDoubleDown;
				}
				if(up_card.alternate_value == 2 ||
						up_card.alternate_value == 7 ||
						up_card.alternate_value == 8) {
					return Action::kStay;
				}
				return Action::kHit;
			}
			case CardType::k8:
			case CardType::k9:
			case CardType::k10:
			case CardType::kJack:
			case CardType::kQueen:
			case CardType::kKing:
			case CardType::kAce:
			case CardType::kUnknown:
				return Action::kStay;
		}
	}
	// hard hand
	if(hand.GetHandValue() <= 8) {
		return Action::kHit;
	}
	if(hand.GetHandValue() == 9) {
		if(up_card.alternate_value >= 3 && up_card.alternate_value <= 6) {
			return Action::kDoubleDown;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() == 10) {
		if(up_card.alternate_value <= 9) {
			return Action::kDoubleDown;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() == 11) {
		if(up_card.alternate_value <= 10) {
			return Action::kDoubleDown;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() == 12) {
		if(up_card.alternate_value >= 4 && up_card.alternate_value <= 6) {
			return Action::kStay;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() >= 13 && hand.GetHandValue() <= 16) {
		if(up_card.alternate_value <= 6) {
			return Action::kStay;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() >= 17) {
		return Action::kStay;
	}
	return Action::kStay;
}

Action BasicStrategyDealerHitsSoft17::Decide(const Card& up_card, const Hand& hand) {
	if(hand.IsSplittable()) {
		switch (hand.GetFirstCard().type) {
			case CardType::k2:
			case CardType::k3: {
				if(up_card.alternate_value <= 7) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k4: {
				if(up_card.alternate_value == 5 || up_card.alternate_value == 6) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k5: {
				if(up_card.alternate_value <= 9) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k6: {
				if(up_card.alternate_value <= 6) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k7: {
				if(up_card.alternate_value <= 7) {
					return Action::kSplit;
				}
				return Action::kHit;
			}
			case CardType::k8:
				return Action::kSplit;
			case CardType::k9: {
				if(up_card.alternate_value == 7 ||
						up_card.alternate_value == 10 ||
						up_card.alternate_value == 11) {
					return Action::kStay;
				}
				return Action::kSplit;
			}
			case CardType::k10:
			case CardType::kJack:
			case CardType::kQueen:
			case CardType::kKing:
				return Action::kStay;
			case CardType::kAce:
				return Action::kSplit;
			case CardType::kUnknown:
				return Action::kStay;
		}
	}
	if(hand.IsSoftHand()) {
		switch (hand.GetHardCard().type) {
			case CardType::k2:
			case CardType::k3: {
				if(up_card.alternate_value == 5 || up_card.alternate_value == 6) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k4:
			case CardType::k5: {
				if(up_card.alternate_value >= 4 && up_card.alternate_value <= 6) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k6: {
				if(up_card.alternate_value >= 3 && up_card.alternate_value <= 6) {
					return Action::kDoubleDown;
				}
				return Action::kHit;
			}
			case CardType::k7:  {
				if(up_card.alternate_value >= 2 && up_card.alternate_value <= 6) {
					return Action::kDoubleDown;
				}
				if(up_card.alternate_value == 7 || up_card.alternate_value == 8) {
					return Action::kStay;
				}
				return Action::kHit;
			}
			case CardType::k8: {
				if(up_card.alternate_value == 6) {
					return Action::kDoubleDown;
				}
				return Action::kStay;
			}
			case CardType::k9:
			case CardType::k10:
			case CardType::kJack:
			case CardType::kQueen:
			case CardType::kKing:
			case CardType::kAce:
			case CardType::kUnknown:
				return Action::kStay;
		}
	}
	// hard hand
	if(hand.GetHandValue() <= 8) {
		return Action::kHit;
	}
	if(hand.GetHandValue() == 9) {
		if(up_card.alternate_value >= 3 && up_card.alternate_value <= 6) {
			return Action::kDoubleDown;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() == 10) {
		if(up_card.alternate_value <= 9) {
			return Action::kDoubleDown;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() == 11) {
		return Action::kDoubleDown;
	}
	if(hand.GetHandValue() == 12) {
		if(up_card.alternate_value >= 4 && up_card.alternate_value <= 6) {
			return Action::kStay;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() >= 13 && hand.GetHandValue() <= 16) {
		if(up_card.alternate_value <= 6) {
			return Action::kStay;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() >= 17) {
		return Action::kStay;
	}
	return Action::kStay;
}

Action AverageBasicStrategy::Decide(const Card& up_card, const Hand& hand) {
	if(hand.IsSplittable()) {
		switch (hand.GetFirstCard().type) {
			case CardType::k2:
			case CardType::k3:
			case CardType::k4:
				return Action::kSplit;
			case CardType::k5:
				return Action::kHit;
			case CardType::k6:
			case CardType::k7:
			case CardType::k8:
			case CardType::k9:
				return Action::kSplit;
			case CardType::k10:
			case CardType::kJack:
			case CardType::kQueen:
			case CardType::kKing:
				return Action::kStay;
			case CardType::kAce:
				return Action::kSplit;
			case CardType::kUnknown:
				return Action::kStay;
		}
	}
	if(hand.IsSoftHand()) {
		switch (hand.GetHardCard().type) {
			case CardType::k2:
			case CardType::k3:
			case CardType::k4:
			case CardType::k5:
			case CardType::k6:
				return Action::kHit;
			case CardType::k7:
			case CardType::k8:
			case CardType::k9:
			case CardType::k10:
			case CardType::kJack:
			case CardType::kQueen:
			case CardType::kKing:
			case CardType::kAce:
			case CardType::kUnknown:
				return Action::kStay;
		}
	}
	// hard hand
	if(hand.GetHandValue() <= 10) {
		return Action::kHit;
	}
	if(hand.GetHandValue() == 11) {
		return Action::kDoubleDown;
	}
	if(hand.GetHandValue() >= 12 && hand.GetHandValue() <= 15) {
		if(up_card.alternate_value <= 6) {
			return Action::kStay;
		}
		return Action::kHit;
	}
	if(hand.GetHandValue() >= 16) {
		return Action::kStay;
	}
	return Action::kStay;
}

Action PoorBasicStrategy::Decide(const Card& up_card, const Hand& hand) {
	return Action::kStay;
}

Action DealerHitsSoft17::Decide(const Hand& hand) {
	if(hand.GetHandValue() == 17 && hand.IsSoftHand()) {
		return Action::kHit;
	}
	if(hand.GetHandValue() <= 16) {
		return Action::kHit;
	}
	return Action::kStay;
}

Action DealerStaysSoft17::Decide(const Hand& hand) {
	if(hand.GetHandValue() <= 16) {
		return Action::kHit;
	}
	return Action::kStay;
}

bool ScalingWongingBetStrategy::IsIn(int true_count) {
	if(true_count < 1) {
		return false;
	}
	return true;
}

int ScalingWongingBetStrategy::GetMultiplier(int true_count) {
	return true_count; // should be true_count - 1 and capped at some max?
}

bool AverageBetStrategy::IsIn(int true_count) {
	return true;
}

int AverageBetStrategy::GetMultiplier(int true_count) {
	if(true_count > 0) {
		return 2;
	}
	return 1;
}

bool FlatBetStrategy::IsIn(int true_count) {
	return true;
}

int FlatBetStrategy::GetMultiplier(int true_count) {
	return 1;
}
