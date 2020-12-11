#pragma once
#include "airlines.h"
#include "airports.h"
#include "planes.h"
#include "routes.h"
#include "cs225/graph.h"
#include "utils.h"
#include "airlineFlow.h"
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
        Pagerank(const Graph* g, bool loadType);

        /**
         * Return the matrix used for PageRank
         * @returns matrix used for PageRank
         */
        Matrix* returnMatrix() {
            return _graphMat;
        }
        /**
         * operate loading and generating results
         * @param _airlineFlow airlineflow pointer to get airport
         * @param double the alpha to set initial vector
         */
        void pagerankOperation(AirlineFlow* _airlineFlow, double alpha);
        
    private:
        /**
         * Load the matrix with edge label (number of airlines that fly in this route) as the weight
         */
        void _loadLabelRank();

        /**
         * Load the matrix with edge weight (distance between two airports) as the weight
         */
        void _loadWeightRank();

        /** Graph used when generating matrix */
        const Graph* _graph;

        //AirlineFlow _airlineFlow;

        /** Generated matrix */
        Matrix* _graphMat;

        /** Mapping from vertex to its associated index in the matrix */
        unordered_map<Vertex, int> _vertexToIdx;

        /** Mapping from index in the matrix to its associated vertex */
        vector<Vertex> _idxToVertex;

};