/*
 * Preflop.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef PREFLOP_H_
#define PREFLOP_H_

#include "GameState.h"

class Preflop: public GameState {
public:
	Preflop(Game *game):GameState(game){};
	virtual void setNextState();
	virtual void play();
	virtual ~Preflop();
};

#endif /* PREFLOP_H_ */
