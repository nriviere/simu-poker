/*
 * Deck.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Deck.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

Deck::Deck(int cardCount) {
	this->cardCount = cardCount;
	cards = new Card*[cardCount];
	srand(time(0));
	init();
	shuffle();
}

Deck::~Deck() {
	for (int i = 0; i < cardCount; i++) {
		delete cards[i];
	}
	delete[] cards;
}

Card *Deck::pick() {
	if (top < cardCount) {
		return cards[top++];
	}
	return NULL;
}

void Deck::shuffle() {
	int out, in;
	Card *tmp;
	for (int i = 0; i < cardCount; i++) {
		out = rand() % cardCount;
		in = rand() % cardCount;
		tmp = cards[in];
		cards[in] = cards[out];
		cards[out] = tmp;
	}
	//printOrder();
	//cout << endl;
	top = 0;
}

void Deck::init() {
	int cardNumber = 0;

	for (unsigned int i = 0; i < CARD_NUMBER_COUNT; i++) {
		for (unsigned int j = 0; j < CARD_COLOR_COUNT; j++) {

			cards[cardNumber++] = new Card(CARD_NUMBERS[i], CARD_COLORS[j],
					cardNumber);
		}
	}
	top = 0;
}

void Deck::printOrder() {
	for (int i = 0; i < cardCount; i++) {
		std::cout << cards[i]->getId() << std::endl;

	}
}

Card* Deck::getCard(const char* id, int *pos) {
	int t = -1;
	bool found = false;
	do {
		t++;
		found = cards[t]->getId()[0] == id[0];
		found = found && cards[t]->getId()[1] == id[1];
	} while (!found && t < 52);

	if (found && pos) {
		*pos = t;
	}

	return found ? cards[t] : 0;
}

bool Deck::putOnTop(const Card& c) {
	bool ret = false;
	int p = -1;
	Card* dc = getCard(c.getId(), &p);
	if (dc) {
		cards[p] = cards[top];
		cards[top] = dc;
		ret = true;
	}
	return ret;
}

