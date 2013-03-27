/*
 * GameParser.cpp
 *
 *  Created on: 27 mars 2013
 *      Author: viande
 */

#include "GameParser.h"
#include "Game.h"
#include "PlayerParser.h"
#include "Player.h"
#include "tinyxml.h"
#include <cstring>
#include <iostream>
#include <list>

using namespace std;

GameParser::GameParser() {
	// TODO Auto-generated constructor stub

}

Game *GameParser::parse(const char *filename) {
	doc = new TiXmlDocument(filename);
	bool loadOkay = doc->LoadFile();
	if (!loadOkay) {
		cout << "Couldn't load " << filename << " " << doc->ErrorDesc() << endl;
		exit(-1);
	}
	TiXmlNode* node = 0;

	node = doc->FirstChildElement("Game");

	int smallBlindAmount = atoi(node->FirstChildElement("SmallBlindAmount")->Attribute("value"));
	node = node->FirstChildElement("Players");

	TiXmlElement* playertype = 0;

	playertype = node->FirstChildElement("Player");
	PlayerParser parser;
	list<Player *>playerList;
	list<int> playerTypeCounts;
	int playerCount = 0;

	while(playertype)
	{
		const char *fileName = playertype->Attribute("filename");
		int playerTypeCount = atoi(playertype->Attribute("count"));
		Player *p = parser.parse(fileName);
		playerList.push_back(p);
		playerTypeCounts.push_back(playerTypeCount);
		playerCount += playerTypeCount;
		playertype = playertype->NextSiblingElement();
	}

	Player **players = new Player*[playerCount];

	list<int>::iterator c = playerTypeCounts.begin();
	list<Player*>::iterator p = playerList.begin();


	int postion = 0;
	for(; p != playerList.end() && c != playerTypeCounts.end();)
	{
		for(int i = 0; i < (*c);i++)
		{
				players[postion++] = (*p)->clone();
		}
		delete (*p);
		++p;
		++c;
	}

	Game *g = new Game(players, playerCount, smallBlindAmount);
	delete []players;
	return g;
}

GameParser::~GameParser() {
	delete doc;
	// TODO Auto-generated destructor stub
}
