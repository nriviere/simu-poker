/*
 * Action.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef ACTION_H_
#define ACTION_H_

class Game;
class Player;

class Action {
public:
	Action(Player *player);
	virtual ~Action();
	virtual void execute() = 0;
protected:
	Player *player;
	Game *game;
};

#endif /* ACTION_H_ */
