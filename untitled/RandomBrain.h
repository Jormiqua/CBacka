//
// Created by Raphael on 3/16/2017.
//

#ifndef UNTITLED_RANDOMBRAIN_H
#define UNTITLED_RANDOMBRAIN_H


#include "Brain.h"

class RandomBrain : Brain
{
    float virtual scoreBoard(BoardArray ba, Colors willPlayColor)
    {
        return (float) (rand() / double(RAND_MAX));
    }
};


#endif //UNTITLED_RANDOMBRAIN_H
