/*
 * GameParser.h
 *
 *  Created on: 27 mars 2013
 *      Author: viande
 */

#ifndef GAMEPARSER_H_
#define GAMEPARSER_H_

#include "tinyxml.h"
#include "Game.h"
class GameParser {
public:
	GameParser();
	Game *parse(const char *filename);
	virtual ~GameParser();
protected:
	TiXmlDocument *doc;
};

#endif /* GAMEPARSER_H_ */
