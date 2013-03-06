/*
 * Preflop.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Preflop.h"
#include "Game.h"
#include "PlayerList.h"
#include "Player.h"

void Preflop::play()
{
	game->setCardsOnTableCount(0);
	PlayerList *playerList = game->getPlayerList();
	playerList->initPlayersInGame();
	playersToPlay = playerList->getPlayersInGameCount();

	playerList->setNextPlayer(1);
	playerList->getNext()->paySmallBlind();
	playerList->getNext()->payBigBlind();

	game->setCurrentBet(game->getBigBlindAmount());
	bool eos = false;
	everyonePlayed = false;
	currentPlayer = 0;
	Player *player;
	for(int i = 0; i < playerList->getPlayersInGameCount(); i++)
	{
		player = playerList->getNext();
		player->setHand(game->getDeck()->pick(),game->getDeck()->pick());
	}

	while(!eos)
	{
		player = playerList->getNext();
		player->play();
		playerPlayed();
		eos = canEndState();
	}
	endOfState();
}

void Preflop::setNextState()
{
	game->setCurrentState(game->getStateList()->getFlop());
}

Preflop::~Preflop() {
	// TODO Auto-generated destructor stub
}
