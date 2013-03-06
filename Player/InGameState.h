/*
 * InGameState.h
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#ifndef INGAMESTATE_H_
#define INGAMESTATE_H_

#include "PlayerState.h"
class Player;
class InGameState: public PlayerState {
public:
	InGameState(Player *player) :PlayerState(player){}
	virtual ~InGameState();
	virtual void play();
	virtual bool canEndTurn();
};

#endif /* INGAMESTATE_H_ */
