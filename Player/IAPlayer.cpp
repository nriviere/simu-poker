#include <iostream>
#include <fstream>
#include <string.h>

#include "IAPlayer.h"
#include "Game.h"
#include "PlayerList.h"

using namespace std;

IAPlayer::IAPlayer(int bankRoll, double tightness, double aggressiveness):Player(bankRoll) {

	this->tightness = tightness;
	this->aggressiveness = aggressiveness;
	this->handC = new char[4];
	this->bluff = 0;
}

IAPlayer::IAPlayer(const IAPlayer &player):Player(player) {
	this->aggressiveness = player.aggressiveness;
	this->tightness = player.tightness;
	this->handC = new char[4];
	this->bluff = 0;

}
IAPlayer::~IAPlayer() {
	delete[] handC;
}

void IAPlayer::iPlay(){
	cout << "############################################################################################" << endl;
	cout << "PLAYER : " << this->id << endl;
	cout << "Cards on table :";
	for(int i = 0; i < game->getCardsOnTableCount(); i++)
	{
		cout << " " << game->getCardsOnTable()[i]->getId();
	}
	cout << endl;
	cout << "Your hand : " << hand[0]->getId() << " " << hand[1]->getId() << endl;
	cout << endl;
	cout << "Current global bet : " << this->getGame()->getCurrentBet() << endl;
	cout << "Your bet : " << this->currentBet << endl;

	//cout << "Current pot : " << this->getGame()->getPot() << endl;
	cout << "Your bankroll  : " << this->bankRoll << endl;

	int playerInGame = this->game->getPlayerList()->getPlayersInGameCount();
	int gain = this->game->getCurrentPot()->getAmount() - this->getCurrentBet();

	if(game->getState() == PFLOP){
		cardToChar();
		gain = this->game->getBigBlindAmount();
	}

	double proba = getProba(handC,playerInGame);

	if(expectedValues(proba, gain)){
		if(this->game->isCheckable()){
			raise(this->aggressiveness * this->game->getBigBlindAmount());
			cout << "raise : "<< this->aggressiveness * this->game->getBigBlindAmount() <<endl;
		}else{
			call();
			cout << "call" <<endl;
		}

	}else if(this->game->isCheckable()){
		check();
		cout << "check" <<endl;
	}else{
		fold();
		cout << "fold" <<endl;
	}
}

//Esperance de gain : l'IA joue si (proba% * (pot - mise)) > 1
bool IAPlayer::expectedValues(double proba, int gain){
	cout << "proba = " << proba << endl;
	cout << "gain = " << gain << endl;
	cout << "EV = " << (proba/100.0) * gain  << endl;
	if( ((proba/100.0) * gain ) > 1){
		return true;
	}else{
		return false;
	}
}

//On transforme la main en char pour chercher les probas dans le fichier .txt
void IAPlayer::cardToChar(){

	bool sameColor = (this->getHand(0)->getId()[1] == this->getHand(1)->getId()[1]);

	handC[0] = this->getHand(0)->getId()[0];
	if(handC[0] == '1') { handC[0] = 'T';}

	handC[1] = this->getHand(1)->getId()[0];
	if(handC[1] == '1') { handC[1] = 'T';}

	if(sameColor){
		handC[2] = '*';
		handC[3] = '\0';
	}else{
		handC[2] = '\0';
	}
}

double IAPlayer::getProba(char *hand, int nbPlayer){
	//Ouverture du fichier
	const char *filename = "probas_preflops.txt";
	ifstream probaFile;
	probaFile.open(filename);

	//On crée un deuxieme tableau où les cartes sont inversées car les cartes n'ont pas d'ordre dans le fichier
	int length = strlen(hand);
	char inverseHand[length+1];
	inverseHand[0] = hand[1];
	inverseHand[1] = hand[0];
	if(length == 3){
		inverseHand[2] = '*';
	}
	inverseHand[length] = '\0';

	string handproba, dump;
	double proba;

	if(probaFile.is_open()){
		bool found = false;

		while(!found){
			if(!probaFile.eof()){ //tant que la fin du fichier n'est pas atteint.
				probaFile >> handproba;
				if(strcmp(hand,handproba.c_str()) == 0 || strcmp(inverseHand,handproba.c_str()) == 0){ // la main est trouvée
					found = true;
				}else{
					getline(probaFile,dump); // ce n'est pas la bonne main, on jette la ligne.
				}
			}else{ //la fin du fichier est atteint sans avoir trouvé de main identique : erreur, on s'arrete.
				cerr << hand << " : main introuvable !" << endl;
				return -1;
			}
		}

		if(found){
			if(nbPlayer < 1){
				cerr << "le nombre d'adversaire ne peut être nul : calcul des probas pour 1 adversaire..." << endl;
				nbPlayer = 1;
			}else if (nbPlayer > 9){
				cerr << "le nombre d'adversaire ne peut être supérieur a 9 : calcul des probas pour 9 adversaires..." << endl;
				nbPlayer = 9;
			}
			for(int i = 0; i < nbPlayer-1; i++){
				probaFile >> dump;
			}
			probaFile >> proba;
		}
	}

	probaFile.close();

	return proba;
}

Player *IAPlayer::clone()  const
{
	return new IAPlayer(*this);
}
