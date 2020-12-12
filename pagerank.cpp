#include "pagerank.h"
#include <algorithm>

using std::stoi;
using std::pair;
using std::sort;
using std::vector;
using utils::matrixSub;
using utils::matrixMul;

Pagerank::Pagerank(const Graph *g, bool loadType) {
    _graph = g;
    int matSize = _graph->getVertices().size();
    _graphMat = new Matrix(matSize, matSize, true);
    vector<Vertex> tempVertex = _graph->getVertices();
    for (size_t i = 0; i < tempVertex.size(); i++) {
        _vertexToIdx[tempVertex[i]] = i;
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

vector<pair<int, string>> Pagerank::pagerankOperation(AirlineFlow* _airlineFlow, double alpha) {
    Matrix* mat = returnMatrix();
    mat->convertToTransitionMatrix(alpha);
    Matrix * temp = Matrix::initialVector(mat->numRows());
    Matrix* lastMatrix = new Matrix(temp->shape());
    int runTime = 0;
    while(matrixSub(temp, lastMatrix)->norm() > powl(10, -8)) {
        lastMatrix = temp;
        temp = matrixMul(mat, temp);
        temp = temp->normalize();
        runTime++;
    }
    vector<long double> res = temp->toVector();
    vector<pair<int, long double>> groupedVec;
    for (int i = 0; i < (int) res.size(); i++) {
        groupedVec.push_back(pair<int, long double>(stoi(_graph->getVertices().at(i)), res[i]));
    }
    sort(groupedVec.begin(), groupedVec.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    Airports* a = _airlineFlow->getAirportDataset();
    vector<pair<int, string>> toReturn;
    for (auto it = groupedVec.begin(); it != groupedVec.end(); ++it) {
        toReturn.push_back(pair<int, string>(it->first, a->getAirportByID(it->first)->name));
    }
    return toReturn;
}