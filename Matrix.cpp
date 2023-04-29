//
// Created by Ethan Holter on 4/27/2023.
//

#include "Matrix.h"
#include <iostream>

Matrix::Matrix() {
    data = nullptr;
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int r, int c) {
    if(r <= 0 || c <= 0) {
        throw std::invalid_argument("Matrix must have dimensions greater than zero");
    }

    initializeData(r, c);
    rows = r;
    cols = c;
}

Matrix::Matrix(const std::initializer_list<std::initializer_list<float>> & data, int r, int c) {
    initializeData(r, c);
    int i = 0;
    int j = 0;

    // TODO AI generated bullshit lmao
    for (auto row : data) {
        for (auto val : row) {
            this->data[i][j] = val;
            j++;
        }
        i++;
        j = 0;
    }

    rows = r;
    cols = c;
}

Matrix::~Matrix() {
    if(data == nullptr) {
        return;
    }

    for (int i = 0; i < rows; i++) {
        delete[] data[i];
    }
    delete[] data;
}

void Matrix::print() const {
    if(data == nullptr) {
        throw std::invalid_argument("Matrix not initialized");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Matrix::initializeData(int r, int c) {
    this->data = new float *[r];
    for (int i = 0; i < r; i++) {
        this->data[i] = new float[c];
    }
}

void Matrix::setAll(float n) {
    if(data == nullptr) {
        throw std::invalid_argument("Matrix not initialized");
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = n;
        }
    }
}

Matrix::Matrix(Matrix &m) {
    rows = m.getRows();
    cols = m.getCols();
    initializeData(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = m.at(i,j);
        }
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

float Matrix::at(int r, int c) const {
    if(data == nullptr) {
        throw std::invalid_argument("Matrix not initialized");
    }

    return data[r][c];
}

//TODO
void Matrix::randomise() {}
