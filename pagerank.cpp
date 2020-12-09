#include "pagerank.h"

Pagerank::Pagerank(Graph *g, bool loadType) {
    _graph = g;
    int matSize = _graph->getVertices().size();
    _graphMat = new Matrix(matSize, matSize, true);
    if(loadType) 
        _loadWeightRank();
    else
        _loadLabelRank();
    vector<Vertex> tempVertex = _graph->getVertices();
    for (int i = 0; i < tempVertex.size(); i++) {
        _vertexToIdx[tempVertex[i]] = i;
        _idxToVertex.push_back(tempVertex[i]);
    }
}

void Pagerank::_loadLabelRank() {
    vector<Edge> tempEdges = _graph->getEdges();
    for (int i = 0; i < tempEdges.size(); i++) {
        Edge e = tempEdges[i];
        _graphMat->setEntry(_vertexToIdx[e.source], _vertexToIdx[e.dest], stoi(e.getLabel()));
    }
}

void Pagerank::_loadWeightRank() {
    vector<Edge> tempEdges = _graph->getEdges();
    for (int i = 0; i < tempEdges.size(); i++) {
        Edge e = tempEdges[i];
        _graphMat->setEntry(_vertexToIdx[e.source], _vertexToIdx[e.dest], e.getWeight());
    }

}