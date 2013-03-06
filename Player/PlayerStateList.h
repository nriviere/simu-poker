/*
 * PlayerStateList.h
 *
 *  Created on: 10 févr. 2013
 *      Author: viande
 */

#ifndef PLAYERSTATELIST_H_
#define PLAYERSTATELIST_H_
#include "PlayerState.h"
#include "OutGameState.h"
#include "InGameState.h"
#include "FoldState.h"


class Player;

class PlayerStateList {
public:

	PlayerStateList(Player *Player);
	virtual ~PlayerStateList();
    FoldState *getFoldState() const
    {
        return foldState;
    }

    InGameState *getInGameState() const
    {
        return inGameState;
    }

    void setInGameState(InGameState *inGameState)
    {
        this->inGameState = inGameState;
    }

    void setOutGameState(OutGameState *outGameState)
    {
        this->outGameState = outGameState;
    }

    void setFoldState(FoldState *foldState)
    {
        this->foldState = foldState;
    }

    Player *getPlayer() const
    {
        return player;
    }

    void setPlayer(Player *Player)
    {
        this->player = player;
    }

private:
	Player *player;
	InGameState *inGameState;
	OutGameState *outGameState;
	FoldState *foldState;
};

#endif /* PLAYERSTATELIST_H_ */
