//
// Created by Raphael on 3/13/2017.
//

#ifndef UNTITLED_PLAYER_H
#define UNTITLED_PLAYER_H

#include <vector>
#include "Play.h"
#include "ColorManagement.h"
#include "BoardArray.h"

class Player
{
private:
    Colors playerColor;
public:
    virtual std::pair<Play, float> pickBestPlay(BoardArray ba, Colors playerColor, std::vector<Play> plays)= 0;
    virtual Colors getColor();
    virtual void setColor(Colors);
};

#endif //UNTITLED_PLAYER_H
