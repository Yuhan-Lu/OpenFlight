#include "airlineFlow.h"

AirlineFlow::AirlineFlow(bool test) : _airlines(new Airlines(test)), _airports(new Airports(test)), 
        _planes(new Planes(test)), _routes(new Routes(test)), _airlineMap(true, true) {
    /* add all the airports to the graph */
    for (auto it = _airports->begin(); it != _airports->end(); ++it) {
        _airlineMap.insertVertex(to_string(it->first));
    }
    /* add all the routes to the graph and construct edge list */
    for (auto it = _routes->begin(); it != _routes->end(); ++it) {
        int id = (*it)->airlineID;
        int source = (*it)->airportID1;
        if (source == -1) {
            source = _airports->getAirportIDByIATA((*it)->airport1);
        }
        int destination = (*it)->airportID2;
        if (destination == -1) {
            destination = _airports->getAirportIDByIATA((*it)->airport2);
        }
        string label = to_string(source) + "_" + to_string(destination);
        auto edge = _edgeList.find(label);
        if (edge != _edgeList.end()) {
            /* the edge already exists */
            edge->second.push_back(id);
            int weight = _airlineMap.getEdge(to_string(source), to_string(destination)).getWeight();
            _airlineMap.setEdgeWeight(to_string(source), to_string(destination), weight + 1);
        } else {
            /* the edge does not exist */
            _edgeList[label].push_back(id);
            _airlineMap.insertEdge(to_string(source), to_string(destination));
            _airlineMap.setEdgeWeight(to_string(source), to_string(destination), 0);
        }
    }
}

AirlineFlow::~AirlineFlow() {
    delete _airlines;
    delete _airports;
    delete _planes;
    delete _routes;
}

vector<int> AirlineFlow::getAirlineBetweenAirports(int sourceAirportID, int destAirportID) {
    string label = to_string(sourceAirportID) + "_" + to_string(destAirportID);
    auto res = _edgeList.find(label);
    if (res == _edgeList.end()) return vector<int>();
    return res->second;
}
