#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>

using std::vector;
using std::string;
using std::unordered_map;

// for planes.dat
class Planes {
    public:
        /**
         * Interal storage element for all entries in planes.dat
         */
        class PlanesNode {
            public:
                /** 
                 * Constructs one storage element
                 * @param name full name of the aircraft ex: Aerospatiale (Nord) 262
                 * @param IATA unique three-letter IATA identifier for aircraft ex: ND2
                 * @param ICAO unique four-letter IXAO identifier for aircraft ex: N262
                 */
                PlanesNode(string name, string ICAO) : 
                    name(name), ICAO(ICAO) {};

                /* All the data should be constant */
                const string name;
                //const string IATA;
                const string ICAO;

        };

        /**
         * Initialzation of all planes data
         * @param filename the name of the file to read
         */
        Planes();

        /** 
         * Get the internal storage element by the plane id specified
         * @param id the ID of the airline
         */
        PlanesNode* getPlaneByIATA(string IATA);

    private:
        /* Internal storage that holds all the plane infomation */
        unordered_map<string, PlanesNode*> _map;
};