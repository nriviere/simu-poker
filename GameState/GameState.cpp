/*
 * GameState.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "GameState.h"
#include "PlayerList.h"
#include "Game.h"
#include <iostream>

GameState::GameState(Game *game) {
	this->game = game;
	playerCount = game->getPlayerList()->getPlayerCount();
	currentPlayer = 0;
}

void GameState::playerPlayed() {
	currentPlayer++;
	if (currentPlayer == playersToPlay) {
		everyonePlayed = true;
	}
}

GameState::~GameState() {

}

bool GameState::canEndState() {
	PlayerList *playerList = game->getPlayerList();
	if (everyonePlayed == false) {
		return false;
	}
	return playerList->canEndState();
}

bool GameState::canEndGame() {
	if (game->getPlayerList()->getPlayerCount() == 1) {
		return true;
	}
	return false;
}

void GameState::endOfState() {
	game->updatePot();
	int p = game->getPlayerList()->getPlayersInGameCount();
	std::cout << "End of state :  playerCount = " << p << std::endl;
	if (game->getPlayerList()->getPlayersInGameCount() == 1) {
		endOfTurn();
	} else {
		setNextState();
		game->play();
	}
}

void GameState::endOfTurn() {
	//TODO : check for end game;
	PlayerList *playerList = game->getPlayerList();
	Player * player = playerList->getNext();
	//TODO : Faire ca dans l'interface ex : creer une fonction win(player,amount) qui appelle la fonction win(amount) de player et qu'on peut redéfinir dans les joueurs interfacés.
	std::cout << "End of turn." << std::endl;
	std::cout << "Player " << player->getId() << " wins ! " << std::endl;
	//std::cout << "Pot :  " << game->getPot() << std::endl;
	std::cout << "Previous bankroll : " << player->getBankRoll();
	player->modifyBankRoll(game->getCurrentPot()->getAmount());
	std::cout << ", new bankroll : " << player->getBankRoll() << std::endl;

	playerList->eraseLosers();
	if (canEndGame()) {
		std::cout << "End of game" << std::endl;
	} else {
		playerList->setNextTurn();
		game->getPots()->clear();
		game->setCurrentState(game->getStateList()->getPreflop());
		game->play();
	}
}
