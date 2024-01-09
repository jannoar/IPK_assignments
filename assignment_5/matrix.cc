#include "matrix.hh"
#include <iostream>


int main() {
    Matrix<int, 2, 2> mat;
    mat._mat = {{{1, 2}, {2, 3}}};
    mat.sub({{{3, 5}, {2, 1}}});
    mat.print();
    return 0;
}
