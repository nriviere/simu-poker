/*
 * CommandLinePlayer.h
 *
 *  Created on: 12 févr. 2013
 *      Author: viande
 */

#ifndef COMMANDLINEPLAYER_H_
#define COMMANDLINEPLAYER_H_

#include "Player.h"

class CommandLinePlayer: public Player {
public:
	CommandLinePlayer(int bankRoll):Player(bankRoll){}
	CommandLinePlayer(const CommandLinePlayer &player):Player(player){};
	Player *clone() const;
	virtual ~CommandLinePlayer();
	void iPlay();
private:
	const char *name;
};

#endif /* COMMANDLINEPLAYER_H_ */
