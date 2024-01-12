#include "matrix.hh"
#include <iostream>


int main() {
    Matrix<float, 1, 4> mat1;
    Matrix<float, 4, 1> mat2;
    mat1._mat = {{{2.5}, {2}, {3}, {1}}};
    mat2._mat = {{{6.1, 2, 3, 4}}};

    mat1.multiply<4>(mat2._mat);
    return 0;
}
