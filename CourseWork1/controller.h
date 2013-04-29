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


    public:
        static Controller* getSharedController();
        ~Controller();
        vector<Point> getInputPoints() { return inputPoints;}
        vector<Point> applyCurveFitting(Technique technique);
        void ReadInput(const char* filename);
};

#endif // CONTROLLER_H
