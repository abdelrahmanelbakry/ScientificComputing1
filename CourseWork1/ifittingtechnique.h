#ifndef IFITTINGTECHNIQUE_H
#define IFITTINGTECHNIQUE_H
#include<vector>
#include "Utils.h"

using namespace std;

class IFittingTechnique
{
public:
    virtual void applyFittingTechnique()=0;
    virtual vector<Point> getFitPoints()=0;

};

#endif // IFITTINGTECHNIQUE_H
