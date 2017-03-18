//
// Created by Raphael on 3/13/2017.
//

#ifndef UNTITLED_AUTOPLAYER_H

#pragma once
#include "Player.h"
#include "Brain.h"

class AutoPlayer : Player
{
public:
    virtual std::pair<Play, float> play(BoardArray ba, Colors playerColor, std::vector<Play> plays);
    Brain brain;
};


#endif //UNTITLED_AUTOPLAYER_H
