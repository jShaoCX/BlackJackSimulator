/*
 * Game.h
 *
 *  Created on: Dec 28, 2019
 *      Author: Joe
 */

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include <unordered_map>

#include "Dealer.h"
#include "Player.h"
#include "Shoe.h"

class Game {
public:
	Game();

	void SetShoe(Shoe* shoe);
	void SetDealer(Dealer* dealer);
	void AddPlayer(Player* player);
	void AddPlayers(const std::vector<Player*>& players);

	void SetMinBet(int min_bet);
	void SetBlackJackPays3To2();
	void SetBlackJackPays6To5();

	void Start(int num_iter);

	void ResetCurrentGame();

	std::unordered_map<std::string, Player::Stats> GetEndGameStats() const;

private:
	bool AreAnyPlayersIn() const;

	void Deal();
	void Play();
	void PayOut();
	void ClearTable();

	Dealer* dealer_;
	std::vector<Player*> players_;
	Shoe* shoe_;

	int min_bet_;
	double black_jack_pay_;
};

#endif /* GAME_H_ */
