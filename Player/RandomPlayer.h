#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

#include "Player.h"

class RandomPlayer: public Player {
public:
  RandomPlayer(int bankRoll);

	void iPlay();
	Player *clone() const;


};

#endif /* RANDOMPLAYER_H_ */
