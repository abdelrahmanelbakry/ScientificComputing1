#ifndef GAUSSMATSOLVERWITHPP_H
#define GAUSSMATSOLVERWITHPP_H

#include <stdio.h>
#include <math.h>
#include "imatrixsolver.h"

template <class T>

class GaussMatSolverWithPP: public iMatrixSolver<T>
{
public:
    GaussMatSolverWithPP()
    {

    }

    void solve(cMatrix<T> *matrix,cVector<T> *bVec,cVector<T>* xVec, double tolerance,double *error)
    {
        cVector<T> * s = new cVector<T> (matrix->getNumberOfRows());

       // log<<matrix->toString()<<endl;
        ofstream log("log.txt",ios_base::app);
        log<<bVec->getValueAtIndex(0)<<endl;

        *(error)=0;
        for(int i=0;i<matrix->getNumberOfRows();i++)
        {
            s->setValueAtIndex(i, fabs(matrix->getCellValue(i,1)));
            for(int j=1;j<matrix->getNumberOfRows();j++)
            {
                T val = fabs(matrix->getCellValue(i,j));
                T val2 = s->getValueAtIndex(i);
                if( val > val2)
                    s->setValueAtIndex(i , fabs(matrix->getCellValue(i,j)));
            }
        }
        eliminate(matrix,s,bVec,tolerance,error);
        if(*(error)!=-1)
            Subsitute(matrix,bVec,xVec);
    }

    //Elimination Procedure
    void eliminate(cMatrix<T> *matrix, cVector<T> * s,cVector<T> *bVec, double tolerance,double *error)
    {
        for(int k=0;k<matrix->getNumberOfRows()-1;k++)
        {
            Pivot(matrix,s,bVec,k);


            if(fabs(matrix->getCellValue(k,k)/s->getValueAtIndex(k)) < tolerance)
            {
                *(error)-=1;
                break;
            }

            for(int i=k+1;i<matrix->getNumberOfRows();i++)
            {
                double factor = matrix->getCellValue(i,k) / matrix->getCellValue(k,k);
                for(int j=k+1;j<matrix->getNumberOfRows();j++)
                {
                    double newVal = matrix->getCellValue(i,j) - factor* matrix->getCellValue(k,j);
                    matrix->modifyCellValue(i,j,newVal);
                }
                bVec->setValueAtIndex(i,bVec->getValueAtIndex(i) -factor*bVec->getValueAtIndex(k));
            }
            if(fabs(matrix->getCellValue(k,k)/s->getValueAtIndex(k)) < tolerance)
                *(error)-=1;
        }
        //(fabs(matrix->getCellValue(k,k)))
    }

    void Subsitute(cMatrix<T> *matrix,cVector<T> *bVec,cVector<T>* xVec)
    {
//        xVec[matrix->getNumberOfRows()-1] = bVec->getValueAtIndex(matrix->getNumberOfRows()-1)/ matrix->getCellValue(matrix->getNumberOfRows()-1,matrix->getNumberOfRows()-1);
        ofstream log("log.txt",ios_base::app);

        log<<bVec->getValueAtIndex(matrix->getNumberOfRows()-1)<<endl;
        log <<bVec->getValueAtIndex(matrix->getNumberOfRows()-1)/ matrix->getCellValue(matrix->getNumberOfRows()-1,matrix->getNumberOfRows()-1)<<endl;
        for(int i= matrix->getNumberOfRows()-1 ; i>=0;i--)
        {
            double sum=0;
            for(int j=i+1;j<matrix->getNumberOfRows();j++)
                sum+= matrix->getCellValue(i,j)* xVec->getValueAtIndex(j);

            xVec->setValueAtIndex(i,(bVec->getValueAtIndex(i) - sum)/matrix->getCellValue(i,i));
        }
        log<<matrix->toString()<<endl;
        log<<xVec->getValueAtIndex(0)<<" "<<xVec->getValueAtIndex(1)<<" "<<xVec->getValueAtIndex(2)<<endl;
    }

    void Pivot(cMatrix<T> *matrix, cVector<T> * s,cVector<T> *bVec,int k)
    {
        int p=k;
        double dummy;
        double big = fabs(matrix->getCellValue(k,k)/s->getValueAtIndex(k));
        for(int ii=k+1;ii<matrix->getNumberOfRows();ii++)
        {
            dummy = fabs(matrix->getCellValue(ii,k)/s->getValueAtIndex(ii));
            if(dummy > big)
            {
                big = dummy;
                p=ii;
            }
        }

        if(p!=k)
        {
            for(int jj=k;jj<matrix->getNumberOfRows();jj++)
            {
               dummy = matrix->getCellValue(p,jj);
               matrix->modifyCellValue(p,jj, matrix->getCellValue(k,jj));
               matrix->modifyCellValue(k,jj,dummy);
            }

            dummy = bVec->getValueAtIndex(p);
            bVec->setValueAtIndex( p , bVec->getValueAtIndex(k));
            bVec->setValueAtIndex(k,dummy);

            dummy = s->getValueAtIndex(p);
            s->setValueAtIndex(p, s->getValueAtIndex(k));
            s->setValueAtIndex(k , dummy);
        }
    }

};

#endif // GAUSSMATSOLVERWITHPP_H
