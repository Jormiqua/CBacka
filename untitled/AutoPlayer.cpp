//
// Created by Raphael on 3/13/2017.
//

#include <iostream>
#include "AutoPlayer.h"

std::pair<Play, float> AutoPlayer::play(BoardArray ba, Colors playerColor, std::vector<Play> plays)
{
    return this->brain.pickBestPlay(ba, playerColor, plays);
}

std::string AutoPlayer::whatAmI()
{
    return "A auto player";
}

//AutoPlayer::AutoPlayer(Brain brain) : brain(brain)
//{}