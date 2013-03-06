/*
 * Flop.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Flop.h"
#include "Player.h"
#include "Game.h"
#include "PlayerList.h"
#include <iostream>

void Flop::play()
{
	game->getDeck()->pick();
	game->getCardsOnTable()[0] = game->getDeck()->pick();
	game->getCardsOnTable()[1] = game->getDeck()->pick();
	game->getCardsOnTable()[2] = game->getDeck()->pick();
	game->setCardsOnTableCount(3);

	PlayerList *playerList = game->getPlayerList();
	playerList->setNextPlayer(1);

	playersToPlay = playerList->getPlayersInGameCount();

	game->setCurrentBet(0);
	bool eos = false;
	everyonePlayed = false;
	currentPlayer = 0;

	std::cout << "Flop" << std::endl;
	while(!eos)
	{
		Player *player = playerList->getNext();
		player->play();

		playerPlayed();
		eos = canEndState();
	}
	endOfState();
}

void Flop::setNextState()
{
	game->setCurrentState(game->getStateList()->getTurn());
}


Flop::~Flop() {
	// TODO Auto-generated destructor stub
}
