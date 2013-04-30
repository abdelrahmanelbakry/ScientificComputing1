#ifndef NEWTONINTERPOLATION_H
#define NEWTONINTERPOLATION_H

#include "ifittingtechnique.h"

class NewtonInterpolation :public IFittingTechnique
{
public:
    NewtonInterpolation();

    NewtonInterpolation(vector<Point> points);
    ~NewtonInterpolation();

    void applyFittingTechnique();
    vector<Point> getFitPoints();
    vector<Point> getPoints() { return points_;}
    void setPoints(vector<Point> points) { points_ = points;}

private:
    vector<Point> points_;
};

#endif // NEWTONINTERPOLATION_H
