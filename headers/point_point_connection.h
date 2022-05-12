#include <vector>
#include "node.h"
class PointPointConnection{
    protected:
        double max_bandwith;
        double used_bandwith;
        Node *src;
        Node *dst;
    public:

    double getAvailibleBandwith();
};