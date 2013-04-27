#ifndef POLYNOMIALREGRSSION_H
#define POLYNOMIALREGRSSION_H
#include<math.h>
#include"cmatrix.h"
#include"ifittingtechnique.h"

class PolynomialRegrssion : public IFittingTechnique
{
public:
    PolynomialRegrssion();
    PolynomialRegrssion(vector<Point> points,int degree);
    ~PolynomialRegrssion();

    void applyFittingTechnique();
    vector<Point> getFitPoints();
    vector<Point> getPoints() { return points_;}
    void setPoints(vector<Point> points) { points_ = points;}
    void setDegree(int value) {degree_ =value;}
    int getDegree() { return degree_; }
private:
    cMatrix<double> * solutionMatrix_;
    int degree_;
    vector<Point> points_;
    double residualError_;
    double lineMean_;
    double lineStandardDeviation_;
    double correlationCofficient_;
    double a1,a0;
};

#endif // POLYNOMIALREGRSSION_H
