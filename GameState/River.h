/*
 * River.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef RIVER_H_
#define RIVER_H_

#include "GameState.h"

class River: public GameState {
public:
	River(Game *game):GameState(game){};
	virtual void setNextState();
	virtual void play();
	virtual void endOfTurn();
	virtual ~River();
};

#endif /* RIVER_H_ */
