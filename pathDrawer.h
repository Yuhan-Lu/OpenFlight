#include "cs225/PNG.h"
#include "cs225/graph.h"
#include "airlineFlow.h"
#include <unordered_map>

using std::pair;
using std::vector;
using std::string;
using std::unordered_map;
using cs225::PNG;
using cs225::HSLAPixel;

class PathDrawer {
    public:
        PathDrawer(Airports* _airports);

        void addPath(vector<Vertex> list, const HSLAPixel& renderPixel);

        void addPath(Vertex from, Vertex to, const HSLAPixel& renderPixel);

        PNG* renderPath();

    private:

        PNG* _drawLine(PNG* canvas, int x1, int y1, int x2, int y2, HSLAPixel& renderPixel);
    
        Airports* _airports;

        PNG* _canvas;

        pair<int, int> _center;

        pair<double, double> _pixelPerDegree;

        unordered_map<string, HSLAPixel> _pathList;
        
};