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

Deck::Deck(int cardCount) {
	this->cardCount = cardCount;
	cards = new Card*[cardCount];
	top = 0;
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
	srand(time(0));
	for (int i = 0; i < cardCount; i++) {
		out = rand() % cardCount;
		in = rand() % cardCount;
		tmp = cards[in];
		cards[in] = cards[out];
		cards[out] = tmp;
	}
	top = 0;
}

void Deck::init() {
	int cardNumber = 0;
	for (unsigned int i = 0; i < CARD_NUMBER_COUNT; i++) {
		for (unsigned int j = 0; j < CARD_COLOR_COUNT; j++) {
				cards[cardNumber++] = new Card(CARD_NUMBERS[i], CARD_COLORS[j],cardNumber);
		}
	}
}

void Deck::printOrder() {
	for (int i = 0; i < cardCount; i++) {
		Card *c = pick();

		std::cout << c->getId() << std::endl;
	}
}
