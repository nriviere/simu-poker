/*
 * HandPowerTest.h
 *
 *  Created on: 21 mars 2013
 *      Author: joffray
 */

#ifndef HANDPOWERTEST_H_
#define HANDPOWERTEST_H_

#include "HandPower2.h"
#include "Deck.h"

class HandPowerTest {
public:
  HandPowerTest();
	virtual ~HandPowerTest();

	int testPower(vector<Card*>& cards, int playerCount, int handCount);

};

#endif /* HANDPOWERTEST_H_ */
