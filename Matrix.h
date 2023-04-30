//
// Created by holte on 4/27/2023.
//

#ifndef C_NEURAL_NET_MATRIX_H
#define C_NEURAL_NET_MATRIX_H


#include <initializer_list>

class Matrix {
public:
    explicit Matrix();
    explicit Matrix(int r, int c);
    Matrix(const std::initializer_list<std::initializer_list<float>>& data);

    Matrix(const Matrix& m);
    ~Matrix();

    void print() const;
    void setAll(float n);
    void setIdentity();
    void randomise();
    float determinate();

    Matrix operator+=(const Matrix & m);
    Matrix operator+=(float n);
    Matrix operator-=(const Matrix & m);
    Matrix operator-=(float n);
    Matrix operator*=(const Matrix & m);
    Matrix operator*=(float n) const;

    Matrix operator+(const Matrix & m) const;
    Matrix operator+(float n) const;
    Matrix operator-(const Matrix & m) const;
    Matrix operator-(float n) const;
    Matrix operator*(const Matrix & m) const;
    Matrix operator*(float n) const;

    Matrix& operator=(const Matrix & m);
    float* operator[](int i) const;
    Matrix operator-() const;

    [[nodiscard]] int getRows() const;
    [[nodiscard]] int getCols() const;

    static void print(const Matrix& m);
    static Matrix identityMatrix(int size);



private:
    int rows;
    int cols;
    float **data{};

    void initializeData(int r, int c);
};


#endif //C_NEURAL_NET_MATRIX_H
