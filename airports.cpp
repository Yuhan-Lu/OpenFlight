#include "airports.h"
#include <fstream>  
#include <unordered_map>
#include <iostream>
#include "utils.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_map;
using std::stod;
using std::stoi;
using utils::readEntry;

Airports::Airports(bool test) {
    _map.clear();
    string filein = test ? "testData/airports.dat" : "data/airports.dat";
    ifstream infile(filein); 
    string line;
    // handle error
    if (!infile.is_open()) {
        cout << "can not open the file \n"<<endl;
        exit(1);
    }
    // loop through dat by lines
    while(getline(infile,line)) {  
        vector<string> in = readEntry(line); 
        int id = stoi(in[0]);
        string name = in[1];
        string city = in[2];
        string country = in[3];
        string IATA = in[4];
        string ICAO = in[5];
        double latit = stod(in[6]);
        double longit = stod(in[7]);
        int alt = stoi(in[8]);
        string timeZone = in[9];
        string DST = in[10];
        string tz = in[11];
        AirportNode* data = new AirportNode(name, city, country, IATA, ICAO, latit, longit,
            alt, timeZone, DST, tz);
        _map[id] = data;
        _IATAToID[IATA] = id;
    }
    infile.close();
}

Airports::AirportNode* Airports::getAirportByID(int id) {
    return _map[id];
}

int Airports::getAirportIDByIATA(string IATA) {
    return _IATAToID[IATA];
}