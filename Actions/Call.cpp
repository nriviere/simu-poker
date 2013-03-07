/*
 * Call.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Call.h"
#include "Game.h"
#include "Player.h"

Call::~Call() {
	// TODO Auto-generated destructor stub
}

void Call::execute() {

	if (game->getCurrentBet() == 0) {
		int diff = game->getBigBlindAmount() - player->getCurrentBet();
		int left = player->modifyBankRoll(-diff);
		if (left > 0) {
			left = 0;
		}
		int amount = game->getBigBlindAmount() + left;
		game->setCurrentBet(amount);
		player->setCurrentBet(amount);
		player->getStatistics()->incrementStat(BET,game->getState());
	} else {
		int diff = game->getCurrentBet() - player->getCurrentBet();
		int left = player->modifyBankRoll(-diff);
		if (left > 0) {
			left = 0;
		}
		int amount = game->getCurrentBet() + left;
		player->setCurrentBet(amount);
		player->getStatistics()->incrementStat(CALL,game->getState());
	}
}

