/*
 * Card.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef CARD_H_
#define CARD_H_

const char CARD_NUMBERS[13] = {'2','3','4','5','6','7','8','9','1','J','Q','K','A'};
const char CARD_POWER[13] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
const unsigned int CARD_NUMBER_COUNT = 13;
const char CARD_COLORS[4] = {'d','h','c','s'};
const unsigned int CARD_COLOR_COUNT = 4;

class Card {
public:
	Card();
	Card(char number, char color,unsigned int order);
	virtual ~Card();
	const char *getId() const;
	void setId(char number, char color);
	//TODO : redefinir operateurs < >
	unsigned int getOrder(){
		return order;
	}
	void print();


private :
	unsigned int order;
	char id[3];
};

#endif /* CARD_H_ */
