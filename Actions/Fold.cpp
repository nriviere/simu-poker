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



Fold::~Fold() {
	// TODO Auto-generated destructor stub
}

void Fold::execute() {
	game->getPlayerList()->fold();
	//player->setCurrentState(player->getStateList()->getFoldState());
	player->getStatistics()->incrementStat(FOLD,game->getState());
}

