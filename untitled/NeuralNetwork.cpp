//
// Created by Raphael on 3/17/2017.
//

#include <cmath>
#include <utility>
#include <cstdlib>
#include "NeuralNetwork.h"


/// Computation
void NeuralNetwork::computeA(float *input, float *A)
{
    float sum = 0;
    for (int i = 0; i < this->numberOfNodes; i++)
    {
        sum = 0;
        for (int j = 0; j < this->numberOfInputs; j++)
        {
            sum += weights_1[i][j] * input[j];
        }

        A[i] = sigmoid(sum);
    }
    A[this->numberOfNodes] = 1;
}

float NeuralNetwork::computeScore(float *input)
{
    float A [this->numberOfNodes + 1];
    computeA(input, A);
    return  computeScore(input, A);

}

float NeuralNetwork::computeScore(float *input, float *A)
{
    float sum = 0;
    for (int i = 0; i < numberOfNodes + 1; i++)
    {
        sum += A[i] * weights_2[i];
    }

    return sigmoid(sum);
}

void NeuralNetwork::computeGrads(float *input, float *A,
                                 std::pair<float[numberOfNodes][numberOfInputs], float[numberOfNodes + 1]> grads)
{
    float score = computeScore(input, A);


    for (int i = 0; i < numberOfNodes; i ++)
    {
        for (int j = 0; j < numberOfInputs; j++)
        {
            grads.first[i][j] = score * ( 1 - score) * A[i] * (1 - A[i]) * input[j] * weights_2[i];
        }
    }

    for (int j = 0; j < numberOfInputs + 1; j++)
    {
        grads.second[j] =  score * (1 - score) * A[j];
    }
}

void NeuralNetwork::computeGrads(float *input,
                                 std::pair<float[numberOfNodes][numberOfInputs], float[numberOfNodes + 1]> grads)
{
    float A [numberOfNodes + 1];
    computeA(input, A);
    computeGrads(input, A, grads);
}

/// Utils
float NeuralNetwork::dsigmoid(float x)
{
    return  sigmoid(x) * (1 - sigmoid(x));
}

float NeuralNetwork::sigmoid(float x)
{
    return  1 / (1 + std::exp(-1 * x));
}


NeuralNetwork::NeuralNetwork()
{
 initializeWeights();
}

//NeuralNetwork::~NeuralNetwork()

//}
//    delete weights_2;
//    delete weights_1
//{
/// Construction
// NeuralNetwork::NeuralNetwork(int numberOfInputs, int numberOfNodes): numberOfInputs(numberOfInputs), numberOfNodes(numberOfNodes)
//{
//    weights_1 = new float[numberOfNodes][numberOfInputs];
//    int** weights_1 = new int*[numberOfInputs];
//    for(int i = 0; i < numberOfInputs; ++i)
//        weights_1[i] = new int[numberOfNodes];
//
//    weights_2 = new float[numberOfNodes + 1];
//    initializeWeights();
//
//}
void NeuralNetwork::initializeWeights()
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
