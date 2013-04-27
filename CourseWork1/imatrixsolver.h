#ifndef IMATRIXSOLVER_H
#define IMATRIXSOLVER_H

#include "cvector.h"
#include "cmatrix.h"
template <class T>
class iMatrixSolver
{
public:
    virtual cVector<T> solve(cMatrix<T> *matrix, double tolerance,double error)=0;
};

#endif // IMATRIXSOLVER_H
