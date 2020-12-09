#pragma once
#include <vector>
#include <string>
#include <math.h>
#include <iostream>

using std::vector;
using std::string;
using std::to_string;
using std::pair;
using std::cout;
using std::endl;

namespace utils {
    
    class Matrix {
        public:
            /** 
             * Constructs empty matrix
             * @param r number of rows of the matrix
             * @param c number of cols of the matrix
             * @param initialize whether the matrix need to be initialized as 0
             */
            Matrix(int r, int c, bool initialize = true);

            /** 
             * Constructs matrix using double pointer
             * @param r number of rows of the matrix
             * @param c number of cols of the matrix
             * @param value the double pointer that discribes the matrix
             */
            Matrix(int r, int c, double** value);

            /** 
             * Get the number of rows the matrix has
             * @returns number of rows the matrix has
             */
            int numRows() {
                return _nRows;
            }
            
            /** 
             * Get the number of cols the matrix has
             * @returns number of cols the matrix has
             */
            int numCols() {
                return _nCols;
            }
            
            /** 
             * Get the shape of the matrix
             * @returns shape of the matrix
             */
            pair<int, int> shape() {
                return pair<int, int>(_nRows, _nCols);
            }

            /** 
             * Set the entry of current matrix at row r, column c
             * @param r row of the entry
             * @param c column of the entry
             * @param entry the new value of the entry
             */
            void setEntry(int r, int c, double entry);

            /** 
             * Get the entry of current matrix at row r, column c
             * @param r row of the entry
             * @param c column of the entry
             * @returns the value of the entry
             */
            double getEntry(int r, int c);

            /** 
             * Prints the matrix
             */
            void printMatrix();

            double ** _value;
        private:
            /** number of rows */
            int _nRows;

            /** number of cols */
            int _nCols;
    };

    /**
     * Prepare the raw string for inputing data
     * @param s input string
     * @returns a vector that contains all the entries
     */
    vector<string> readEntry(string &s);

    /**
     * Get the distance between two points on earth given their latitude and
     * longtitude. 
     * @param latitude1 latitude of the first point
     * @param longtitude1 longtitude of the first point
     * @param latitude2 latitude of the second point
     * @param longtitude2 longtitude of the second point
     * @returns distance between these two points
     */
    double getDistance(double latitude1, double longtitude1, double latitude2, double longtitude2);

    
    /**
     * Get the distance between two points on earth given their latitude and
     * longtitude. 
     * @param latitude1 latitude of the first point
     * @param longtitude1 longtitude of the first point
     * @param latitude2 latitude of the second point
     * @param longtitude2 longtitude of the second point
     * @returns distance between these two points
     */
    Matrix* matrixMul(Matrix* mat1, Matrix* mat2);

    /** Error code used when airport ID is not recognizable */
    const static int ERROR_AIRPORT_ID = -pow(2,30);
    const static string STR_ERROR_AIRPORT_ID = to_string(ERROR_AIRPORT_ID);
}