/*
 * PlayerList.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "PlayerList.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "Game.h"
#include <iostream>
using namespace std;

PlayerList::PlayerList(Game *game, Player **players, int playerCount) {
	//shuffle(players, playerCount);
	this->playerCount = playerCount;
	this->game = game;
	for (int i = 0; i < playerCount; i++) {
		players[i]->setGame(game);
		int j = game->getCurrentPlayerId();
		players[i]->setId(j);
		this->players.push_back(players[i]);
		playersInGame.push_back(players[i]);
	}
	current = playersInGame.begin();
}

PlayerList::~PlayerList() {
}

Player *PlayerList::getNext() {
	if (current == playersInGame.end()) {
		current = playersInGame.begin();
	}
	Player *player = (*current);
	current++;
	return player;
}

void PlayerList::shuffle(Player **players, int playerCount) {
	int out, in;
	Player *tmp;
	srand(time(0));
	for (int i = 0; i < playerCount; i++) {
		out = rand() % playerCount;
		in = rand() % playerCount;
		tmp = players[in];
		players[in] = players[out];
		players[out] = tmp;
	}
}

bool PlayerList::isCheckable() {
	bool isCheckable = true;
	for (std::list<Player*>::iterator ite = playersInGame.begin(); ite
			!= playersInGame.end();) {
		if (!(*ite)->canEndState()) {
			isCheckable = false;
			return isCheckable;
		}
		++ite;
	}
	return isCheckable;
}

void PlayerList::initPlayersInGame() {
	playersInGame.clear();
	for (std::list<Player*>::iterator ite = players.begin(); ite
			!= players.end();) {
		Player *p = (*ite);
		playersInGame.push_back((*ite));
		++ite;
	}
}

void PlayerList::fold() {
	current--;
	current = playersInGame.erase(current);
}

void PlayerList::eraseLosers() {
	for (std::list<Player*>::iterator ite = players.begin(); ite
			!= players.end();) {
		std::cout << "Player " << (*ite)->getId() << " : "
				<< (*ite)->getBankRoll() << std::endl;
		if ((*ite)->getBankRoll() <= 0) {

			std::cout << "Player " << (*ite)->getId() << " lost ! " << endl;
			ite = players.erase(ite);
		} else {
			++ite;
		}
	}
	for (std::list<Player*>::iterator ite = playersInGame.begin(); ite
			!= playersInGame.end();) {
		if ((*ite)->getBankRoll() < 0) {
			playersInGame.erase(ite);
		}
		++ite;
	}

}

int PlayerList::allPayPot() {
	int sum = 0;
	for (std::list<Player*>::iterator ite = players.begin(); ite
			!= players.end();) {
		sum += (*ite)->getCurrentBet();
		(*ite)->setCurrentBet(0);
		++ite;
	}
	return sum;
}

bool PlayerList::canEndState() {
	cout << playersInGame.size() << endl;
	for (std::list<Player*>::iterator ite = playersInGame.begin(); ite
			!= playersInGame.end();) {
		if (!(*ite)->canEndState()) {
			return false;
		}
		++ite;
	}
	return true;
}

int PlayerList::getPlayerCount() {
	return players.size();
}

int PlayerList::getPlayersInGameCount() {
	return playersInGame.size();
}

void PlayerList::setNextTurn() {
	players.push_back(players.front());
	players.pop_front();
	initPlayersInGame();
}

void PlayerList::setNextPlayer(int offsetFromDealer) {
	current = playersInGame.begin();
	for (int i = 0; i < offsetFromDealer; i++) {
		current++;
	}
}

