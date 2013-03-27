#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include "CommandLinePlayer.h"
#include "GameParser.h"
#include "HandPowerTest.h"

#include <list>
#include <iostream>
using namespace std;

int main() {
	Deck deck;
	deck.shuffle();
	//deck.printOrder();

	GameParser parser;
	Game *game = parser.parse("XMLGameTypes/GameType1.xml");

	game->play();

	delete game;

	/* Exemple d'affichage de la proba de gain avec As Kh*/
	Deck d2;
	int maxPlayerTestCount = 6;
	HandPowerTest t;
	vector<Card*> cards;
	cards.push_back(d2.getCard("As"));
	cards.push_back(d2.getCard("Kh"));
	//	cards.push_back(d2.getCard("4d"));
	//	cards.push_back(d2.getCard("2c"));
	//	cards.push_back(d2.getCard("5d"));
	//	cards.push_back(d2.getCard("8h"));

	for (int i = 1; i < maxPlayerTestCount; i++) {
		t.testPower(cards, i, 100000);
	}

	return 0;
}
