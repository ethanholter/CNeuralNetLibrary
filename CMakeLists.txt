cmake_minimum_required(VERSION 3.24)
project(C_Neural_Net)

set(CMAKE_CXX_STANDARD 17)

add_executable(C_Neural_Net main.cpp src/Matrix/Matrix.h src/Matrix/Matrix.cpp src/NeuralNet/NeuralNet.h src/NodeLayer/NodeLayer.h src/NodeLayer/NodeLayer.cpp src/NeuralNet/NeuralNet.cpp)
