//
// Created by holte on 4/30/2023.
//

#include "NeuralNet.h"
#include <cmath>

NeuralNet::NeuralNet() {

}

float NeuralNet::ReLU(float n) {
    return (n > 0) ? n : 0;
}

float NeuralNet::ReLU_derivative(float n) {
    return (n > 0) ? 1 : 0;
}

float NeuralNet::sigmoid(float n) {
    return (float)(1/(1+std::exp(-n)));
}

float NeuralNet::sigmoid_derivative(float n) {
    return sigmoid(n)*(1-sigmoid(n));
}
