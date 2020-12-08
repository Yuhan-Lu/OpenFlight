#include "getDistance.h"
#include <math.h>

using namespace std;

double FinalProject::getDistance(double latitude1, double longtitude1, double latitude2, double longtitude2) {
    double lati1 = latitude1;
    double long1 = longtitude1;
    double lati2 = latitude2;
    double long2 = longtitude2;

    //toRadian  lat = latitude / 180 * pi long = longt / 180 *pi
    double latiR1 = lati1/180*M_PI;
    double latiR2 = lati2/180*M_PI;
    double longR1 = long1/180*M_PI;
    double longR2 = long2/180*M_PI;

    double latiDiff = latiR2 - latiR1;
    double longDiff = longR2 - longR1;

    double part1 = pow(sin(latiDiff/2), 2) + pow(sin(longDiff / 2), 2)*cos(latiR1) * cos(latiR2); 
    //6371 is the radian of earth in km
    double result = 2 * asin(sqrt(part1))* 6371;

    return result;

}





