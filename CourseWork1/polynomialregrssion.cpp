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
    for(int i=0;i<points_.size();i++)
    {
        Point newPoint;
        newPoint.setX(points_[i].getX());
        newPoint.setY( (a0 + a1*points_[i].getX()));
        fitPoints.push_back(newPoint);
    }
    return fitPoints;
}
void PolynomialRegrssion::applyFittingTechnique()
{
    //As The algorithm can't run on less than the number of points.

    if(points_.empty() || points_.size()<degree_)
        return;

    solutionMatrix_ = new cMatrix<double>(degree_,degree_+1,0.0);
    double sum=0;
    for(int i=0;i<degree_;i++)
    {
        for(int j=0;j<i;j++)
        {
            double k = i+j-2;
            for(int l=0;i<points_.size();l++)
                sum+= pow(points_[l].getX(),k);
            solutionMatrix_->modifyCellValue(i,j,sum);
            solutionMatrix_->modifyCellValue(j,i,sum);
        }
        sum=0;
        for(int l=0;l<points_.size();l++)
            sum+= (points_[l].getY() * pow(points_[l].getX(),i-1));

        solutionMatrix_->modifyCellValue(i,degree_+2,sum);
    }
}
