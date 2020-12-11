#include "pagerank.h"
#include <iostream>

using std::stoi;
using std::cout;
using std::endl;

Pagerank::Pagerank(const Graph *g, bool loadType) {
    _graph = g;
    int matSize = _graph->getVertices().size();
    _graphMat = new Matrix(matSize, matSize, true);
    vector<Vertex> tempVertex = _graph->getVertices();
    for (size_t i = 0; i < tempVertex.size(); i++) {
        _vertexToIdx[tempVertex[i]] = i;

        // if(tempVertex[i] == "350") {
        //     cout << "faffeeqwfweewfew  " <<i << endl;
        // }
        _idxToVertex.push_back(tempVertex[i]);
    }
    if (loadType) 
        _loadWeightRank();
    else
        _loadLabelRank();
}

void Pagerank::_loadLabelRank() {
    vector<Edge> tempEdges = _graph->getEdges();
    for (size_t i = 0; i < tempEdges.size(); i++) {
        Edge e = tempEdges[i];
        _graphMat->setEntry(_vertexToIdx[e.source], _vertexToIdx[e.dest], stoi(e.getLabel()));
    }
}

void Pagerank::_loadWeightRank() {
    vector<Edge> tempEdges = _graph->getEdges();
    for (size_t i = 0; i < tempEdges.size(); i++) {
        Edge e = tempEdges[i];
        _graphMat->setEntry(_vertexToIdx[e.source], _vertexToIdx[e.dest], e.getWeight());
    }

}