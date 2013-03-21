#include "Game.h"
#include "Deck.h"
#include "Player.h"
#include "CommandLinePlayer.h"

#include "HandPowerTest.h"

#include <list>
#include <iostream>
using namespace std;

int main() {
	/*Card **cards = new Card*[52];
	 int cardNumber = 0;
	 for (unsigned int i = 0; i < CARD_NUMBER_COUNT; i++) {
	 for (unsigned int j = 0; j < CARD_COLOR_COUNT; j++) {
	 cards[cardNumber++] =  new Card(CARD_NUMBERS[i], CARD_COLORS[j]);
	 }
	 }

	 char **hands = new char*[133784560];
	 int test = 0;
	 for (int i = 51; i >= 0; i--) {
	 for (int j = i - 1; j >= 0; j--) {
	 for (int k = j - 1; k >= 0; k--) {
	 for (int l = k - 1; l >= 0; l--) {
	 for (int m = l - 1; m >= 0; m--) {
	 for (int n = m - 1; n >= 0; n--) {
	 for (int o = n - 1; o >= 0; o--) {
	 hands[test] = new char[14];
	 hands[test][0] = cards[i]->getId()[0];
	 hands[test][1] = cards[i]->getId()[1];
	 hands[test][2] = cards[j]->getId()[0];
	 hands[test][3] = cards[j]->getId()[1];
	 hands[test][4] = cards[k]->getId()[0];
	 hands[test][5] = cards[k]->getId()[1];
	 hands[test][6] = cards[l]->getId()[0];
	 hands[test][7] = cards[l]->getId()[1];
	 hands[test][8] = cards[m]->getId()[0];
	 hands[test][9] = cards[m]->getId()[1];
	 hands[test][10] = cards[n]->getId()[0];
	 hands[test][11] = cards[n]->getId()[1];
	 hands[test][12] = cards[o]->getId()[0];
	 hands[test][13] = cards[o]->getId()[1];
	 test++;
	 }
	 }
	 }
	 }
	 }
	 }
	 }*/
	int test = 0;
	for (int i = 6; i >= 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			for (int k = j - 1; k >= 0; k--) {
				for (int l = k - 1; l >= 0; l--) {
					for (int m = l - 1; m >= 0; m--) {
						test++;
					}
				}
			}
		}
	}
	cout << test << endl;
	/*	for (int i = 0; i < 133784560; i++) {
	 cout << hands[i][0] << hands[i][1] << " " << hands[i][2] << hands[i][3] << " " << hands[i][4] << " " << hands[i][5] << hands[i][6] <<endl;
	 delete [] hands[i];
	 }
	 delete [] hands;*/
	Deck deck;
	deck.shuffle();
	deck.printOrder();

	int bankRoll = 1000;
	int smallBlind = 5;
	int playerCount = 5;
	Player **players = new Player*[playerCount];
	for (int i = 0; i < playerCount; i++) {
		players[i] = new CommandLinePlayer(bankRoll);
	}
	Game game(players, playerCount, smallBlind);
	game.play();
	for (int i = 0; i < playerCount; i++) {
		delete players[i];
	}
	delete[] players;
	
	
	/* Exemple d'affichage de la proba de gain avec As Kh*/
	Deck d2;
	int maxPlayerTestCount = 6;
	HandPowerTest t;
	vector<Card*> cards;
	cards.push_back(d2.getCard("As"));
	cards.push_back(d2.getCard("Kh"));
//	cards.push_back(d2.getCard("4d"));
//	cards.push_back(d2.getCard("2c"));
//	cards.push_back(d2.getCard("5d"));
//	cards.push_back(d2.getCard("8h"));

	for(int i=1; i<maxPlayerTestCount; i++){
		t.testPower(cards,i,100000);
	}
	
	
	return 0;
}
