/*
 * Check.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Check.h"
#include "Game.h"

Check::~Check() {
	// TODO Auto-generated destructor stub
}

void Check::execute()
{
	player->getStatistics()->incrementStat(CHECK,game->getState());
}


