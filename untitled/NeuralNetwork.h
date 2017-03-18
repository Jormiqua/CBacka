//
// Created by Raphael on 3/17/2017.
//

#ifndef UNTITLED_NEURALNETWROK_H
#define UNTITLED_NEURALNETWROK_H


class NeuralNetwork
{
public:

//    NeuralNetwork(const int numberOfInputs, const int numberOfNodes);
//    virtual ~NeuralNetwork();

    NeuralNetwork();

    void initializeWeights();

    static const int numberOfInputs = 26 * 4 * 2 + 2;
    static const int numberOfNodes = 100;
    float weights_1[numberOfNodes][numberOfInputs];
    float weights_2[numberOfNodes + 1];

    void computeA(float *input, float *A);

    float computeScore(float *input, float *A);
    float computeScore(float *input);

    void computeGrads(float *input, float *A,
                      std::pair<float[numberOfNodes][numberOfInputs], float[numberOfNodes + 1]> grads);
    void computeGrads(float *input, std::pair<float[numberOfNodes][numberOfInputs], float[numberOfNodes + 1]> grads);

    /// Utils
    float sigmoid(float x);
    float dsigmoid(float x);
};


#endif //UNTITLED_NEURALNETWROK_H
