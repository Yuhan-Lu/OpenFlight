#include <fstream>  
#include <unordered_map>
#include <iostream>
#include "utils.h"
#include "pagerank.h"
#include "cs225/graph.h"

using namespace std;

Pagerank::Pagerank(Graph *g, bool loadType) {
    _graph = g;
    int matSize = _graph->getVertices().size();
    
    graphMat = new Matrix(matSize, matSize, true);
    if(loadType) {
        loadWeightRank();
    } else {
        loadLabelRank();
    }
}

void Pagerank::loadLabelRank() {
    int matSize = _graph->getVertices().size();
    vector<Edge> tempEdges = _graph->getEdges();
    vector<Vertex> tempVertex = _graph->getVertices();

    unordered_map<Vertex, int> viMap;
    for (int i = 0; i < int(tempVertex.size()); i++) {
        viMap[tempVertex[i]] = i;
        cout << " Vertex order" << i << ' ' << tempVertex[i] << endl;
    }

    for (int i = 0; i < int(tempEdges.size()); i++) {
        Edge e = tempEdges[i];
        graphMat->_value[viMap[e.source]][viMap[e.dest]] = stoi(e.getLabel());
    }
}

void Pagerank::loadWeightRank() {
    int matSize = _graph->getVertices().size();
    vector<Edge> tempEdges = _graph->getEdges();
    vector<Vertex> tempVertex = _graph->getVertices();
    unordered_map<Vertex, int> viMap;
    for (int i = 0; i < int(tempVertex.size()); i++) {
        viMap[tempVertex[i]] = i;
        cout << " Vertex order" << i << ' ' << tempVertex[i] << endl;
    }
    for (int i = 0; i < int(tempEdges.size()); i++) {
        Edge e = tempEdges[i];
        graphMat->_value[viMap[e.source]][viMap[e.dest]] = e.getWeight();
    }

}