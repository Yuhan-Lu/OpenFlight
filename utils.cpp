#include "utils.h"
#include <algorithm>
#include <iostream>
#include <assert.h>

using std::cout;
using std::stringstream;
using std::remove;

namespace utils {
    vector<string> readEntry(string &s) {
        string item;
        vector<string> elems;
        size_t idx = 0;
        while (idx < s.size()) {
            if (s[idx] == '\"') {
                idx++;
                while (s[idx] != '\"') {
                    item.push_back(s[idx++]);
                }
            } else {
                while (idx < s.size()) {
                    if (s[idx] == ',') break;
                    item.push_back(s[idx++]);
                }
                if (item == "\\N") elems.push_back("");
                else elems.push_back(item);
                item.clear();
            }
            idx++;
        }
        if (item == "\\N") elems.push_back("");
        else elems.push_back(item);
        return elems;
    }

    double getDistance(double latitude1, double longtitude1, double latitude2, double longtitude2) {
        /**
         * Change to Radian  
         * lat = latitude / 180 * pi 
         * long = longt / 180 *pi
         */
        double latiR1 = latitude1 / 180 * M_PI;
        double latiR2 = latitude2 / 180 * M_PI;
        double longR1 = longtitude1 / 180 * M_PI;
        double longR2 = longtitude2 / 180 * M_PI;

        double latiDiff = latiR2 - latiR1;
        double longDiff = longR2 - longR1;

        double part1 = pow(sin(latiDiff / 2), 2) + pow(sin(longDiff / 2), 2) * cos(latiR1) * cos(latiR2); 
        //6371 is the radian of earth in km
        return 2 * asin(sqrt(part1)) * 6371;
    }

    Matrix::Matrix(int r, int c, bool initialize) {
        _nRows = r;
        _nCols = c;
        _value = new double*[_nRows];
        for (int i = 0; i < _nRows; i++) {
            _value[i] = new double[_nCols];
            if (initialize) {
                for (int j = 0; j < _nCols; j++) {
                    _value[i][j] = 0;
                }
            }
        }
    }

    Matrix::Matrix(int rows, int cols, double** value) {
        _nRows = rows;
        _nCols = cols;
        _value = value;
    }
    
    void Matrix::printMatrix() {
        for (int i = 0; i < _nRows; i++) {
            for (int j = 0; j < _nCols; j++) {
                cout << _value[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void Matrix::setEntry(int r, int c, double entry) {
        _value[r][c] = entry;
    }

    double Matrix::getEntry(int r, int c) {
        return _value[r][c];
    }

    Matrix* matrixMul(Matrix * matrix1, Matrix * matrix2) {
        assert(matrix1->numCols() == matrix2->numRows());
        int mat1Row = matrix1->numRows();
        int mat1Col = matrix1->numCols();
        int mat2Col = matrix2->numCols();
        Matrix* toReturn = new Matrix(mat1Row, mat2Col, false);
        for (int i = 0; i < mat1Row; i++) {
            for (int j = 0; j < mat2Col; j++) {
                double sum = 0;
                for (int k = 0; k < mat1Col; k ++) {
                    sum += matrix1->getEntry(i, k) * matrix2->getEntry(k, j);
                }
                toReturn->setEntry(i, j, sum);
            }
        }
        return toReturn;
    }
}