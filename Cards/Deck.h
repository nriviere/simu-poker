/*
 * Deck.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef DECK_H_
#define DECK_H_
#include "Card.h"
#include <list>

class Deck {
public:
	Deck(int cardCount = 52);
	virtual ~Deck();
	void init();
	void shuffle();
	void printOrder();
	Card *pick();
	
	Card* getCard(const char* id, int* pos = NULL);
	//recherche une carte dans le paquet el la retourne en 
	//stockent sa position dans pos (utilisé dans HandPowerTest)
	
	bool putOnTop(const Card& c);
	//recherche c dans le paquet et la place tout en haut
	//(utilisé dans handPowerTest)
	
private:

	Card **cards;
	int cardCount;
	int top;

};

#endif /* DECK_H_ */
