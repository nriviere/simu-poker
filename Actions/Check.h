/*
 * Check.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef CHECK_H_
#define CHECK_H_

#include "Action.h"

class Check: public Action {
public:
	Check(Player *player):Action(player){}
	virtual ~Check();
	virtual void execute();
};

#endif /* CHECK_H_ */
