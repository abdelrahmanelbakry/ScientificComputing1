#include "linearregression.h"

LinearRegression::LinearRegression()
{

}

LinearRegression::LinearRegression(vector<Point> points)
{
    points_ = points;
}
LinearRegression::~LinearRegression()
{
    //that is going to clear all the data used
    points_.clear();
}
vector<Point> LinearRegression::getFitPoints()
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
void LinearRegression::applyFittingTechnique()
{
    //As The algorithm can't run on less than two points.
    //P.S.: In case we have less than 3 points we won't
    //      calculate the standard deviation of the line as it needs at least three points.
    if(points_.empty() || points_.size()<2)
        return;
    double sumX=0,sumY=0,sumXY=0,sumX2=0;
    for(int i=0;i<points_.size();i++)
    {
        sumX+= points_[i].getX();
        sumY+= points_[i].getY();
        sumXY+= points_[i].getX() * points_[i].getY();
        sumX2+= points_[i].getX()* points_[i].getX();
    }

    double xMean = sumX/points_.size();
    double yMean = sumY/points_.size();

    a1 = (points_.size() * sumXY - sumX*sumY)/(points_.size()*sumX2- sumX*sumX);
    a0 = yMean - a1*xMean;

    ofstream log("log.txt",ios_base::app);

    lineMean_=0;
    residualError_=0;

    for(int i=0;i<points_.size();i++)
    {
        lineMean_+= (points_[i].getY() - yMean)*(points_[i].getY() - yMean);
        residualError_ += (points_[i].getY() - a1*points_[i].getX() - a0) * (points_[i].getY() - a1*points_[i].getX() - a0);
    }

    if(points_.size()>=3)
        lineStandardDeviation_= sqrt(residualError_/ (points_.size()-2) );

    correlationCofficient_ = (lineMean_ - residualError_) / lineMean_;

    log<<"Residual Error For Linear Reg: "<<residualError_<<endl;
    log<<"Correlation Co For Linear Reg: "<<correlationCofficient_<<endl;


}
