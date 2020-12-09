#include "pagerank.h"

Pagerank::Pagerank(Graph *g, bool loadType) {
    _graph = g;
    int matSize = _graph->getVertices().size();
    
    _graphMat = new Matrix(matSize, matSize, true);
    if(loadType) {
        loadWeightRank();
    } else {
        loadLabelRank();
    }
    vector<Vertex> tempVertex = _graph->getVertices();
    for (int i = 0; i < (int) tempVertex.size(); i++) {
        _viMap[tempVertex[i]] = i;
    }
}

void Pagerank::loadLabelRank() {
    vector<Edge> tempEdges = _graph->getEdges();
    for (int i = 0; i < int(tempEdges.size()); i++) {
        Edge e = tempEdges[i];
        _graphMat->setEntry(_viMap[e.source], _viMap[e.dest], stoi(e.getLabel()));
    }
}

void Pagerank::loadWeightRank() {
    vector<Edge> tempEdges = _graph->getEdges();
    for (int i = 0; i < int(tempEdges.size()); i++) {
        Edge e = tempEdges[i];
        _graphMat->setEntry(_viMap[e.source], _viMap[e.dest], e.getWeight());
    }

}