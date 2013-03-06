/*
 * Flop.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef FLOP_H_
#define FLOP_H_

#include "GameState.h"

class Flop: public GameState {
public:
	Flop(Game *game) : GameState(game){};
	virtual void setNextState();
	virtual void play();
	virtual ~Flop();
};

#endif /* FLOP_H_ */
