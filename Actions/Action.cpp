/*
 * Action.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Action.h"
#include "Player.h"

Action::Action(Player *player) {
	this->game = player->getGame();
	this->player = player;
}
Action::~Action() {
	// TODO Auto-generated destructor stub
}
