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
    explicit Matrix(const std::initializer_list<std::initializer_list<float>> & data, int r, int c);
    Matrix(Matrix & m);

    ~Matrix();

    void print() const;
    void setAll(float n);
    void randomise();

    [[nodiscard]] int getRows() const;
    [[nodiscard]] int getCols() const;
    [[nodiscard]] float at(int r, int c) const;




private:
    int rows;
    int cols;
    float **data{};

    void initializeData(int r, int c);
};


#endif //C_NEURAL_NET_MATRIX_H
