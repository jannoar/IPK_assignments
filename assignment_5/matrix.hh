#include <iostream>
#include <array>

// a
template<typename matrixType, int col, int rows>
class Matrix {
public:
    std::array<std::array<matrixType, col>, rows> _mat; 
    Matrix() {
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < rows; j++) {
                this->_mat[i][j] = 0;
            }
        }
    }

    void print() {
        for (std::array<matrixType, col> n : this->_mat) {
            for (matrixType m : n) {
                std::cout << m;
            }
            std::cout << "\n";
        }
    }

    matrixType get(int n, int m) {
        return this->_mat[n][m];
    } 
    
    // b
    std::array<std::array<matrixType, col>, rows> transpose(std::array<std::array<matrixType, col>, rows> m) {
        std::array<std::array<matrixType, rows>, col> newMatrix; 
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < rows; ++j) {
                newMatrix[i][j] = m[j][i];
            }
        }
        return newMatrix;
    }

    // c
    std::array<std::array<matrixType, col>, rows> add(std::array<std::array<matrixType, col>, rows> otherMat) {
        std::array<std::array<matrixType, col>, rows> res; 
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < rows; j++) {
                res[i][j] = this->_mat[i][j] + otherMat[i][j];
            }
        }
        return res;

    }

    std::array<std::array<matrixType, col>, rows> sub(std::array<std::array<matrixType, col>, rows> otherMat) {
        std::array<std::array<matrixType, col>, rows> res; 
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < rows; j++) {
                res[i][j] = this->_mat[i][j] - otherMat[i][j];
            }
        }
        return res;
    }

    template<int dimension>
    std::array<std::array<matrixType, rows>, dimension> multiply(std::array<std::array<matrixType, dimension>, col> otherMat) {
        std::array<std::array<matrixType, rows>, dimension> res;
        matrixType tempRes = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < dimension; ++j) {
                for (int k = 0; k < col; ++k) {
                    tempRes += (this->_mat[i][k] * otherMat[k][j]);
                }
                res[i][j] = tempRes;
                tempRes = 0;
            }  
        }
        for (auto a : res) {
            for (auto b : a) {
                std::cout << b << "|";
            }
            std::cout << "\n";
        }
        return res; 
    }
};