/*
 * Raise.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Raise.h"
#include "Game.h"
#include "Player.h"

Raise::~Raise() {
	// TODO Auto-generated destructor stub
}

void Raise::execute() {
	if (player->getBankRoll()<=0)
	{
		return;
	}
	int totalAmount = game->getCurrentBet() - player->getCurrentBet();
	totalAmount += game->getBigBlindAmount() + amount;
	int left = player->modifyBankRoll(-totalAmount);
	if (left > 0)
		left = 0;
	player->setCurrentBet(player->getCurrentBet() + totalAmount + left);
	game->setCurrentBet(player->getCurrentBet());
	
	player->getStatistics()->incrementStat(RAISE,game->getState());
	// TODO calculer montant moyen de la relance
}

