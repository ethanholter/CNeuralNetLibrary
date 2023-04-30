#include "Matrix.h"


int main() {
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

    q = r * (Matrix::identityMatrix(3) * 3);
    q -= r;

    Matrix::print(q);


    return 0;
}
