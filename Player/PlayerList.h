/*
 * PlayerList.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef PLAYERLIST_H_
#define PLAYERLIST_H_
#include "Player.h"
#include "Game.h"
#include <list>

class PlayerList {
public:
	PlayerList(Game *game, Player **players, int playerCount);
	virtual ~PlayerList();
	Player *getNext();
	Player *getNearestFromDealer();
	int getPlayerCount();
	int getPlayersInGameCount();
	void shuffle(Player **players, int playerCount);
	void setNextTurn();
	void setNextPlayer(int offsetFromDealer);
	bool isCheckable();
	bool canEndState();
	void initPlayersInGame();
	void eraseLosers();
	int allPayPot();
	void fold();

	list<Player*> getPlayersInGame() {
		return this->playersInGame;
	}

	list<Player*> getPlayers() {
		return this->players;
	}

private:
	int playerCount;
	Game *game;
	std::list<Player*> players;
	std::list<Player*> playersInGame;
	std::list<Player*>::iterator current;

};

#endif /* PLAYERLIST_H_ */
