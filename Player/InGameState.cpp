/*
 * InGameState.cpp
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#include "InGameState.h"
#include "Player.h"
#include "Game.h"
#include "CommandLinePlayer.h"
#include <iostream>
using namespace std;


InGameState::~InGameState() {
	// TODO Auto-generated destructor stub
}

void InGameState::play()
{
	player->iPlay();
}

bool InGameState::canEndTurn()
{
	return player->getCurrentBet() == player->getGame()->getCurrentBet();
}


