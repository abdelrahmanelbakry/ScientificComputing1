#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include<vector>
#include<math.h>
#include "Utils.h"

using namespace std;

class LinearRegression
{
    public:
        LinearRegression();
        LinearRegression(vector<Point> points);
        ~LinearRegression();

        void applyFittingTechnique();

        vector<Point> getPoints() { return points_;}
        void setPoints(vector<Point> points) { points_ = points;}

    private:
        vector<Point> points_;
        double residualError_;
        double lineMean_;
        double lineStandardDeviation_;
        double correlationCofficient_;
        double a1,a0;
};

#endif // LINEARREGRESSION_H
