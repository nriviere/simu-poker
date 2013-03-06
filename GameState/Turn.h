/*
 * Turn.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef TURN_H_
#define TURN_H_

#include "GameState.h"

class Turn: public GameState {
public:
	Turn(Game*game):GameState(game){};
	virtual void setNextState();
	virtual void play();
	virtual ~Turn();
};

#endif /* TURN_H_ */
