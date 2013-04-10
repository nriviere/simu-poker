/*
 * Game.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Game.h"
#include "Call.h"
#include "Raise.h"
#include "Check.h"
#include "Fold.h"
#include "AllIn.h"
#include "PlayerList.h"
#include <set>

Game::~Game() {
	delete stateList;
	delete playerList;
	delete deck;
}

Game::Game(Player **players, int playerCount, unsigned int smallBlindAmount) {
	currentPlayerId = 0;
	this->smallBlindAmount = smallBlindAmount;
	this->bigBlindAmount = smallBlindAmount * 2;
	this->playerList = new PlayerList(this, players, playerCount);
	this->stateList = new GameStateList(this);
	this->currentState = stateList->getPreflop();
	this->currentBet = 0;
	cardsOnTableCount = 0;
	canEndGame = false;
	currentPot = NULL;
	deck = new Deck();
	state = -1;
}

void Game::play() {
	while(!canEndGame)
	{
		this->currentState->play();
	}

}

void Game::raise(Player *player, int amount) {
	Raise *raise = new Raise(player, amount);
	raise->execute();
	this->actions.push_back(raise);
}

void Game::call(Player *player) {
	Call *call = new Call(player);
	call->execute();
	this->actions.push_back(call);
}

bool Game::isCheckable() {
	if (currentBet == 0) {
		return true;
	}
	return playerList->isCheckable();
}

void Game::check(Player *player) {
	Check *check = new Check(player);
	check->execute();
	this->actions.push_back(check);
}

void Game::fold(Player *player) {
	Fold *fold = new Fold(player);
	fold->execute();
	this->actions.push_back(fold);
}

void Game::allIn(Player *player, int amount) {
	AllIn *allIn = new AllIn(player, amount);
	allIn->execute();
	this->actions.push_back(allIn);
}

void Game::updatePot() {
	set<int> amounts;
	list<Player*> playersInGame = playerList->getPlayersInGame();
	list<Player*> players = playerList->getPlayers();
	int playerBet;
	for (list<Player*>::iterator p = playersInGame.begin(); p
			!= playersInGame.end();) {
		playerBet = (*p)->getCurrentBet();
		if (amounts.count(playerBet) == 0) {
			amounts.insert(playerBet);
		}
		++p;
	}

	if (amounts.size() == 1) {
		int amount = 0;
		for (list<Player*>::iterator p = players.begin(); p != players.end();) {
			amount += (*p)->getCurrentBet();
			(*p)->setCurrentBet(0);
			++p;
		}
		currentPot->updateAmount(amount);
	} else {
		int newBet = 0;
		int previousAmount = 0;
		set<int>::iterator ite = amounts.begin();
		for (list<Player*>::iterator p = players.begin(); p != players.end();) {
			playerBet = (*p)->getCurrentBet();

			if (playerBet != 0) {
				int valueToPay = (*ite);
				int paidValue = min(playerBet, valueToPay);
				currentPot->updateAmount(paidValue);
				newBet = playerBet - paidValue;
				(*p) -> setCurrentBet(newBet);
			}
			cout << "CURRENT POT VALUE : " << currentPot->getAmount() << endl;
			++p;
		}
		previousAmount = (*ite);
		for (++ite; ite != amounts.end();) {
			currentPot = new Pot(0);
			pots.push_back(currentPot);
			cout << "CURRENT AMOUNT : " << (*ite) << endl;
			for (list<Player*>::iterator p = players.begin(); p
					!= players.end();) {
				playerBet = (*p)->getCurrentBet();
				if (playerBet != 0) {
					int valueToPay = (*ite) - previousAmount;
					int paidValue = min(playerBet, valueToPay);
					currentPot->updateAmount(paidValue);
					newBet = playerBet - paidValue;
					(*p) -> setCurrentBet(newBet);
					cout << "newBet : " << newBet << endl;
					currentPot->registerPlayer((*p));
				}
				cout << "CURRENT POT VALUE : " << currentPot->getAmount() << endl;
				++p;
			}
			previousAmount = (*ite);

			++ite;
		}
	}
}

void Game::initDeck(){
	deck->init();
	deck->shuffle();
}

void Game::endOfTurn() {
	//determine le gagnant;
}

