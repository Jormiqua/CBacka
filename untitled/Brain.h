//
// Created by Raphael on 3/17/2017.
//

#ifndef UNTITLED_BRAIN_H
#define UNTITLED_BRAIN_H


#include <array>
#include "BoardArray.h"
#include "ColorManagement.h"
#include "NeuralNetwork.h"

class Brain
{
private:
    void turnBoardIntoInput(BoardArray ba, Colors playerColor, float* input);
public:
    virtual float getScore(BoardArray ba, Colors playerColor);
    NeuralNetwork NN;
    std::pair<Play, float> pickBestPlay(BoardArray ba, Colors playerColor, std::vector<Play> plays);
    virtual std::string whatAmI();

};

class RandomBrain : public Brain
{
public:
    float virtual getScore(BoardArray ba, Colors willPlayColor)
    {
        return (float) (rand() / double(RAND_MAX));
    }

    virtual std::string whatAmI()
    {
        return "A random brain";
    }
public:
    NeuralNetwork NN;


};


#endif //UNTITLED_BRAIN_H
