#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "cs225/graph.h"
#include "util.h"
/**
 * used as Pagerank method by Markov Chain.
 *
 */
class Pagerank{
    public:
        /**
         * Inner class matrix for Pagerank
         */
        class Matrix {
            public:
                /** 
                 * Constructs one matrix
                 * @param r number of rows of the matrix
                 * @param c number of cols of the matrix
                 * @param initialize whether the matrix need to be initialized as 0
                 */
                Matrix(int r, int c, bool initialize) {
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

                Matrix(double ** value, int rows, int cols) {
                    _nRows = rows;
                    _nCols = cols;
                    _value = value;
                }

                void printMatrix() {
                    for (int i = 0; i < _nRows; i++) {
                        for (int j = 0; j < _nCols; j++) {
                            cout << _value[i][j]<<  "\t";
                        }
                        cout<< endl;
                    }
                }
                int returnRows() {
                    return _nRows;
                }
                int returnCols() {
                    return _nCols;
                }
                double ** _value;
            private:

                int _nRows;
                int _nCols;
            

        };

        /** 
         * Constructs pageRank
         * @param g the pointer to graph
         * @param loadType load label with 0, load weight with 1
         */
        Pagerank(Graph *g, bool loadType);

        Matrix * returnMatrix() {
            return graphMat;
        }

        void printMatrix();
    private:
        void loadLabelRank();
        void loadWeightRank();
        Graph * _graph;
        Matrix * graphMat;

};