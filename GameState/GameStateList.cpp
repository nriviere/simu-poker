/*
 * GameStateList.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "GameStateList.h"

GameStateList::GameStateList(Game *game) {
	this->game = game;
	preflop = new Preflop(game);
	flop = new Flop(game);
	turn = new Turn(game);
	river = new River(game);
}

GameStateList::~GameStateList() {
	delete preflop;
	delete flop;
	delete turn;
	delete river;
}
