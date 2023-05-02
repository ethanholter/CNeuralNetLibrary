//
// Created by holte on 4/30/2023.
//

#ifndef C_NEURAL_NET_NEURALNET_H
#define C_NEURAL_NET_NEURALNET_H


#include "../Matrix/Matrix.h"

class NeuralNet {
public:
    NeuralNet();
    NeuralNet(int inputs, int outputs, int hLayers, int nodes);

    static float ReLU(float n);
    static float ReLU_derivative(float n);

    static float sigmoid(float n);
    static float sigmoid_derivative(float n);

private:

    Matrix *weights;
    Matrix *biases;
};


#endif //C_NEURAL_NET_NEURALNET_H
