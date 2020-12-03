#include "airports.h"
#include <fstream>  
#include <unordered_map>
#include "utils.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_map;
using utils::readEntry;

void Airports::init() {
    _map.clear();
    ifstream infile("data/airports.dat");  
    string line;
    // handle error
    if (!infile.is_open()) {
        cout << "can not open the file \n"<<endl;
        exit(1);
    }
    // loop through dat by lines
    while(getline(infile,line)) {  
        vector<string> in = readEntry(line); 
        int id = std::stoi(in[0]);
        //cout << id << endl;
        string name = in[1];
        string city = in[2];
        string country = in[3];
        string IATA = in[4];
        string ICAO = in[5];
        double latit = std::stod(in[6]);
        double longit = std::stod(in[7]);
        int alt = std::stoi(in[8]);
        string timeZone = in[9];
        string DST = in[10];
        string tz = in[11];
        AirportNode* data = new AirportNode(name, city, country, IATA, ICAO, latit, longit,
            alt, timeZone, DST, tz);
        _map[id] = data;
    }
    infile.close();
}

Airports::AirportNode* Airports::getAirportByID(int id) {
    return _map[id];
}