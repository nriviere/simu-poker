/*
 * Card.cpp
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#include "Card.h"
#include <iostream>

using namespace std;

Card::Card() {
	this->id[2] = '\0';
	// TODO Auto-generated constructor stub

}

Card::Card(char number, char color, unsigned int order) {
	this->id[0] = number;
	this->id[1] = color;
	this->id[2] = '\0';
	this->order = order;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

const char *Card::getId() const {
	return id;
}

void Card::setId(char number, char color) {
	id[0] = number;
	id[1] = color;
}

void Card::print(){
	std::cout << id[0] << id[1] << endl;
}

