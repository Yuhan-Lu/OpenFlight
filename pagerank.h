#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "cs225/graph.h"
#include "utils.h"
#include <unordered_map>

using utils::Matrix;

/**
 * Pagerank class, use the method by Markov Chain
 */
class Pagerank {
    public:
        /** 
         * Constructs pageRank
         * @param g the pointer to graph
         * @param loadType load label with 0, load weight with 1
         */
        Pagerank(Graph* g, bool loadType);

        Matrix* returnMatrix() {
            return _graphMat;
        }

        void printMatrix();
    private:
        void loadLabelRank();
        void loadWeightRank();
        Graph* _graph;
        Matrix* _graphMat;
        unordered_map<Vertex, int> _viMap;

};