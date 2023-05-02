//
// Created by holte on 4/30/2023.
//

#ifndef C_NEURAL_NET_NODELAYER_H
#define C_NEURAL_NET_NODELAYER_H

#include <string>
#include "../Matrix/Matrix.h"

using namespace std;

class NodeLayer {
public:
    explicit NodeLayer(int size=1, const string &aFunc="ReLU", NodeLayer* next= nullptr);

    ~NodeLayer();

    void setNextLayer(NodeLayer* newNextLayer);
    void setBias(Matrix* newBias);
    void setWeight(Matrix* weight);
    void setActivationFunction(const string & aFunc);
    void setSize(int size);

    NodeLayer *getNextLayer();
    Matrix *getBias();
    string getActivationFunction();
    [[nodiscard]] int getSize() const;

private:
    string activationFunction;
    int layerSize;
    Matrix *bias;

    NodeLayer *nextLayer;
    Matrix *weight;
};


#endif //C_NEURAL_NET_NODELAYER_H
