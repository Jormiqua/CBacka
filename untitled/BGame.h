//
// Created by Raphael on 3/20/2017.
//

#ifndef UNTITLED_BGAME_H
#define UNTITLED_BGAME_H


#include "Player.h"

class BGame
{
public:
    BGame(Player *playerWhite, Player *playerBlack);

    Player *playerWhite = 0;
    Player *playerBlack = 0;
};


#endif //UNTITLED_BGAME_H
