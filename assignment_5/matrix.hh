#include <iostream>
#include <array>

template<typename matrixType, int rows, int cols>
class Matrix {
public:
    std::array<std::array<matrixType, rows>, cols> _mat; 
    Matrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                this->_mat[i][j] = 0;
            }
        }
    }

    void print() {
        for (std::array<matrixType, rows> n : this->_mat) {
            for (matrixType m : n) {
                std::cout << m;
            }
            std::cout << "\n";
        }
    }

    matrixType get(int n, int m) {
        return this->_mat[n][m];
    } 
    
    std::array<std::array<matrixType, rows>, cols> transpose(std::array<std::array<matrixType, rows>, cols> m) {
        std::array<std::array<matrixType, cols>, rows> newMatrix; 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                newMatrix[i][j] = m[j][i];
            }
        }
        return newMatrix;
    }

    std::array<std::array<matrixType, rows>, cols> add(std::array<std::array<matrixType, rows>, cols> otherMat) {
        std::array<std::array<matrixType, rows>, cols> res; 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = this->_mat[i][j] + otherMat[i][j];
            }
        }
        return res;

    }

    std::array<std::array<matrixType, rows>, cols> sub(std::array<std::array<matrixType, rows>, cols> otherMat) {
        std::array<std::array<matrixType, rows>, cols> res; 
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; j++) {
                res[i][j] = this->_mat[i][j] - otherMat[i][j];
            }
        }
        return res;
    }

    std::array<std::array<matrixType, rows>, cols> multiply(std::array<std::array<matrixType, rows>, cols> otherMat) {

    }
};
