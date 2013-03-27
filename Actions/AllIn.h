/*
 * AllIn.h
 *
 *  Created on: 21 mars 2013
 *      Author: viande
 */

#ifndef ALLIN_H_
#define ALLIN_H_

#include "Action.h"

class AllIn: public Action {
public:
	AllIn(Player *player,int amount):Action(player){this->amount = amount;}
	virtual void execute();
	virtual ~AllIn();
private:
	int amount;
};

#endif /* ALLIN_H_ */
