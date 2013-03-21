/*
 * HandPower2.cpp
 *
 *  Created on: 20 mars 2013
 *      Author: joffray
 */

#include "HandPower2.h"
#include "Game.h"

typedef std::vector<Card*> c_vect;

HandPower2::HandPower2() { player = NULL; }

HandPower2::HandPower2(Player* p) { player = p; }

HandPower2::~HandPower2() { }

void HandPower2::setPlayer(Player* p){ player = p; }


void HandPower2::initHand(){
  hand.clear();
	hand.push_back(player->getHand(0));
	hand.push_back(player->getHand(1));

	Game *g = player->getGame();
	Card** onTable = g->getCardsOnTable();
	for(int i=0;i<g->getCardsOnTableCount();i++){
		hand.push_back(onTable[i]);
	}

}

void HandPower2::initOccurence(int occ[][2]) const {

	int n = hand.size();

	for(int i=0; i<n; i++){
		occ[i][0] = 1;
		occ[i][1] = hand[i]->getPower();
	}

	for(int i=0; i<n ; i++){
		//on regroupe ensuite les cartes ayant la meme valeur
		for(int j=i+1;j<n;j++){
			if(occ[j][0]>0 && occ[i][1]==occ[j][1]){
				occ[i][0]++;
				occ[j][0] = occ[j][1] = -1;
			}
		}
	}

	for(int i=0; i<n; i++){
		//TODO optimiser tri
		//puis on trie le tableau en fonction du nombre d'occurence et de la valeur des cartes
		for(int j=0;j<n-1;j++){
			if( (occ[j][0]<occ[j+1][0]) || (occ[j][0]==occ[j+1][0] && occ[j][1]<occ[j+1][1]) ){
				int tmp[2]  = { occ[j][0], occ[j][1] };
				occ[j][0] = occ[j+1][0];
				occ[j][1] = occ[j+1][1];
				occ[j+1][0]=tmp[0];
				occ[j+1][1]=tmp[1];
			}
		}
	}

}

void HandPower2::sortHand(c_vect* hand){
	int n=hand->size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int c1 = hand->at(i)->getPower();
			int c2 = hand->at(j)->getPower();
			if(c2>c1){
				Card* tmp = hand->at(i);
				hand->at(i) = hand->at(j);
				hand->at(j) = tmp;
			}
		}
	}

}


void HandPower2::highCard(int occ[][2],std::vector<int>* p) {
	int i=0;
	p->push_back(HCARD);
	while(i<5 && occ[i][1]>0){
		p->push_back(occ[i][1]);
		i++;
	}
}

bool HandPower2::isSinglePair(int occ[][2],std::vector<int>* p)  {
	bool ret = 0;

	if(occ[0][0]==2){
		p->push_back(PAIR);
		p->push_back(occ[0][1]);
		int i=1;
		while(i<4 && occ[i][0]>0){
			p->push_back(occ[i][1]);
			i++;
		}
		ret = 1;
	}

	return ret;
}

bool HandPower2::isTwoPairs(int occ[][2], std::vector<int>* p)  {
	int ret = 0;
	if(occ[0][0]==2 && occ[1][0]==2){
		p->push_back(DBPAIR);
		p->push_back(occ[0][1]);
		p->push_back(occ[1][1]);
		p->push_back(occ[2][1]);
		ret = 1;
	}
	return ret;
}

bool HandPower2::isTrips(int occ[][2], std::vector<int>* p)  {
	int ret = 0;
	if(occ[0][0]==3){
		p->push_back(TRIPS);
		p->push_back(occ[0][1]);
		p->push_back(occ[1][1]);
		p->push_back(occ[2][1]);
		ret = 1;
	}
	return ret;
}

bool HandPower2::isStraight(const c_vect& hand, std::vector<int>* p) {
	int ret = 0;
	int n = hand.size();
	if(n>4){
		int i=0;
		int n_consec = 1;
		int curHigh = 0;
		while(n_consec<5 && i+1<n ) {
			if(hand[i]->getPower()==hand[i+1]->getPower()+1){
				if(n_consec==1) curHigh=hand[i]->getPower();
				n_consec++;
			}
			else if(hand[i]->getPower()!=hand[i+1]->getPower()){
				n_consec = 1;
				curHigh = 0;
			}
			i++;
		}
		if(n_consec>=5) {
			p->push_back(STRAIGHT);
			p->push_back(curHigh);
			ret = 1;
		}
	}
	return ret;
}

bool HandPower2::isFullHouse(int occ[][2], std::vector<int>* p) {
	int ret = 0;
	if(hand.size()>4){
		if(occ[0][0]==3 && occ[1][0]==2){
			ret = 1;
			p->push_back(FULLH);
			p->push_back(occ[0][1]);
			p->push_back(occ[1][1]);
		}
	}
	return ret;
}

bool HandPower2::isQuads(int occ[][2], std::vector<int>* p) {
	int ret = 0;
	if(hand.size()>3 && occ[0][0]==4){
		p->push_back(QUADS);
		p->push_back(occ[0][1]);
		p->push_back(occ[1][1]);
		ret = 1;
	}
	return ret;
}

int HandPower2::isStraightOrFlush(int occ[][2], std::vector<int>* p) {
	int ret = 0;
	int n=hand.size();
	if(n>4){
		sortHand(&hand);
		ret = isStraight(hand,p);

		c_vect colors[CARD_COLOR_COUNT];
		for(int i=0;i<n;i++){
			int c = hand[i]->getIntColor();
			colors[c].push_back(hand[i]);
		}

		unsigned int i=0;
		int straightHigh;
		bool test = false;
		while(i<CARD_COLOR_COUNT && !test){
			if(colors[i].size()>4){
				test = true;
				p->clear();
				//HandPower tmp(d[i]);
				std::vector<int> tmp_vect;
				if(isStraight(colors[i], &tmp_vect)){
					straightHigh = tmp_vect[1];
					//cout << " straight flush found high : " << straightHigh << endl;
					p->push_back(SFLUSH);
					p->push_back(straightHigh);
					p->push_back(i);
					ret = 3;
				}
				else{
					//cout << "flush found high " << tmp_v[1] << endl;
					p->push_back(FLUSH);
					p->push_back(colors[i][0]->getPower());
					p->push_back(i);
					ret = 2;
				}
			}
			i++;
		}
	}

	return ret;
}

std::vector<int> HandPower2::initPower(){

	int occ[7][2];
	initOccurence(occ);

    int testStrFlush = isStraightOrFlush(occ, &hForce);

	if(testStrFlush==3){
		//cout << "straight flush detected " << endl;
	}
    else if(isQuads(occ,&hForce)){
		//cout << "quad " << endl;
	}
    else if(isFullHouse(occ,&hForce)){
		//cout << "full " <<endl;
	}
	else if(testStrFlush==2){
		//cout << "flush " << endl;
	}
	else if(testStrFlush==1){
		//cout << "straight " << endl;
	}
    else if(isTrips(occ,&hForce)){
		//cout << "three of a kind detected " << endl;
	}
    else if(isTwoPairs(occ,&hForce)){
		//cout << "Two Pairs " << endl;
	}
    else if(isSinglePair(occ,&hForce)){
		//cout << "Single pair " << endl;
	}
	else{
        highCard(occ,&hForce);
		//cout << "high card " << endl;
	}

    return hForce;
}


int comparePower(std::vector<int>& pow1, std::vector<int>& pow2){
	int ret = -2;
	int i = -1;

	int n1 = pow1.size();
	int n2 = pow2.size();

	do	i++;
	while(pow1[i]==pow2[i] && i<n1 && i<n2);

	if(pow1[i]>pow2[i]) 		ret =  1;
	else if(pow1[i]<pow2[i]) 	ret = -1;
	else if(i>=n1)				ret =  0;

	return ret;
}
