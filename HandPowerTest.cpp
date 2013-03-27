/*
 * HandPowerTest.cpp
 *
 *  Created on: 21 mars 2013
 *      Author: joffray
 */

#include "HandPowerTest.h"

HandPowerTest::HandPowerTest() { }

HandPowerTest::~HandPowerTest() { }

int HandPowerTest::testPower(vector<Card*>& cards, int playerCount, int handCount){

  int winCount = 0;
	int n = cards.size();
	Deck d;

	cout << "Test hand : ";
	for(int i=0; i<n; i++){
		cout << cards[i]->getId() << " ";
	}
	cout << " with "<< playerCount << "players  ----> ";


	for(int k=0; k<handCount;k++){
		d.shuffle();

		HandPower2 testHand;
		HandPower2 handsPow[playerCount];

        for(int i=0; i<n;i++){
            d.putOnTop( *cards[i]);
            testHand.addCard(d.pick());
        }

		for(int i=0; i<playerCount;i++){
			handsPow[i].addCard(d.pick());
			handsPow[i].addCard(d.pick());
		}

		for(int i=2; i<n;i++){
			Card* c = testHand.getCard(i);
			for(int j=0; j<playerCount; j++){
				handsPow[j].addCard(c);
			}
		}

		for(int i=n;i<7;i++){
			Card* c = d.pick();
			testHand.addCard(c);
			for(int j=0; j<playerCount; j++){
				handsPow[j].addCard(c);
			}
		}

		vector<int> testPower = testHand.initPower();

		bool winner = true;
		int i = 0;
		while(winner && i<playerCount){
			vector<int> p = handsPow[i].initPower();
			winner = comparePower(testPower, p ) >= 0;
			i++;
		}

		if(winner)	winCount++;

	}

	float f = 100*(winCount/(float)handCount);

	cout << " win "<< f << "%" << endl;

	return (int)f;

}
