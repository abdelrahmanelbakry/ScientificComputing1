#include "polynomialregrssion.h"

PolynomialRegrssion::PolynomialRegrssion()
{
}
PolynomialRegrssion::PolynomialRegrssion(vector<Point> points,int degree)
{
    points_ = points;
    degree_ = degree;
}
PolynomialRegrssion::~PolynomialRegrssion()
{
    //that is going to clear all the data used
    points_.clear();
    delete solutionMatrix_;
}
vector<Point> PolynomialRegrssion::getFitPoints()
{

    vector<Point> fitPoints;
    /*for(int i=0;i<points_.size();i++)
    {
        Point newPoint;
        newPoint.setX(points_[i].getX());
        newPoint.setY( (a0 + a1*points_[i].getX()));
        fitPoints.push_back(newPoint);
    }*/
    return fitPoints;
}
void PolynomialRegrssion::applyFittingTechnique()
{
    //As The algorithm can't run on less than the number of points.

    if(points_.empty() || points_.size()<degree_)
        return;

    solutionMatrix_ = new cMatrix<double>(degree_,degree_,0.0);
    double sum=0;
    cVector<double>* bVec = new cVector<double>(degree_,0.0);

    for(int i=1;i<degree_+1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            double k = i+j-2;
            sum=0;
            for(int l=0;l<points_.size();l++)
                sum+= pow(points_[l].getX(),k);
            solutionMatrix_->modifyCellValue(i-1,j-1,sum);
            solutionMatrix_->modifyCellValue(j-1,i-1,sum);
        }
        sum=0;
        for(int l=0;l<points_.size();l++)
            sum+= (points_[l].getY() * pow(points_[l].getX(),i-1));

        bVec->setValueAtIndex(i-1, sum);
       // solutionMatrix_->modifyCellValue(i,degree_+2,sum);
    }
    double error=0;

    ofstream log("log.txt",ios_base::app);
    log<<solutionMatrix_->toString()<<endl;

    matrixSolver_ = new GaussMatSolverWithPP<double>();

    cVector<double>* xVec = new cVector<double> (degree_,0.0);
    log<<bVec->getValueAtIndex(0)<<" "<<bVec->getValueAtIndex(1)<<" "<<bVec->getValueAtIndex(2)<<endl;

    matrixSolver_->solve(solutionMatrix_,bVec,xVec,0.0001,&error);

    log<<xVec->getValueAtIndex(0)<<" "<<xVec->getValueAtIndex(1)<<" "<<xVec->getValueAtIndex(2)<<endl;


}
