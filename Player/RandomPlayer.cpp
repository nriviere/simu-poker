/*
 * RandomPlayer.cpp
 *
 *  Created on: 21 mars 2013
 *      Author: joffray
 */

#include "RandomPlayer.h"
#include "Game.h"

#include <stdlib.h>

RandomPlayer::RandomPlayer(int bankRoll) : Player(bankRoll){

}

void RandomPlayer::iPlay(){
  int d = rand()%10;
	cout << "d="<<d<<"\t";
	cout << "Random player " << id <<" ("<<bankRoll<<") : ";
	if(game->isCheckable()){
		//check or bet

		if(d<6){
			cout <<"check" << endl;
			check();
		}
		else{
			int nBb = 1+(rand()%4);
			int blind = game->getBigBlindAmount();
			cout <<"bet " << nBb*blind << endl;
			raise(nBb*blind);
		}

	}
	else{
		//fold, call or raise
		if(0){
			cout <<"fold" << endl;
			fold();
		}
		else if(d<7){
			cout <<"call" << endl;
			call();
		}
		else {
			int nBb = 1+(rand()%4);
			int blind = game->getBigBlindAmount();
			cout << "raise to " << nBb*blind << endl;
			raise(nBb*blind);
		}

	}

}

Player *RandomPlayer::clone()  const
{
	return new RandomPlayer(*this);
}
