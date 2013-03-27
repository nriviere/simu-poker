/*
 * CommandLinePlayer.cpp
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#include "CommandLinePlayer.h"
#include "Game.h"
#include <iostream>
#include <string>

using namespace std;

void CommandLinePlayer::iPlay() {
	cout << "############################################################################################" << endl;
	cout << "PLAYER : " << this->id << endl;
	cout << "Cards on table :";
	for(int i = 0; i < game->getCardsOnTableCount(); i++)
	{
		cout << " " << game->getCardsOnTable()[i]->getId();
	}
	cout << endl;
	cout << "Your hand : " << hand[0]->getId() << " " << hand[1]->getId() << endl;
	cout << endl;
	cout << "Current global bet : " << this->getGame()->getCurrentBet() << endl;
	cout << "Your bet : " << this->currentBet << endl;

	//cout << "Current pot : " << this->getGame()->getPot() << endl;
	cout << "Your bankroll  : " << this->bankRoll << endl;
	int ans;
	if (game->isCheckable()) {
		cout << "press 1 to fold, 2 to call, 3 to raise, 4 to check" << endl;
		do {
			cin >> ans;
		} while (ans != 1 && ans != 2 && ans != 3 && ans != 4);
	} else {
		cout << "press 1 to fold, 2 to call/bet, 3 to raise" << endl;
		do {
			cin >> ans;
		} while (ans != 1 && ans != 2 && ans != 3);
	}

	switch (ans) {
	case 1:
		fold();
		break;
	case 2:
		call();
		break;
	case 3:
		cout << "Amount (0 = minimum raise): " << endl;
		int amount;
		cin >> amount;
		raise(amount);
		break;
	case 4:
		check();
		break;
	}

}

Player *CommandLinePlayer::clone()  const
{
	return new CommandLinePlayer(*this);
}

CommandLinePlayer::~CommandLinePlayer() {
	// TODO Auto-generated destructor stub
}
