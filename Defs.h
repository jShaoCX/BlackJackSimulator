/*
 * Defs.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#ifndef DEFS_H_
#define DEFS_H_

#include <string>

enum class Action {
	kHit,
	kStay,
	kDoubleDown,
	kSplit,
	kDone,
};

std::string ActionToString(Action action);

#endif /* DEFS_H_ */
