/*
 * GameState.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class Game;

class GameState {
public:
	GameState(Game *game);
	virtual ~GameState();
	virtual void play() = 0;
	virtual void setNextState() = 0;
	void playerPlayed();
	bool canEndState();
	bool canEndGame();
	void endOfState();
	void endOfTurn();
protected:
	int playerCount;
	int playersToPlay;
	int currentPlayer;
	int maxBetTurns;
	bool everyonePlayed;
	Game *game;
};

#endif /* GAMESTATE_H_ */
