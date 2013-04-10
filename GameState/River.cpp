/*
 * River.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "River.h"
#include "Game.h"
#include "PlayerList.h"
#include "Player.h"
#include "HandPower.h"
#include <iostream>

void River::play() {
	game->setState(RIVER);
	game->getDeck()->pick();
	game->getCardsOnTable()[4] = game->getDeck()->pick();
	game->setCardsOnTableCount(5);

	PlayerList *playerList = game->getPlayerList();
	playerList->setNextPlayer(1);

	playersToPlay = playerList->getPlayersInGameCount();

	game->setCurrentBet(0);
	bool eos = false;
	everyonePlayed = false;
	currentPlayer = 0;

	std::cout << "River" << std::endl;
	while (!eos) {
		Player *player = playerList->getNext();
		player->play();

		playerPlayed();
		eos = canEndState();
	}
	this->endOfTurn();
}

void River::setNextState() {
	game->setCurrentState(game->getStateList()->getPreflop());
}

void River::endOfTurn() {
	//TODO : check for end game;
	int playersLeft = game->getPlayerList()->getPlayersInGameCount();
	if (playersLeft == 1) {
		GameState::endOfTurn();
	} else {
		game->updatePot();
		list<Pot*>::iterator pot;
		cout << game->getPots()->size() << endl;
		for (pot = game->getPots()->begin(); pot != game->getPots()->end();) {
			std::list<Player *> maxPowerPlayers;
			char *max, *value;
			cout << "Players in pot " << (*pot)->getRegisteredPlayers()->size()
					<< endl;
			cout << "Pot value : " << (*pot)->getAmount() << endl;
			std::list<Player *>::iterator ite =
					(*pot)->getRegisteredPlayers()->begin();
			max = (*ite)->getHandPower();
			maxPowerPlayers.push_back((*ite));

			std::cout << "Player : " << (*ite)->getId() << " " << max
					<< std::endl;
			++ite;
			for (; ite != (*pot)->getRegisteredPlayers()->end();) {

				value = (*ite)->getHandPower();

				std::cout << "Player : " << (*ite)->getId() << " " << value
						<< std::endl;

				if (compare(value, max) > 0) {
					std::cout << "New Max : " << value << " > " << max
							<< std::endl;
					delete[] max;
					max = value;
					maxPowerPlayers.clear();
					maxPowerPlayers.push_back((*ite));
				} else if (compare(value, max) == 0) {
					std::cout << "Nouvelle egalité" << std::endl;
					maxPowerPlayers.push_back((*ite));
					for (list<Player*>::iterator p = maxPowerPlayers.begin();
							p != maxPowerPlayers.end(); ++p) {
						std::cout << "Player : " << (*p)->getId() << " "
								<< value << std::endl;
					}
				} else {
					delete[] value;
				}
				++ite;
			}
			std::cout << "Max : " << max << std::endl;

			int amount = (int) (1. * (*pot)->getAmount()
					/ maxPowerPlayers.size());
			int diff = (*pot)->getAmount() - amount * maxPowerPlayers.size();
			Player **winningPlayersByPosition =
					new Player *[maxPowerPlayers.size()];
			int pi = 0;
			for (std::list<Player *>::iterator ite = maxPowerPlayers.begin();
					ite != maxPowerPlayers.end();) {
				winningPlayersByPosition[pi++] = (*ite);
				++ite;
			}

			bool changed = true;
			while (changed) {
				changed = false;
				for (int i = 0; i < maxPowerPlayers.size()-1; i++) {
						if(winningPlayersByPosition[i]->getPosition()>winningPlayersByPosition[i+1]->getPosition())
						{
							Player *swp = winningPlayersByPosition[i];
							winningPlayersByPosition[i] = winningPlayersByPosition[i+1];
							winningPlayersByPosition[i+1] = swp;
							changed = true;
						}
				}
			}

			//std::cout << "current pot amount " <<
			for (std::list<Player *>::iterator ite = maxPowerPlayers.begin();
					ite != maxPowerPlayers.end();) {
				std::cout << "Player : " << (*ite)->getId() << " wins !"
						<< std::endl;
				(*ite)->modifyBankRoll(amount);
				++ite;
			}
			pi = 0;
			while(diff>0)
			{
				winningPlayersByPosition[pi]->modifyBankRoll(1);
				diff--;
			}

			delete[] max;
			++pot;
		}
		game->getPots()->clear();
	}
	game->getPlayerList()->eraseLosers();
	if (canEndGame()) {
		game->setEndGame();
		std::cout << "End of game" << std::endl;
	} else {
		game->getPlayerList()->setNextTurn();
		game->setCurrentState(game->getStateList()->getPreflop());
		//game->play();
	}
}

River::~River() {
// TODO Auto-generated destructor stub
}
