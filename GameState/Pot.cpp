/*
 * Pot.cpp
 *
 *  Created on: 21 mars 2013
 *      Author: viande
 */

#include "Pot.h"

Pot::Pot() {
	amount = 0;
}

Pot::Pot(int amount) {
	this->amount = amount;
}

int Pot::updateAmount(int amount) {
	this->amount += amount;
	return amount;
}

void Pot::registerPlayer(Player *player) {
	registeredPlayers.push_back(player);
}

std::list<Player*> *Pot::getRegisteredPlayers() {
	return &registeredPlayers;
}

Pot::~Pot() {
}
