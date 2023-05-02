#include <cstdlib>
#include <ctime>
#include "src/Matrix/Matrix.h"
#include "src/NeuralNet/NeuralNet.h"
#include <iostream>

using namespace std;

int main() {
    std::srand(std::time(nullptr));


    Matrix m = {{1, 2, 3},
                {4, 5, 6}};

    Matrix n = {{1, 2},
                {3, 4},
                {5, 6}};

    Matrix o = {{9,  10, 11},
                {12, 13, 14}};

    Matrix p = o + m;
    Matrix q = o - m;

    Matrix r = {{1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}};

    p.print();
    q.print();
    Matrix::print(p);

    q = r * (Matrix::iMatrix(3) * 3);
    q -= r;

    Matrix::print(q);

    for (int i = 0; i < 11; ++i) {
        cout << i-5 << ":" << NeuralNet::sigmoid(i - 5) << " ";
    }


    return 0;
}
