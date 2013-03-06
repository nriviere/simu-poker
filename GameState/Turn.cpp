/*
 * Turn.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Turn.h"
#include "Player.h"
#include "Game.h"
#include "PlayerList.h"
#include <iostream>


void Turn::play()
{
	game->getDeck()->pick();
	game->getCardsOnTable()[3] = game->getDeck()->pick();
	game->setCardsOnTableCount(4);

	PlayerList *playerList = game->getPlayerList();
	playerList->setNextPlayer(1);

	playersToPlay = playerList->getPlayersInGameCount();

	game->setCurrentBet(0);
	bool eos = false;
	everyonePlayed = false;
	currentPlayer = 0;

	std::cout << "Turn" << std::endl;
	while(!eos)
	{
		Player *player = playerList->getNext();
		player->play();

		playerPlayed();
		eos = canEndState();
	}
	endOfState();
}

void Turn::setNextState()
{
	game->setCurrentState(game->getStateList()->getRiver());
}

Turn::~Turn() {
	// TODO Auto-generated destructor stub
}
