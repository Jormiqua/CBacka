//
// Created by Raphael on 3/17/2017.
//

#ifndef UNTITLED_NEURALNETWROK_H
#define UNTITLED_NEURALNETWROK_H


class NeuralNetwork
{
public:

    NeuralNetwork(const int numberOfInputs, const int numberOfNodes);

    virtual ~NeuralNetwork();

    void initializeWeights();

    const int numberOfInputs;
    const int numberOfNodes ;
    float weights_1;
    float weights_2;

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
