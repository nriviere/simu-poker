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
#include "PlayerList.h"

Game::~Game() {
	delete stateList;
	delete playerList;
	delete deck;
}

Game::Game(Player **players, int playerCount, unsigned int smallBlindAmount) {
	currentPlayerId = 0;
	this->smallBlindAmount = smallBlindAmount;
	this->bigBlindAmount = smallBlindAmount * 2;
	this->playerList = new PlayerList(this,players, playerCount);
	this->stateList = new GameStateList(this);
	this->currentState = stateList->getPreflop();
	this->currentBet = 0;
	this->pot = 0;
	this->deck = new Deck();
	state = -1;
}

void Game::play() {
	this->currentState->play();
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

bool Game::isCheckable()
{
	if(currentBet == 0)
	{
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

int Game::addToPot(int amount){
	return pot += amount;
}

int Game::updatePot()
{
	pot += playerList->allPayPot();
	return pot;
}

void Game::endOfTurn()
{
	//determine le gagnant;
}



