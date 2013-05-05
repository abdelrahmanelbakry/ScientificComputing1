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
        double yVal=0;
<<<<<<< HEAD
        int p=1;
        for(int j=0;j<degree_+1;j++,p++)
            yVal += xVec->getValueAtIndex(j)* pow(points_[i].getX(),p);
=======
        //int p=1;
        for(int j=0;j<degree_+1;j++)//,p++)
            yVal += xVec->getValueAtIndex(j)* pow(points_[i].getX(),j);
>>>>>>> Beta Version

        newPoint.setY(yVal);
        fitPoints.push_back(newPoint);
    }
    return fitPoints;
}
void PolynomialRegrssion::applyFittingTechnique()
{
    //As The algorithm can't run on less than the number of points.

    if(points_.empty() || points_.size()<degree_+1)
        return;

    double sumY=0;
    for(int i=0;i<points_.size();i++)
        sumY+= points_[i].getY();


    double yMean = sumY/points_.size();

    solutionMatrix_ = new cMatrix<double>(degree_+1,degree_+1,0.0);
    double sum=0;
    cVector<double>* bVec = new cVector<double>(degree_+1,0.0);

    for(int i=1;i<=degree_+1;i++)
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

    residualError_=0;
    lineMean_=0;
    ofstream log("log.txt",ios_base::app);
    log<<solutionMatrix_->toString()<<endl;

    matrixSolver_ = new GaussMatSolverWithPP<double>();

    xVec = new cVector<double> (degree_+1,0.0);
    log<<bVec->getValueAtIndex(0)<<" "<<bVec->getValueAtIndex(1)<<" "<<bVec->getValueAtIndex(2)<<endl;

    double error=0;
    matrixSolver_->solve(solutionMatrix_,bVec,xVec,0.0001,&error);

    log<<xVec->getValueAtIndex(0)<<" "<<xVec->getValueAtIndex(1)<<" "<<xVec->getValueAtIndex(2)<<endl;

    for(int i=0;i<points_.size();i++)
    {
        double yVal=0;
<<<<<<< HEAD
        int p=1;
        for(int j=0;j<degree_+1;j++,p++)
            yVal += xVec->getValueAtIndex(j)* pow(points_[i].getX(),p);
=======
        //int p=1;
        for(int j=0;j<degree_+1;j++)//,p++)
            yVal += xVec->getValueAtIndex(j)* pow(points_[i].getX(),j);
>>>>>>> Beta Version

        log<<"Error for point: "<<(points_[i].getY() - yVal)<<endl;
        residualError_ +=  ((points_[i].getY() - yVal) * (points_[i].getY() - yVal));
        lineMean_+= (points_[i].getY() - yMean)*(points_[i].getY() - yMean);

    }
    if(points_.size()>=3)
        lineStandardDeviation_= sqrt(residualError_/ (points_.size()-(degree_+1)) );

    correlationCofficient_ = (lineMean_ - residualError_) / lineMean_;

    log<<"Residual Error For Poly Reg: "<<residualError_<<endl;
    log<<"Correlation Co For Poly Reg: "<<correlationCofficient_<<endl;

}
