/*
 * OutGameState.h
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#ifndef OUTGAMESTATE_H_
#define OUTGAMESTATE_H_

#include "PlayerState.h"

class OutGameState: public PlayerState {
public:
	OutGameState(Player *player) :PlayerState(player){}
	virtual ~OutGameState();
	virtual void play();
	virtual bool canEndTurn(){return true;};
};

#endif /* OUTGAMESTATE_H_ */
