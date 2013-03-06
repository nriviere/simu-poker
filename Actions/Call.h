/*
 * Call.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef CALL_H_
#define CALL_H_

#include "Action.h"

class Call: public Action {
public:
	Call(Player *player):Action(player){}
	virtual ~Call();
	virtual void execute();
};

#endif /* CALL_H_ */
