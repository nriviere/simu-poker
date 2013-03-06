/*
 * PlayerState.cpp
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#include "PlayerState.h"

PlayerState::PlayerState(Player *player) {
	this->player = player;
}

bool PlayerState::canEndTurn()
{
	return true;
}

PlayerState::~PlayerState() {
	// TODO Auto-generated destructor stub
}
