/*
 * Defs.cpp
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#include "Defs.h"

std::string ActionToString(Action action) {
	switch (action) {
		case Action::kHit:
			return "Hit";
		case Action::kStay:
			return "Stay";
		case Action::kDoubleDown:
			return "DoubleDown";
		case Action::kSplit:
			return "Split";
		case Action::kDone:
			return "Done";
	}
	return "";
}


