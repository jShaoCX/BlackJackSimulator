/*
 * GameCreator.h
 *
 *  Created on: Jan 1, 2020
 *      Author: Joe
 */

#ifndef GAMECREATOR_H_
#define GAMECREATOR_H_

#include <memory>

#include "Rules.h"
#include "Game.h"

class GameCreator {
public:
	// pre packed simulations
	std::unique_ptr<Game> PureBasicStrategy();
	std::unique_ptr<Game> PureBasicStrategy6To5();

	std::unique_ptr<Game> ComparePlayerQuality();
	std::unique_ptr<Game> ComparePlayerQuality6To5();

	std::unique_ptr<Game> OtherPerfectPlayerInterference();
	std::unique_ptr<Game> OtherAveragePlayerInterference();
	std::unique_ptr<Game> OtherPoorPlayerInterference();

	// Maybe add a builder here for custom games
};

#endif /* GAMECREATOR_H_ */
