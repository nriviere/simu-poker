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
private:

	Card **cards;
	int cardCount;
	int top;

};

#endif /* DECK_H_ */
