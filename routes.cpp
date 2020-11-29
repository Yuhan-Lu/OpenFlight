#include "routes.h"
#include <fstream>  
#include <unordered_map>
#include "utils.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_map;
using utils::split;
using utils::strip;

void Routes::init() {
    _map.clear();
    ifstream infile("data/routes.dat");  
    string line;
    // handle error
    if (!infile.is_open()) {
        cout << "can not open the file \n"<<endl;
        exit(1);
    }
    // loop through dat by lines
    while(getline(infile,line)) {  
        vector<string> in = split(line, ','); 
        string airline = strip(in[0]);
        int airlineID = std::stoi(in[1]);
        string airport1 = strip(in[2]);
        int airportID1 = std::stoi(in[3]);
        string airport2 = strip(in[4]);
        int airportID2 = std::stoi(in[5]);
        bool codeshare = in[6] == "Y";
        int stops = std::stoi(in[7]);
        string equipment = strip(in[8]);
        RoutesNode* data = new RoutesNode(airline,airport1,airportID1,airport2,airportID2,codeshare,stops,equipment);
        _map[airlineID] = data;
    }
    infile.close();
}

Routes::RoutesNode* Routes::getAirlineByID(int id) {
    //cout<< getAirlineByID(5);
    return _map[id];
}
