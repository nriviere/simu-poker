/*
 * Pot.h
 *
 *  Created on: 21 mars 2013
 *      Author: viande
 */

#ifndef POT_H_
#define POT_H_

#include "Player.h"
#include <list>

class Pot {
public:
	Pot();
	Pot(int amount);
	virtual ~Pot();
	int updateAmount(int amount);
	int getAmount(){return amount;};
	std::list<Player*> *getRegisteredPlayers();
	void registerPlayer(Player *player);
private:
	std::list<Player*> registeredPlayers;
	int amount;
};

#endif /* POT_H_ */
