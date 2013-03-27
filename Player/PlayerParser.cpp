/*
 * PlayerParser.cpp
 *
 *  Created on: 27 mars 2013
 *      Author: viande
 */

#include "PlayerParser.h"
#include "tinyxml.h"
#include <iostream>
#include <cstring>

using namespace std;

PlayerParser::PlayerParser() {
	// TODO Auto-generated constructor stub

}

Player *PlayerParser::parse(const char *fileName) {
	doc = new TiXmlDocument(fileName);
	bool loadOkay = doc->LoadFile();
	if (!loadOkay) {
		cout << "Couldn't load " << fileName << " " << doc->ErrorDesc() << endl;
		exit(-1);
	}
	TiXmlNode* node = 0;

	node = doc->FirstChildElement("Player")->FirstChildElement("Parameters");

	assert( node );
	const char *playerType = node->FirstChildElement("PlayerType")->Attribute(
			"value");
	if (strcmp(playerType, "CommandLinePlayer")==0) {
		return parseCommandLinePlayer();
	}
	return NULL;
}

Player *PlayerParser::parsePlayer() {
	int bankRoll = atoi(doc->FirstChildElement("Player")->FirstChildElement("Parameters")->FirstChildElement("BankRoll")->Attribute("value"));
	return new Player(bankRoll);
}

Player *PlayerParser::parseCommandLinePlayer() {
	int bankRoll = atoi(doc->FirstChildElement("Player")->FirstChildElement("Parameters")->FirstChildElement("BankRoll")->Attribute("value"));
	return new CommandLinePlayer(bankRoll);
}

PlayerParser::~PlayerParser() {
	delete doc;
	// TODO Auto-generated destructor stub
}
