#ifndef CONTROLLER_H
#define CONTROLLER_H

#include<iostream>
#include <QDebug>
#include<fstream>

#include "cmatrix.h"
#include "cvector.h"
#include "linearregression.h"
#include "polynomialregrssion.h"

using namespace std;

enum Technique { LINEAR_REG,POLY_REG,NEWTON,CUBIC_SPLINE};
class Controller
{
    private:
        Controller();
        vector<Point> inputPoints;
        IFittingTechnique* fittechnique;

        void RunTest();
    public:
        static Controller* getSharedController();
        ~Controller();
        vector<Point> getInputPoints() { return inputPoints;}
<<<<<<< HEAD
        vector<Point> applyCurveFitting(Technique technique);
=======
        vector<Point> applyCurveFitting(Technique technique,double degree=0);
>>>>>>> Beta Version
        vector<Point> applyNewtonInterpol();
        vector<Point> applyCubicSpline();
        void ReadInput(const char* filename);
};

#endif // CONTROLLER_H
