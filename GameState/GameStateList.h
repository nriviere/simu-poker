/*
 * GameStateList.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef GAMESTATELIST_H_
#define GAMESTATELIST_H_
#include "GameState.h"
#include "Preflop.h"
#include "Flop.h"
#include "Turn.h"
#include "River.h"

class Game;

class GameStateList {
public:

	GameStateList(Game *game);
	virtual ~GameStateList();
    Flop *getFlop() const
    {
        return flop;
    }

    Game *getGame() const
    {
        return game;
    }

    Preflop *getPreflop() const
    {
        return preflop;
    }

    River *getRiver() const
    {
        return river;
    }

    Turn *getTurn() const
    {
        return turn;
    }

    void setFlop(Flop *flop)
    {
        this->flop = flop;
    }

    void setGame(Game *game)
    {
        this->game = game;
    }

    void setPreflop(Preflop *preflop)
    {
        this->preflop = preflop;
    }

    void setRiver(River *river)
    {
        this->river = river;
    }

    void setTurn(Turn *turn)
    {
        this->turn = turn;
    }

private:
	Preflop *preflop;
	Flop *flop;
	Turn *turn;
	River *river;
	Game *game;
};

#endif /* GAMESTATELIST_H_ */
