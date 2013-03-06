/*
 * PlayerStateList.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "PlayerStateList.h"

PlayerStateList::PlayerStateList(Player *player) {
	this->player = player;
	inGameState = new InGameState(player);
	outGameState = new OutGameState(player);
	foldState = new FoldState(player);

}

PlayerStateList::~PlayerStateList() {
	delete inGameState;
	delete outGameState;
	delete foldState;
}
