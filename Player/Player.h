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

#include "PlayerStatistics.h"

class Game;

class Player {
public:
	Player();
	Player(const Player &player);
	Player(int bankRoll);
	virtual Player *clone() const;
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

	int getBankRoll() const
	{
		return bankRoll;
	}
	void setCurrentState(PlayerState *state) {
		this->currentState = state;
	}

	PlayerStatistics* getStatistics() const{
		return statistics;
	}
	
	Card* getHand(int i) { return hand[i]; }

protected:
	int id;
	Game *game;
	int bankRoll;
	int currentBet;
	Card *hand[2];
	PlayerState *currentState;
	PlayerStatistics *statistics;
};

#endif /* PLAYER_H_ */
