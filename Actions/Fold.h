/*
 * Call.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef FOLD_H_
#define FOLD_H_

#include "Action.h"

class Fold: public Action {
public:
	Fold(Player *player):Action(player){}
	virtual ~Fold();
	virtual void execute();
};

#endif /* CALL_H_ */
