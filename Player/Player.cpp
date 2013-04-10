/*
 * Player.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Player.h"
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include "HandPower.h"

using namespace std;

Player::Player() {
	bankRoll = 0;
}

Player::Player(int bankRoll) {
	this->bankRoll = bankRoll;
	currentBet = 0;
	id = 0;
	statistics = new PlayerStatistics();
}

Player::Player(const Player &player) {
	this->bankRoll = player.bankRoll;
	currentBet = player.currentBet;
	hand[0] = player.hand[0];
	hand[1] = player.hand[1];
	statistics = new PlayerStatistics(*player.statistics);
}

Player *Player::clone() const {
	exit(-1);
	return new Player(*this);
}

Player::~Player() {
	delete statistics;
}

void Player::setHand(Card *card1, Card *card2) {
	this->hand[0] = card1;
	this->hand[1] = card2;
	statistics->incrementStat(HAND);
}

void Player::play() {
	iPlay();
}

int Player::modifyBankRoll(int amount) {
	int left = bankRoll += amount;
	if (left < 0) {
		bankRoll = 0;
	}
	return left;

}


void Player::setId(const int id) {
	this->id = id;
	statistics->setPlayerId(id);
}

int Player::getId() {
	return id;
}

void Player::paySmallBlind() {
	int left = modifyBankRoll(-game->getSmallBlindAmount());
	if (left > 0)
		left = 0;
	currentBet = game->getSmallBlindAmount() - left;
}

void Player::payBigBlind() {
	int left = modifyBankRoll(-game->getBigBlindAmount());
	if (left > 0)
		left = 0;
	currentBet = game->getBigBlindAmount() - left;
}

bool Player::canEndState() {
	return getCurrentBet() == game->getCurrentBet() || bankRoll == 0;
}

void Player::iPlay() {
	cout << "Player : joueur" << id << " joue" << endl;
}

void Player::raise(int amount) {
	game->raise(this, amount);
}

void Player::check() {
	game->check(this);
}

void Player::call() {
	game->call(this);
}

void Player::fold() {
	game->fold(this);
}

//TODO : bouger cette fonction dans handPower ?
char *Player::getHandPower() {
	//on trie les cartes par ordre décroissant
	Card *cards[7] = { hand[0], hand[1], game->getCardsOnTable()[0],
			game->getCardsOnTable()[1], game->getCardsOnTable()[2],
			game->getCardsOnTable()[3], game->getCardsOnTable()[4] };
	Card *c;
	bool p = true;
	while (p) {
		p = false;
		for (int i = 0; i < 6; i++) {
			if (cards[i]->getOrder() < cards[i + 1]->getOrder()) {
				c = cards[i];
				cards[i] = cards[i + 1];
				cards[i + 1] = c;
				p = true;
			}
		}
	}
	//On génère les 21 5-cartes ordonnées parmi 7 cartes;
	char **finalHands = new char*[21];
	int i[5] = { 0, 0, 0, 0, 0 };
	int pos = 0;
	for (i[0] = 0; i[0] < 6; i[0]++) {
		for (i[1] = i[0] + 1; i[1] < 7; i[1]++) {
			for (i[2] = i[1] + 1; i[2] < 7; i[2]++) {
				for (i[3] = i[2] + 1; i[3] < 7; i[3]++) {
					for (i[4] = i[3] + 1; i[4] < 7; i[4]++) {
						finalHands[pos] = new char[11];
						for (int it = 0; it < 5; it++) {
							finalHands[pos][it * 2] = cards[i[it]]->getId()[0];
							//std::cout << cards[i[it]]->getId()[0] << std::endl;
							finalHands[pos][it * 2 + 1] =
									cards[i[it]]->getId()[1];
							//std::cout << cards[i[it]]->getId()[1] << std::endl;
						}
						finalHands[pos][10] = '\0';
						pos++;
					}
				}
			}
		}
	}

	char *maxHand;
	char *handPower;
	//on choisi la max
	maxHand = calculForceSymbolique(finalHands[0]);
	for (int i = 1; i < 21; i++) {
		handPower = calculForceSymbolique(finalHands[i]);
		//cout << handPower << endl;
		//power = ;
		if (compare(handPower, maxHand) > 0) {
			delete[] maxHand;
			maxHand = handPower;
		} else {
			delete[] handPower;
		}
	}
	delete[] finalHands;
	return maxHand;
}

