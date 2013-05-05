#include "controller.h"
#include "Interpolation.cpp"
#include "Cubic.cpp"
#include "gaussmatsolverwithpp.h"
#include "imatrixsolver.h"

Controller* sharedController = 0;
Controller::Controller()
{
    fittechnique = 0;
}
Controller::~Controller()
{
    if(fittechnique!=0)
        delete fittechnique;

    delete sharedController;
    sharedController = 0;
}
Controller* Controller::getSharedController()
{
    if(sharedController == 0)
        sharedController = new Controller();
    return sharedController;
}
/*
void Controller::RunTest()
{
    ofstream log("log.txt");
    cVector<double> newVec = cVector<double>(3,6);
    log<<newVec[0]<<" "<<newVec[1]<<" "<<newVec[2]<<endl;
    cVector<double> newVec2 = cVector<double>(3,4);
    cVector<double> newVec3 = cVector<double>(3,2);

    //newVec = newVec2 = newVec3;
    log<<newVec2[0]<<" "<<newVec2[1]<<" "<<newVec2[2]<<endl;
    newVec[0]=7;
    newVec.resize(4);
    log<<newVec[0]<<" "<<newVec[1]<<" "<<newVec[2]<<" "<<newVec[3]<<endl;

    cMatrix<double> newMat = cMatrix<double>(3,3,10);
    log<<newMat.toString()<<endl;
   // char* log;

}*/

void Controller::ReadInput(const char *filename)
{
    inputPoints.clear();
    ifstream inputSream(filename);
    Point tmpPoint;
    int setSize;
    while(inputSream.good())
    {
        string line;
        getline(inputSream,line);
        if(line.find("#Number Of Points") != string::npos)
            inputSream>>setSize;
        if(line.find("#The Co-ordinates")!= string::npos)
        {
            for(int i=0;i<setSize;i++)
            {
                double xCord,yCord;
                inputSream>>xCord>>yCord;
                tmpPoint.setX(xCord);
                tmpPoint.setY(yCord);
                inputPoints.push_back(tmpPoint);
            }
        }
    }
    //qDebug(inputPoints.size());
}
vector<Point> Controller::applyCurveFitting(Technique technique, double degree)
{
    switch(technique)
    {
        case LINEAR_REG:
            if(fittechnique != 0) delete fittechnique;
            fittechnique = new LinearRegression(inputPoints);

            break;
        case POLY_REG:
            if(fittechnique != 0) delete fittechnique;
            fittechnique = new PolynomialRegrssion(inputPoints,degree);
            break;
        case POLY_REG:
            fittechnique = new PolynomialRegrssion(inputPoints,2);
            break;
    }

    fittechnique->applyFittingTechnique();
    return fittechnique->getFitPoints();
}


vector<Point> Controller::applyNewtonInterpol()
{
    cVector<double> Input_X = cVector<double> (inputPoints.size());
    cVector<double> Input_Y = cVector<double> (inputPoints.size());
    Point var_point;
    for (int i =0; i<inputPoints.size(); i++)
    {
       var_point = inputPoints[i];
       Input_X[i] = var_point.getX();
       Input_Y[i] = var_point.getY();
    }
    cVector<double> resultNewton = NewtonInterPolation (inputPoints.size(),Input_X,Input_Y );

    var_point = inputPoints[0];
    double X_start = var_point.getX();
    var_point = inputPoints[inputPoints.size()-1];
    double X_end = var_point.getX();
    double Interval =0.5;
    int count_X = ceil ((X_end-X_start )/Interval)+1;

    cVector<double> X_Plot = cVector<double> (count_X);
    cVector<double> Y_Plot = cVector<double> (count_X);
    X_Plot[0] = X_start;
    X_Plot[count_X -1] = X_end;
    for (int i=1; i<(count_X-1) ; i++)
    {
        X_Plot[i] = X_Plot[i-1] + Interval;
    }
    //Calculate Error
   // cVector <double> ErrorNewton = cVector<double> (inputPoints.size());


    // Calculate Y_Plot
    for (int i=0; i< X_Plot.size(); i++)
    {
        Y_Plot[i] = resultNewton[0];
        double varfactor = 1;
        for (int j=1; j< Input_X.size(); j++)
        {
            varfactor = varfactor * (X_Plot[i] - Input_X[j-1]);
            Y_Plot[i] = Y_Plot[i] + varfactor * resultNewton[j];
        }

    }
    //Calculate Error at each input point
    cVector <double> ErrorNewton = cVector<double> (inputPoints.size());
    ofstream log("log.txt",ios_base::app);

    for (int i=0; i< Input_X.size(); i++)
    {
        double Calculated = resultNewton[0];
        double varfactor = 1;
        for (int j=1; j< Input_X.size(); j++)
        {
            varfactor = varfactor * (X_Plot[i] - Input_X[j-1]);
            Calculated = Calculated + varfactor * resultNewton[j];
        }
<<<<<<< HEAD
        ErrorNewton [i] = Calculated - Input_X[i];
=======
        ErrorNewton [i] = Calculated - Input_Y[i];
>>>>>>> Beta Version
        log<<ErrorNewton[i]<<endl;
    }

    vector<Point> returnpoints = vector<Point>(count_X);
    for (int i=0; i<count_X ; i++)
    {
        var_point.setX(X_Plot[i]);
        var_point.setY(Y_Plot[i]);
        returnpoints[i] = var_point;
    }
 return returnpoints;

}

vector<Point> Controller::applyCubicSpline()
{
    cVector<double> Input_X = cVector<double> (inputPoints.size());
    cVector<double> Input_Y = cVector<double> (inputPoints.size());
<<<<<<< HEAD
    Point var_point;
=======
    ofstream log("log.txt",ios_base::app);
    log << "  inputPoint Size:" << inputPoints.size() << " End inputPoint size \n";
    Point var_point;
    log << "Guten Morgen!" ;
>>>>>>> Beta Version
    for (int i =0; i<inputPoints.size(); i++)
    {
       var_point = inputPoints[i];
       Input_X[i] = var_point.getX();
       Input_Y[i] = var_point.getY();
    }
    cMatrix<double> linear_equation_set = cMatrix<double> ( 4*(inputPoints.size()-1), 4*(inputPoints.size()-1) +1);
<<<<<<< HEAD
=======
    for (int i =0; i<4*(inputPoints.size()-1) ; i++)
    {
        for (int j=0 ; j<4*(inputPoints.size()-1) +1 ;j++)
        {
            linear_equation_set.modifyCellValue(i,j,0);
        }
    }
>>>>>>> Beta Version
    CubicSpline (inputPoints.size(), Input_X, Input_Y, &linear_equation_set );
//    Assume 4n Matrix is ready with coeffecients Result_Splines cVector<double>
//    Apply Matrix Solver
    //
<<<<<<< HEAD
=======

    // Test Result
    log << "We will display test results" ;
    for (int i = 0; i<4*(inputPoints.size()-1); i++)
    {
        for (int j=0 ; j<4*(inputPoints.size()-1) +1;j++)
        {
            log << " " << linear_equation_set.getCellValue(i,j);
        }
        log << "\n" ;
    }
    log << "End display test results" ;


>>>>>>> Beta Version
    cVector<double> Result_Splines = cVector<double> (4*(inputPoints.size()-1));
    cVector<double> bVec = cVector<double> (4*(inputPoints.size()-1));
    cMatrix<double> solutionMatrix_ = cMatrix<double> ( 4*(inputPoints.size()-1), 4*(inputPoints.size()-1) );
    for (int i=0; i<4*(inputPoints.size()-1); i++)
    {
        bVec[i] =linear_equation_set.getCellValue( i,4*(inputPoints.size()-1));
        for (int j=0;j<4*(inputPoints.size()-1);j++ )
        {
             solutionMatrix_ [i][j] = linear_equation_set.getCellValue( i,j);
        }
    }

    double error;
    GaussMatSolverWithPP<double> solverobject = GaussMatSolverWithPP<double>();
    solverobject.solve(&solutionMatrix_,&bVec,&Result_Splines,0.0001,&error);

//  for (int i=0; i<Result_Splines.size();i++)
//  Result_Splines[i] = 1;
//  Below was Tested & Okay
    var_point = inputPoints[0];
    double X_start = var_point.getX();
    var_point = inputPoints[inputPoints.size()-1];
    double X_end = var_point.getX();
<<<<<<< HEAD
    double Interval =0.5;
=======
    double Interval =0.1;
>>>>>>> Beta Version
    int count_X = ceil ((X_end-X_start )/Interval)+1;

    cVector<double> X_Plot = cVector<double> (count_X);
    cVector<double> Y_Plot = cVector<double> (count_X);
    X_Plot[0] = X_start;
    X_Plot[ count_X -1] = X_end;
    for (int i=1; i<(count_X-1) ; i++)
    {
        X_Plot[i] = X_Plot[i-1] + Interval;
    }
    // Obtain Y_Plot
    int g = 0;
    double X_compare = Input_X[g+1];
    for (int i=0; i<X_Plot.size(); i++)
    {
        Y_Plot[i] = Result_Splines[0+4*g]*pow(X_Plot[i],3)+ Result_Splines[1+4*g]*pow(X_Plot[i],2)+Result_Splines[2+4*g]*X_Plot[i]+Result_Splines[3+4*g];
        if( X_Plot[i] >X_compare)
        {
            g++;
            X_compare = Input_X[g+1];
        }
    }
<<<<<<< HEAD
/*
=======

>>>>>>> Beta Version
    // Calculate Error at each input point
    cVector <double> ErrorCubic = cVector<double> (inputPoints.size());

    g = 0;
    X_compare = Input_X[g+1];
    for (int i=0; i<Input_X.size(); i++)
    {
<<<<<<< HEAD
        ErrorCubic = Input_Y[i] - (Result_Splines[0+4*g]*pow(Input_X[i],3)+ Result_Splines[1+4*g]*pow(Input_X,2)+Result_Splines[2+4*g]*Input_X[i]+Result_Splines[3+4*g]);
=======
        ErrorCubic [i] = Input_Y[i] - (Result_Splines[0+4*g]*pow(Input_X[i],3)+ Result_Splines[1+4*g]*pow(Input_X[i],2)+Result_Splines[2+4*g]*Input_X[i]+Result_Splines[3+4*g]);
>>>>>>> Beta Version
        if( X_Plot[i] >X_compare)
        {
            g++;
            X_compare = Input_X[g+1];
        }
<<<<<<< HEAD
    }*/
=======
    }
>>>>>>> Beta Version

 vector<Point> returnpoints = vector<Point>(count_X);
 for (int i=0; i<count_X ; i++)
 {
   var_point.setX(X_Plot[i]);
   var_point.setY(Y_Plot[i]);
   returnpoints[i] = var_point;
 }
 return returnpoints;
}
<<<<<<< HEAD
=======



>>>>>>> Beta Version
