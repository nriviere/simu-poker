/*
 * River.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "River.h"
#include "Game.h"
#include "PlayerList.h"
#include "Player.h"
#include "HandPower.h"
#include <iostream>

void River::play() {
	game->getDeck()->pick();
	game->getCardsOnTable()[4] = game->getDeck()->pick();
	game->setCardsOnTableCount(5);

	PlayerList *playerList = game->getPlayerList();
	playerList->setNextPlayer(1);

	playersToPlay = playerList->getPlayersInGameCount();

	game->setCurrentBet(0);
	bool eos = false;
	everyonePlayed = false;
	currentPlayer = 0;

	std::cout << "River" << std::endl;
	while (!eos) {
		Player *player = playerList->getNext();
		player->play();

		playerPlayed();
		eos = canEndState();
	}
	this->endOfTurn();
}

void River::setNextState() {
	game->setCurrentState(game->getStateList()->getPreflop());
}

void River::endOfTurn() {
	//TODO : check for end game;
	int playersLeft = game->getPlayerList()->getPlayersInGameCount();
	if (playersLeft == 1) {
		GameState::endOfTurn();
	} else {
		std::list<Player *> maxPowerPlayers;
		char *max, *value;

		Player *player;
		player = game->getPlayerList()->getNext();
		max = player->getHandPower();
		maxPowerPlayers.push_back(player);

		std::cout << "Player : " << player->getId() << " " << max << std::endl;

		for (int i = 1; i < playersLeft; i++) {
			player = game->getPlayerList()->getNext();
			value = player->getHandPower();

			std::cout << "Player : " << player->getId() << " " << value
					<< std::endl;

			if (compare(value, max) > 0) {
				std::cout << "New Max : " << value << " > " << max << std::endl;
				max = value;
				maxPowerPlayers.clear();
				maxPowerPlayers.push_back(player);
			}
			if (compare(value, max) == 0) {
				maxPowerPlayers.push_back(player);
			}
		}
		std::cout << "Max : " << max << std::endl;

		game->updatePot();

		int amount = (int) (1. * game->getPot() / maxPowerPlayers.size());

		for (std::list<Player *>::iterator ite = maxPowerPlayers.begin(); ite
				!= maxPowerPlayers.end();) {
			std::cout << "Player : " << (*ite)->getId() << " wins !"
					<< std::endl;
			(*ite)->modifyBankRoll(amount);
			++ite;
		}
		game->setPot(0);
	}
	game->getPlayerList()->eraseLosers();
	if (canEndGame()) {
		std::cout << "End of game" << std::endl;
	} else {
		game->getPlayerList()->setNextTurn();
		game->setCurrentState(game->getStateList()->getPreflop());
		game->play();
	}
}

River::~River() {
	// TODO Auto-generated destructor stub
}
