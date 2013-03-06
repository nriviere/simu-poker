/*
 * Player.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Card.h"
#include "PlayerState.h"
#include "PlayerStateList.h"

class Game;

class Player {
public:
	Player();
	Player(const Player &player);
	Player(int bankRoll);
	virtual ~Player();
	void play();
	virtual void iPlay();
	void setHand(Card *card1, Card *card2);
	void setId(const int id);
	int getId();
	int modifyBankRoll(int amount);
	void payBigBlind();
	void paySmallBlind();
	void check();
	void call();
	void raise(int amount);
	void fold();
	bool canEndState();
	char *getHandPower();

	void setGame(Game *game) {
		this->game = game;
	}
	Game *getGame() {
		return game;
	}
	int getCurrentBet() const {
		return this->currentBet;
	}
	void setCurrentBet(const int &currentBet) {
		this->currentBet = currentBet;
	}
	PlayerStateList *getStateList() {
		return stateList;
	}
	int getBankRoll() const
	{
		return bankRoll;
	}
	void setCurrentState(PlayerState *state) {
		this->currentState = state;
	}

protected:
	int id;
	Game *game;
	int bankRoll;
	int currentBet;
	Card *hand[2];
	PlayerStateList *stateList;
	PlayerState *currentState;
};

#endif /* PLAYER_H_ */
