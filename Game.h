/*
 * Game.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef GAME_H_
#define GAME_H_
#include <list>
#include "GameState.h"
#include "GameStateList.h"
#include "Player.h"
#include "Action.h"
#include "Deck.h"

class PlayerList;
class Player;
class Action;


class Game {
public:
	Game(Player **players, int playerCount, unsigned int smallBlindAmount);
	virtual ~Game();
	void play();
	void addAction(Action *action);
	void call(Player *player);
	void raise(Player *player, int amount);
	bool isCheckable();
	void check(Player *player);
	void fold(Player *player);
	int updatePot();
	int addToPot(int amount);
	void endOfTurn();
	int getCurrentBet() const {
		return currentBet;
	}

	int getPot() const {
		return pot;
	}

	void setCurrentBet(int currentBet) {
		this->currentBet = currentBet;
	}

	void setPot(int pot) {
		this->pot = pot;
	}

	int getCurrentPlayerId() {
		return currentPlayerId++;
	}

	void setCurrentPlayerId(int currentPlayerId) {
		this->currentPlayerId = currentPlayerId;
	}

	int getBigBlindAmount() const {
		return bigBlindAmount;
	}

	void setBigBlindAmount(int bigBlindAmount) {
		this->bigBlindAmount = bigBlindAmount;
	}

	int getSmallBlindAmount() const {
		return smallBlindAmount;
	}

	void setSmallBlindAmount(int smallBlindAmount) {
		this->smallBlindAmount = smallBlindAmount;
	}

	PlayerList *getPlayerList() const {
		return playerList;
	}

	void setPlayerList(PlayerList *playerList) {
		this->playerList = playerList;
	}

	std::list<Action*> getActions() const {
		return actions;
	}

	GameState *getCurrentState() const {
		return currentState;
	}

	GameStateList *getStateList() const {
		return stateList;
	}

	int getTurn() const {
		return turn;
	}

	void setActions(std::list<Action*> actions) {
		this->actions = actions;
	}

	void setCurrentState(GameState *currentState) {
		this->currentState = currentState;
	}

	void setStateList(GameStateList *stateList) {
		this->stateList = stateList;
	}

	void setTurn(int turn) {
		this->turn = turn;
	}

	void setCardsOnTableCount(int cardsOnTableCount) {
		this->cardsOnTableCount = cardsOnTableCount;
	}

	int getCardsOnTableCount() const {
		return cardsOnTableCount;
	}

	Card **getCardsOnTable(){
		return cardsOnTable;
	}

	Deck *getDeck(){
		return deck;
	}

private:
	PlayerList *playerList;
	std::list<Action*> actions;
	int turn;
	int smallBlindAmount, bigBlindAmount;
	int pot;
	int currentBet;
	int currentPlayerId;

	Card *cardsOnTable[5];
	Deck *deck;
	int cardsOnTableCount;

	GameStateList *stateList;
	GameState *currentState;
};

#endif /* GAME_H_ */
