/*
 * HandPower2.h
 *
 *  Created on: 20 mars 2013
 *      Author: joffray
 */

#ifndef HANDPOWER2_H_
#define HANDPOWER2_H_

#define HCARD 1
#define PAIR 2
#define DBPAIR 3
#define TRIPS 4
#define STRAIGHT 5
#define FLUSH 6
#define FULLH 7
#define QUADS 8
#define SFLUSH 9

#include <iostream>
#include <vector>

#include "Card.h"
#include "Player.h"




class HandPower2 {

private:
  Player* player;
	std::vector<Card*> hand;
	std::vector<int> hForce;

public:
	HandPower2();
	HandPower2(Player* p);
	virtual ~HandPower2();

	void setPlayer(Player* p);

	void initHand();
	void initOccurence(int occ[][2]) const;


	void sortHand(std::vector<Card*>* v);


	void highCard(int occ[][2], std::vector<int>* );
	bool isSinglePair(int occ[][2],std::vector<int>* );
	bool isTwoPairs(int occ[][2], std::vector<int>* );
	bool isTrips(int occ[][2], std::vector<int>* );
	bool isStraight(const std::vector<Card*>& hand,std::vector<int>*);		//detecte une suite dans un main deja triee
	bool isFullHouse(int occ[][2], std::vector<int>* );
	bool isQuads(int occ[][2], std::vector<int>* );
	int isStraightOrFlush(int occ[][2], std::vector<int>* );

	void addCard(Card* c) { hand.push_back(c); }
	Card* getCard(int i) { return hand[i]; }

	std::vector<int> initPower();

};

int comparePower(std::vector<int>& pow1, std::vector<int>& pow2);


#endif /* HANDPOWER2_H_ */
