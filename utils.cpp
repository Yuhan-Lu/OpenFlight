#include "utils.h"
#include <algorithm>
#include <iostream>

using std::cout;
using std::stringstream;
using std::remove;

namespace utils {
    vector<string> readEntry(string &s) {
        string item;
        vector<string> elems;
        string::iterator it = s.begin();
        while (it != s.end()) {
            if (*it == '\"') {
                while (++it != s.end()) {
                    if (*it == '\"') break;
                    item.push_back(*it);
                }
            } else {
                while (it != s.end()) {
                    if (*it == ',') break;
                    item.push_back(*it++);
                }
                if (item == "\\N") elems.push_back("");
                else elems.push_back(item);
                item.clear();
            }
            ++it;
        }
        elems.push_back(item);
        return elems;
    }

    double getDistance(double latitude1, double longtitude1, double latitude2, double longtitude2) {
        /**
         * Change to Radian  
         * lat = latitude / 180 * pi 
         * long = longt / 180 *pi
         */
        double latiR1 = latitude1 / 180 * M_PI;
        double latiR2 = latitude2 / 180 * M_PI;
        double longR1 = longtitude1 / 180 * M_PI;
        double longR2 = longtitude2 / 180 * M_PI;

        double latiDiff = latiR2 - latiR1;
        double longDiff = longR2 - longR1;

        double part1 = pow(sin(latiDiff / 2), 2) + pow(sin(longDiff / 2), 2) * cos(latiR1) * cos(latiR2); 
        //6371 is the radian of earth in km
        return 2 * asin(sqrt(part1)) * 6371;
    }
}