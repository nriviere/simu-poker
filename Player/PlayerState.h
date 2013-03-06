/*
 * PlayerState.h
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#ifndef PLAYERSTATE_H_
#define PLAYERSTATE_H_

class Player;

class PlayerState {
public:
	PlayerState(Player *player);
	virtual ~PlayerState();
	virtual void play() = 0;
	virtual bool canEndTurn();
protected:
	Player *player;
};

#endif /* PLAYERSTATE_H_ */
