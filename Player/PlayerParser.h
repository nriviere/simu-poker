/*
 * PlayerParser.h
 *
 *  Created on: 27 mars 2013
 *      Author: viande
 */

#ifndef PLAYERPARSER_H_
#define PLAYERPARSER_H_

#include "Player.h"
#include "CommandLinePlayer.h"
#include "tinyxml.h"

class PlayerParser {
public:
	PlayerParser();
	Player *parse(const char *fileName);
	Player *parsePlayer();
	Player *parseCommandLinePlayer();
	virtual ~PlayerParser();
protected:
	TiXmlDocument *doc;
};

#endif /* PLAYERPARSER_H_ */
