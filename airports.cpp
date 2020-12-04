#include "airlines.h"
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

Airports::Airports() {
    _map.clear();
    ifstream infile("data/airlines.dat");  
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
    }
    infile.close();
}

Airlines::AirlineNode* Airlines::getAirlineByID(int id) {
    return _map[id];
}