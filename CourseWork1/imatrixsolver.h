#ifndef IMATRIXSOLVER_H
#define IMATRIXSOLVER_H

#include "cvector.h"
#include "cmatrix.h"
template <class T>
class iMatrixSolver
{
public:
    virtual void solve(cMatrix<T> *matrix,cVector<T> *bVec,cVector<T>* xVec, double tolerance,double *error)=0;
};

#endif // IMATRIXSOLVER_H
