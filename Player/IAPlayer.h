#ifndef IAPLAYER_H_
#define IAPLAYER_H_

#include "Player.h"

class IAPlayer: public Player {
public:
	IAPlayer(int bankRoll, double tightness, double aggressiveness);
	IAPlayer(const IAPlayer &player);
	Player *clone() const;
	virtual ~IAPlayer();
	void iPlay();

private:
	double tightness;
	double aggressiveness;
	double bluff;
	char *handC;

	void getProba();
	void cardToChar();
	double getProba(char *hand, int nbPlayer);
	bool expectedValues(double proba, int gain);
};

#endif /* IAPLAYER_H_ */
