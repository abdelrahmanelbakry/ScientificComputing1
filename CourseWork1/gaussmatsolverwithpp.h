#ifndef GAUSSMATSOLVERWITHPP_H
#define GAUSSMATSOLVERWITHPP_H

#include <stdio.h>
#include <math.h>
#include "imatrixsolver.h"

template <class T>

class GaussMatSolverWithPP: public iMatrixSolver<T>
{
public:
    GaussMatSolverWithPP();

    cVector<T> solve(cMatrix<T> *matrix, double tolerance,double error)
    {
        cVector<T> * s = new cVector<T> (matrix->getNumberOfRows());
        error=0;
        for(int i=0;i<matrix->getNumberOfRows();i++)
        {
            s[i] = fabs(matrix->getCellValue(i,1));
            for(int j=1;j<matrix->getNumberOfRows();j++)
            {
                if(fabs(matrix->getCellValue(i,j)) > s[i])
                    s[i] = fabs(matrix->getCellValue(i,j));
            }
        }

    }

    //Elimination Procedure
    void eliminate()
    {

    }

    void Subsitute()
    {

    }

    void Pivot()
    {

    }

};

#endif // GAUSSMATSOLVERWITHPP_H
