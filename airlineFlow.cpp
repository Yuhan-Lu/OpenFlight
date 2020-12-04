#include "airlineFlow.h"
#include "utils.h"

using std::stoi;
using utils::getDistance;

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
        /* prevent possible error in the dataset */
        if (source == -1) {
            source = _airports->getAirportIDByIATA((*it)->airport1);
            if (source == -1) continue;
        }
        int destination = (*it)->airportID2;
        /* prevent possible error in the dataset */
        if (destination == -1) {
            destination = _airports->getAirportIDByIATA((*it)->airport2);
            if (destination == -1) continue;
        }
        string label = to_string(source) + "_" + to_string(destination);
        auto edge = _edgeList.find(label);
        if (edge != _edgeList.end()) {
            /* the edge already exists */
            edge->second.push_back(id);
            int num = stoi(_airlineMap.getEdge(to_string(source), to_string(destination)).getLabel());
            _airlineMap.setEdgeLabel(to_string(source), to_string(destination), to_string(num + 1));
        } else {
            /* the edge does not exist */
            auto sourceAirport = _airports->getAirportByID(source);
            double sourceLatitude = sourceAirport->latit;
            double sourceLongitude = sourceAirport->longit;
            auto destAirport = _airports->getAirportByID(destination);
            double destLatitude = destAirport->latit;
            double destLongitude = destAirport->longit;
            double distance = getDistance(sourceLatitude, sourceLongitude, destLatitude, destLongitude);
            _edgeList[label].push_back(id);
            _airlineMap.insertEdge(to_string(source), to_string(destination));
            _airlineMap.setEdgeLabel(to_string(source), to_string(destination), "1");
            _airlineMap.setEdgeWeight(to_string(source), to_string(destination), distance);
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

vector<int> AirlineFlow::getAirlineBetweenAirports(string sourceIATA, string destIATA) {
    int sourceAirportID = _airports->getAirportIDByIATA(sourceIATA);
    int destAirportID = _airports->getAirportIDByIATA(destIATA);
    string label = to_string(sourceAirportID) + "_" + to_string(destAirportID);
    auto res = _edgeList.find(label);
    if (res == _edgeList.end()) return vector<int>();
    return res->second;
}
