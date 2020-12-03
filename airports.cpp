#include "airlines.h"
#include <fstream>  
#include <unordered_map>
#include "utils.h"

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_map;
using utils::readEntry;

void Airlines::init() {
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
        int id = std::stoi(in[0]);
        string name = in[1];
        string alias = in[2];
        string IATA = in[3];
        string ICAO = in[4];
        string callsign = in[5];
        string country = in[6];
        bool active = in[7] == "Y";
        AirlineNode* data = new AirlineNode(name, alias, IATA, ICAO, callsign, country, active);
        _map[id] = data;
    }
    infile.close();
}

Airlines::AirlineNode* Airlines::getAirlineByID(int id) {
    return _map[id];
}