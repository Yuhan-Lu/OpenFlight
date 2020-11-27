#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;
// for airlines.dat
class airlines {
    public:

        airlines(int airlineID, string name, string alias, string IATA, 
        string ICAO, string callsign, string country, string active);
        // load DAT as a map
        void loadData(string fileName);

         
    private:
        int airlineID;
        string name;
        string alias;
        string IATA;
        string ICAO;
        string callsign;
        string country;
        string active;

        //map<int, airlines> airlinesDAT; 

        // void _split(const string &s, char delim, vector<string> &elems) {
        //     stringstream ss(s);
        //     string item;

        //     while (getline(ss, item, delim)) {
        //         elems.push_back(item);
        //     }
        // }
       
        vector<string> split(string &s, char delim);
        void _split(string &s, char delim, vector<string> &elems);

};

