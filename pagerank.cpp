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

void Pagerank::pagerankOperation(AirlineFlow* _airlineFlow, double alpha) {
    Matrix* mat = returnMatrix();
    mat->convertToDampingMatrix(0.85);
    Matrix * temp = Matrix::initialVector(mat->numRows());
    Matrix* lastMatrix = new Matrix(temp->shape());
    int runTime = 0;
    while(utils::matrixSub(temp, lastMatrix)->norm() > powl(10, -8)) {
        lastMatrix = temp;
        temp = utils::matrixMul(mat, temp);
        temp = temp->normalize();
        runTime++;
    }
    vector<long double> res = temp->toVector();
    vector<pair<int, long double>> groupedVec;
    for (int i = 0; i < (int) res.size(); i++) {
        groupedVec.push_back(std::pair<int, long double>(stoi(_graph->getVertices().at(i)), res[i]));
    }
    std::sort(groupedVec.begin(), groupedVec.end(), [](auto &left, auto &right) {
        return left.second > right.second;
    });
    Airports* a = _airlineFlow->getAirportDataset();
    int ranking = 1;
    for (auto it = groupedVec.begin(); it != groupedVec.end(); ++it) {
        std::pair<int, string> dataPair(it->first, a->getAirportByID(it->first)->name);
        cout<< ranking << ": " << it->first << " \t" << a->getAirportByID(it->first)->name << endl;
        ranking++;
    }
}