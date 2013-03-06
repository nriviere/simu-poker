/*
 * FoldState.h
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#ifndef FOLDSTATE_H_
#define FOLDSTATE_H_

#include "PlayerState.h"

class FoldState: public PlayerState {
public:
	FoldState(Player *player) :PlayerState(player){}
	virtual ~FoldState();
	virtual void play();
	virtual bool canEndTurn(){return true;};
};

#endif /* FOLDSTATE_H_ */
