#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "HandPower.h"

int isStraightFlush(char* hand) { // test de la Quinte Flush
	if (isStraight(hand) == 1 && isFlush(hand) == 1)
		return 1;
	return 0;
}

int isQuads(char* hand) { // test du Carré
	int i, cpt = 0;
	for (i = 0; i < 10; i = i + 2) {
		if (hand[i] == hand[i+2])
			cpt++;
	}
	if (cpt == 4)
		return 1;
	return 0;
}

int isFullHouse(char* hand) { // test du Full
	if ((isTrips(hand) == 1) && (isSinglePair(hand) == 1)) {
		return 1;
	}
	return 0;
}

int isFlush(char* hand) { // test de la Couleur
	if (hand[1] == hand[3] && hand[1] == hand[5] && hand[1] == hand[7]
			&& hand[1] == hand[9]) {
		return 1;
	}
	return 0;
}

int isStraight(char* hand) { // test de la Suite
	if (hand[0] == 'A' && hand[2] == 'K' && hand[4] == 'Q' && hand[6] == 'J'
			&& hand[8] == '1') {
		return 1;
	}
	if (hand[0] == 'K' && hand[2] == 'Q' && hand[4] == 'J' && hand[6] == '1'
			&& hand[8] == '9') {
		return 1;
	}
	if (hand[0] == 'Q' && hand[2] == 'J' && hand[4] == '1' && hand[6] == '9'
			&& hand[8] == '8') {
		return 1;
	}
	if (hand[0] == 'J' && hand[2] == '1' && hand[4] == '9' && hand[6] == '8'
			&& hand[8] == '7') {
		return 1;
	}
	if (hand[0] == '1' && hand[2] == '9' && hand[4] == '8' && hand[6] == '7'
			&& hand[8] == '6') {
		return 1;
	}
	if (hand[0] == '9' && hand[2] == '8' && hand[4] == '7' && hand[6] == '6'
			&& hand[8] == '5') {
		return 1;
	}
	if (hand[0] == '8' && hand[2] == '7' && hand[4] == '6' && hand[6] == '5'
			&& hand[8] == '4') {
		return 1;
	}
	if (hand[0] == '7' && hand[2] == '6' && hand[4] == '5' && hand[6] == '4'
			&& hand[8] == '3') {
		return 1;
	}
	if (hand[0] == '6' && hand[2] == '5' && hand[4] == '4' && hand[6] == '3'
			&& hand[8] == '2') {
		return 1;
	}

	/* The Wheel */
	if (hand[0] == '5' && hand[2] == '4' && hand[4] == '3' && hand[6] == '2'
			&& hand[8] == 'A') {
		return 1;
	}
	return 0;
}

int isTrips(char* hand) { // test du Brelan
	int i, cpt = 0;
	for (i = 0; i < 10; i = i + 2)
		if (hand[i] == hand[0])
			++cpt;
	if (cpt == 3)
		return 1;
	return 0;
}

int isTwoPairs(char* hand) { // test de la double paire
	int i, cpt = 0;
	for (i = 0; i < 10; i = i + 2) {
		if (hand[i] == hand[2])
			++cpt;
		if (hand[i] == hand[6])
			++cpt;
	}
	cpt = cpt - 2;
	if (cpt == 2)
		return 1;
	return 0;
}

int isSinglePair(char* hand) { // test de la paire simple
	if (hand[0] == hand[2] || hand[2] == hand[4] || hand[4] == hand[6]
			|| hand[6] == hand[8])
		return 1;
	return 0;
}

char* calculForceSymbolique(char* hand) { // création des forces symboliques
	char* forceSymbolique = (char*) malloc(10 * sizeof(char*));

	if (isStraightFlush(hand) == 1) {
		sprintf(forceSymbolique, "9%c", hand[0]);
		return forceSymbolique;
	}

	if (isQuads(hand) == 1) {
		if (hand[0] == hand[2]) {
			sprintf(forceSymbolique, "8%c%c", hand[0], hand[8]);
			return forceSymbolique;
		}
		sprintf(forceSymbolique, "8%c%c", hand[2], hand[0]);
		return forceSymbolique;
	}

	if (isFullHouse(hand) == 1) {
		if (hand[0] == hand[4]) {
			sprintf(forceSymbolique, "7%c%c", hand[4], hand[8]);
			return forceSymbolique;
		}
		sprintf(forceSymbolique, "7%c%c", hand[4], hand[0]);
		return forceSymbolique;
	}

	if (isFlush(hand) == 1) {
		sprintf(forceSymbolique, "6%c%c%c%c%c", hand[0], hand[2], hand[4],
				hand[6], hand[8]);
		return forceSymbolique;
	}

	if (isStraight(hand) == 1) {
		sprintf(forceSymbolique, "5%c", hand[0]);
		return forceSymbolique;
	}

	if (isTrips(hand) == 1) {
		if (hand[0] == hand[4]) {
			sprintf(forceSymbolique, "4%c%c%c", hand[4], hand[6], hand[8]);
			return forceSymbolique;
		}
		sprintf(forceSymbolique, "4%c%c%c", hand[4], hand[0], hand[2]);
		return forceSymbolique;
	}

	if (isTwoPairs(hand) == 1) {
		if (hand[0] != hand[2]) {
			sprintf(forceSymbolique, "3%c%c%c", hand[2], hand[6], hand[0]);
			return forceSymbolique;
		} else if (hand[8] != hand[6]) {
			sprintf(forceSymbolique, "3%c%c%c", hand[0], hand[4], hand[8]);
			return forceSymbolique;
		}
		sprintf(forceSymbolique, "3%c%c%c", hand[0], hand[6], hand[4]);
		return forceSymbolique;
	}

	if (isSinglePair(hand) == 1) {
		if (hand[0] == hand[2]) {
			sprintf(forceSymbolique, "2%c%c%c%c", hand[0], hand[4], hand[6],
					hand[8]);
			return forceSymbolique;
		} else if (hand[2] == hand[4]) {
			sprintf(forceSymbolique, "2%c%c%c%c", hand[2], hand[0], hand[6],
					hand[8]);
			return forceSymbolique;
		} else if (hand[4] == hand[6]) {
			sprintf(forceSymbolique, "2%c%c%c%c", hand[4], hand[0], hand[2],
					hand[8]);
			return forceSymbolique;
		}
		sprintf(forceSymbolique, "2%c%c%c%c", hand[6], hand[0], hand[2],
				hand[4]);
		return forceSymbolique;
	}
	sprintf(forceSymbolique, "1%c%c%c%c%c", hand[0], hand[2], hand[4], hand[6],
			hand[8]);
	return forceSymbolique;
}

int value(char c) {
	switch (c) {
	case '2':
		return 1;
		break;
	case '3':
		return 2;
		break;
	case '4':
		return 3;
		break;
	case '5':
		return 4;
		break;
	case '6':
		return 5;
		break;
	case '7':
		return 6;
		break;
	case '8':
		return 7;
		break;
	case '9':
		return 8;
		break;
	case '1':
		return 9;
		break;
	case 'J':
		return 10;
		break;
	case 'Q':
		return 11;
		break;
	case 'K':
		return 12;
		break;
	case 'A':
		return 13;
		break;
	default:
		return 0;
		break;
	}
}

//retourne <0 si pow1 < pow2 0 si egale et >0 si superieure
int compare(char* pow1, char* pow2) {

	if (pow1[0] == pow2[0]) {
		int i = 1;
		while (value(pow1[i]) == value(pow2[i]) && value(pow1[i]) != 0
				&& value(pow2[i]) != 0) {
			i++;
		}
		return value(pow1[i]) - value(pow2[i]);
	}
	return pow1[0]-pow2[0];
}
