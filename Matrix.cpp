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

Matrix::Matrix(const std::initializer_list<std::initializer_list<float>> & data) {
    rows = (int)data.size();
    cols = (int)data.begin()->size();
    initializeData(rows, cols);
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
        throw std::runtime_error("Matrix not initialized");
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << data[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Matrix::initializeData(int r, int c) {
    if (data != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    data = new float *[r];
    for (int i = 0; i < r; i++) {
        this->data[i] = new float[c];
    }
}

void Matrix::setAll(float n) {
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = n;
        }
    }
}

Matrix::Matrix(const Matrix &m) {
    rows = m.getRows();
    cols = m.getCols();
    initializeData(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = m[i][j];
        }
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getCols() const {
    return cols;
}

//TODO
void Matrix::randomise() {}

Matrix Matrix::operator+=(const Matrix & m) {
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += m[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-=(const Matrix & m) {
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= m[i][j];
        }
    }
    return *this;
}

Matrix Matrix::operator-() const {
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }

    Matrix n(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            n[i][j] = -data[i][j];
        }
    }
    return n;
}

void Matrix::setIdentity() {
    if (rows != cols) {
        throw std::runtime_error("Cannot create identity matrix from non-square matrix");
    }

    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = (i == j) ? 1 : 0;
        }
    }
}

//TODO
[[maybe_unused]] float Matrix::determinate() {
    return 0;
}

Matrix Matrix::operator*=(const Matrix &m) {
    if (this->cols != m.getRows()) {
        throw std::runtime_error("Matrices cannot be multiplied");
    }

    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }

    Matrix n = *this;
    cols = m.getCols();
    initializeData(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            float sum = 0;
            for (int k = 0; k < n.getCols(); ++k) {
                    sum += n[i][k]*m[k][j];
            }
            data[i][j] = sum;
        }
    }
    return n;
}

Matrix Matrix::operator*=(float n) const {
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] *= n;
        }
    }
    return *this;
}

Matrix &Matrix::operator=(const Matrix & m) {
    if (this != &m) {
        rows = m.getRows();
        cols = m.getCols();
        initializeData(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                data[i][j] = m[i][j];
            }
        }
    }

    return *this;
}

float *Matrix::operator[](int i) const{
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }
    return data[i];
}

Matrix Matrix::operator+=(float n) {
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }
    Matrix m(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] += n;
        }
    }
    return m;
}

Matrix Matrix::operator-=(float n) {
    if(data == nullptr) {
        throw std::runtime_error("Matrix not initialized");
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] -= n;
        }
    }
    return *this;
}

Matrix Matrix::operator+(const Matrix &m) const {
    Matrix result = *this;
    result += m;
    return result;
}

Matrix Matrix::operator+(float n) const {
    Matrix result = *this;
    result += n;
    return result;
}

Matrix Matrix::operator-(const Matrix &m) const {
    Matrix result = *this;
    result -= m;
    return result;
}

Matrix Matrix::operator-(float n) const {
    Matrix result = *this;
    result -= n;
    return result;
}

Matrix Matrix::operator*(const Matrix &m) const {
    Matrix result = *this;
    result *= m;
    return result;
}

Matrix Matrix::operator*(float n) const {
    Matrix result = *this;
    result *= n;
    return result;
}


void Matrix::print(const Matrix &m) {
    m.print();
}

Matrix Matrix::identityMatrix(int size) {
    Matrix n(size, size);
    n.setIdentity();
    return n;
}

