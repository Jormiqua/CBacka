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
    virtual std::pair<Play, float> pickBestPlay(BoardArray ba, std::vector<Play>, Colors playerColor);
    Brain brain;
};


#endif //UNTITLED_AUTOPLAYER_H
