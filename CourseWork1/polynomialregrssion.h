#ifndef POLYNOMIALREGRSSION_H
#define POLYNOMIALREGRSSION_H
#include<math.h>
#include<fstream>

#include "gaussmatsolverwithpp.h"
#include"cmatrix.h"
#include"ifittingtechnique.h"

using namespace std;

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
    cVector<double>* xVec;
    iMatrixSolver<double>* matrixSolver_;
    int degree_;
    vector<Point> points_;
    double residualError_;
    double lineMean_;
    double lineStandardDeviation_;
    double correlationCofficient_;

};

#endif // POLYNOMIALREGRSSION_H
