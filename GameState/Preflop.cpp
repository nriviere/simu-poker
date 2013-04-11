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

int times = 0;

void Preflop::play() {
	cout << "TIMES : " << times++ << endl;
	game->getDeck()->shuffle();
	game->setState(PFLOP);
	game->setCardsOnTableCount(0);
	Pot *pot = new Pot(0);
	PlayerList *playerList = game->getPlayerList();
	list<Player *> players = playerList->getPlayers();
	int sum = 0;


	for (list<Player*>::iterator p = players.begin(); p != players.end();) {
		pot->registerPlayer(*p);
		sum += (*p)->getBankRoll();
		++p;
	}

	game->setCurrentPot(pot);
	game->getPots()->push_back(pot);

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

	for (int i = 0; i < playerList->getPlayersInGameCount(); i++) {
		player = playerList->getNext();
		sum += player->getBankRoll();
		player->setHand(game->getDeck()->pick(), game->getDeck()->pick());
	}

	while (!eos) {
		player = playerList->getNext();
		player->play();
		playerPlayed();
		eos = canEndState();
	}
	endOfState();
}

void Preflop::setNextState() {
	game->setCurrentState(game->getStateList()->getFlop());
}

Preflop::~Preflop() {
	// TODO Auto-generated destructor stub
}
