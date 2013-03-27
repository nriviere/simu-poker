/*
 * Call.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Fold.h"
#include "Game.h"
#include "Player.h"
#include "PlayerList.h"
#include <iostream>

using namespace std;


Fold::~Fold() {
	// TODO Auto-generated destructor stub
}

void Fold::execute() {
	game->getPlayerList()->fold();
	//player->setCurrentState(player->getStateList()->getFoldState());
	player->getStatistics()->incrementStat(FOLD,game->getState());
	int i = 0;
	for(list<Pot*>::iterator pot = game->getPots()->begin(); pot != game->getPots()->end();)
	{
		cout << "pot " << i << " : " << (*pot)->getRegisteredPlayers()->size() << endl;
		(*pot)->getRegisteredPlayers()->remove(player);
		cout << "pot " << i << " : " << (*pot)->getRegisteredPlayers()->size() << endl;
		++pot;
	}
}

