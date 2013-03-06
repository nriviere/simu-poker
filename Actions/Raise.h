/*
 * Raise.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef RAISE_H_
#define RAISE_H_

#include "Action.h"

class Raise: public Action {
public:
	Raise(Player *player, int amount) :
		Action(player) {
		this->amount = amount;
	}
	virtual ~Raise();
	virtual void execute();
private:
	int amount;
};

#endif /* RAISE_H_ */
