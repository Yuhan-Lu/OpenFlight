#include "routes.h"
#include <fstream>  
#include <unordered_map>
#include "utils.h"
#include <iostream>

using std::cout;
using std::endl;
using std::ifstream;
using std::unordered_map;
using std::stoi;
using utils::readEntry;

Routes::Routes() {
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
        vector<string> in = readEntry(line); 
        string airline = in[0];
        int airlineID = stoi(in[1]);
        string airport1 = in[2];
        int airportID1 = stoi(in[3]);
        string airport2 = in[4];
        int airportID2 = stoi(in[5]);
        bool codeshare = in[6] == "Y";
        int stops = stoi(in[7]);
        string equipment = in[8];
        RoutesNode* data = new RoutesNode(airline,airport1,airportID1,airport2,airportID2,codeshare,stops,equipment);
        _map[airlineID] = data;
    }
    infile.close();
}

Routes::RoutesNode* Routes::getAirlineByID(int id) {
    //cout<< getAirlineByID(5);
    return _map[id];
}
