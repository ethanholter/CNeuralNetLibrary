//
// Created by holte on 4/30/2023.
//

//TODO need to initialize weight matrices to random values on creation

#include <stdexcept>
#include "NodeLayer.h"

NodeLayer::NodeLayer(int size, const string & aFunc, NodeLayer *next) {
    this->layerSize = size;
    this->activationFunction = aFunc;
    this->nextLayer = next;

    if (next != nullptr) {
        this->weight = new Matrix(next->getSize(), this->getSize());
    } else {
        this->weight = nullptr;
    }

    this->bias = new Matrix(size, 1);
    this->bias->setAll(1);
}

NodeLayer::~NodeLayer() {
    delete weight;
    delete bias;
}

void NodeLayer::setNextLayer(NodeLayer *newNextLayer) {
    this->nextLayer = newNextLayer;
    this->weight = new Matrix(newNextLayer->getSize(), this->getSize());
}

void NodeLayer::setBias(Matrix *newBias) {
    if (newBias->getRows() != this->layerSize || newBias->getCols() != 1) {
        throw std::invalid_argument("Bias matrix must have rows equal to layer size and 1 column");
    }

    *(this->bias) = *newBias;
}

void NodeLayer::setActivationFunction(const string & aFunc) {
    this->activationFunction = aFunc;
}

void NodeLayer::setSize(int size) {
    this->layerSize = size;

    if (this->nextLayer != nullptr) {
        this->weight = new Matrix(this->nextLayer->getSize(), this->getSize());
    } else {
        this->weight = nullptr;
    }

    this->bias = new Matrix(size, 1);
    this->bias->setAll(1);
}

NodeLayer *NodeLayer::getNextLayer() {
    return this->nextLayer;
}

Matrix *NodeLayer::getBias() {
    return this->bias;
}

string NodeLayer::getActivationFunction() {
    return this->activationFunction;
}

int NodeLayer::getSize() const {
    return this->layerSize;
}
