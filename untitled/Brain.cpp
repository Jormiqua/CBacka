//
// Created by Raphael on 3/11/2017.
//

#include <cmath>
#include <array>
#include "Brain.h"

float Brain::scoreBoard(BoardArray ba, Colors willPlayColor)
{
    return (float) (rand() / double(RAND_MAX));
}

Brain::Brain(int numberOfInputs, int numberOfNodes)
{
    initializeWeights();
}



void Brain::initializeWeights()
{
    for (int i = 0; i < numberOfNodes; i ++)
    {
        for (int j = 0; j < numberOfInputs; j++)
        {
            weights_1[i][j] = (float) ((float) (rand() / double(RAND_MAX) - 0.5) * 0.4);
        }
    }

    for (int j = 0; j < numberOfInputs + 1; j++)
    {
        weights_2[j] =  (float) ((float) (rand() / double(RAND_MAX) - 0.5) * 0.4);
    }


}

void Brain::updateGrads()
{
    float score = runScoreBoard();
    for (int i = 0; i < numberOfNodes; i ++)
    {
        for (int j = 0; j < numberOfInputs; j++)
        {
            weights_1[i][j] = score * ( 1 - score) * A[i] * (1 - A[i]) * arrayInput[j] * weights_2[i];
        }
    }

    for (int j = 0; j < numberOfInputs + 1; j++)
    {
        weights_2[j] =  score * (1 - score) * A[j];
    }

}

float Brain::sigmoid(float x)
{
    return  1 / (1 + std::exp(-1 * x));
}

float Brain::dsigmoid(float x)
{
    return  sigmoid(x) * (1 - sigmoid(x));
}

void Brain::updateAArray(float * AArray)
{
    float sum = 0;
    for (int i = 0; i < numberOfNodes; i++)
    {
        sum = 0;
        for (int j = 0; j < numberOfInputs; j++)
        {
            sum += weights_1[i][j] * arrayInput[j];
        }

        AArray[i] = sigmoid(sum);
    }
    AArray[numberOfNodes] = 1;
}

void Brain::updateA()
{
    updateAArray(A);
}

std::vector<int> Brain::computeValueForArrayInput(int numberOfToken, int position, Colors color)
{
    std::vector<int> vector1;

    int color_addition = color == Colors::WHITE ? 0 : 104;

    for (int i = 1; i <= 3; i++)
    {
        vector1.push_back(position % 26 + (i - 1) * 26 + color_addition);
        vector1.push_back((int) numberOfToken >= i);
    }

    vector1.push_back(position % 26 + 3 * 26 + color_addition);
    vector1.push_back(max((float) 0, ((float) (numberOfToken - 3) / 2)));
}

float Brain::runScoreBoard()
{
    //TODO: REMAKE THE FUNCTION UPDATE A TO TAKE A POINTER
}

void Brain::initializeInput(BoardArray ba, Colors playerColor, int* inputs)
{
    std::vector<int> to_update;
    for (int i = 0; i < ba.array_lenght[0]; i++)
    {
        updateArrayOfInputsFromVectorOfValueUpdate(computeValueForArrayInput(ba.get_value(i, ColorManagement::column(Colors::WHITE)), i, Colors::WHITE), inputs);
        updateArrayOfInputsFromVectorOfValueUpdate(computeValueForArrayInput(ba.get_value(i, ColorManagement::column(Colors::BLACK)), i, Colors::BLACK), inputs);
        setColorPlaying(playerColor, inputs);
    }

}

void Brain::updateArrayOfInputsFromVectorOfValueUpdate(std::vector<int> updateValues, int *inputArray)
{
    for (int i = 0; i < updateValues.size(); i = i + 2)
    {
        inputArray[updateValues[i]] = updateValues[i + 1];
    }
}

void Brain::setColorPlaying(Colors color, int *inputArray)
{
    color == Colors::WHITE ? inputArray[208] = 1: inputArray[208] = 0;
    inputArray[209] = 1 - inputArray[208];
}

float Brain::simpleRunFromPlay(Play play)
{
    std::array<int, arrayInputSize> newInput = arrayInput;

}
