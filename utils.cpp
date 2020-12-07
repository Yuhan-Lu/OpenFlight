#include "utils.h"
#include <algorithm>
#include <iostream>

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

    Pagerank::Matrix* matrixMul(Pagerank::Matrix * matrix1, Pagerank::Matrix * matrix2) {
        double **mat1 = matrix1->_value;
        double **mat2 = matrix2->_value;
        int mat1xRow = matrix1->returnRows();
        int mat1yCol = matrix1->returnCols();
        int mat2xRow = matrix2->returnRows();
        int mat2yCol = matrix2->returnCols();
        double **res = new double*[mat1xRow];
        // initial and compute value for res matrix
        for (int i = 0; i < mat1xRow; i++) {
            res[i] = new double[mat2yCol];
            for (int j = 0; j < mat2yCol; j++) {
                res[i][j] = 0;
                for (int k = 0; k < mat1yCol; k ++) {
                    res[i][j] += mat1[i][k] * mat2[k][j];
                }
            }
        }
        Pagerank::Matrix* toReturn = new Pagerank::Matrix(res, mat1xRow, mat2yCol);
        return toReturn;
    }
}