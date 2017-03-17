//
// Created by Raphael on 3/11/2017.
//

#ifndef UNTITLED_BRAIN_H
#define UNTITLED_BRAIN_H


#include "BoardArray.h"
#include "ColorManagement.h"

class Brain
{
private:
    void updateGrads();
    void updateAArray(float *);
    std::vector<int> computeValueForArrayInput(int numberOfToken, int position, Colors color);
    void updateArrayOfInputsFromVectorOfValueUpdate(std::vector<int> updateValues, int * inputArray);
    void setColorPlaying(Colors color, int * inputArray);

public:
/// Gloabal variable
    virtual float scoreBoard(BoardArray ba, Colors willPlayColor);
    static const int numberOfInputs = 2;
    static const int numberOfNodes = 2;
    float alpha;
    float lambda;

/// Temp variables
    float weights_1 [numberOfNodes][numberOfInputs];
    float weights_2 [numberOfNodes + 1];

    float grads_1 [numberOfNodes][numberOfInputs] = {0};
    float grads_2 [numberOfInputs + 1 ] = {0};

    float A [numberOfNodes + 1];
    static const int arrayInputSize = 26 * 4 * 2 + 2;
    std::array<int, arrayInputSize> arrayInput;

/// Constructor
    Brain(int numberOfInputs, int numberOfNodes);
    void initializeWeights();
    void initializeInput(BoardArray ba, Colors playerColor, int* inputs);

/// Utils
    float sigmoid(float x);
    float dsigmoid(float x);


/// Scoring
    float updateAndGoThrought();
    float simpleRunFromBoard(BoardArray ba);
    float simpleRunFromPlay(Play play);

/// Learning
    void updateWeights();
    void updateArrayInput(Play play);

    float runScoreBoard();
};


#endif //UNTITLED_BRAIN_H
