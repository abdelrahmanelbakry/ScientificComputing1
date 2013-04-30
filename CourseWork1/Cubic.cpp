#include "cvector.h"
#include "cmatrix.h"

cVector<double> function01 (double XX)
{
    cVector<double> result = cVector<double> (4);
    result[0] = XX * XX * XX;
    result[1] = XX * XX;
    result[2] = XX;
    result[3] = 1;
    return result;
}

cVector<double> function02 (double XX)
{
    cVector<double> result = cVector<double> (4);
    result[0] = 3* (XX *XX);
    result[1] = 2* XX;
    result[2] = 1;
    result[3] = 0;
    return result;
}

cVector<double> function03 (double XX)
{
    cVector<double> result = cVector<double> (4);
    result[0] = 6 * XX;
    result[1] = 2;
    result[2] = 0;
    result[3] = 0;
    return result;
}

void  CubicSpline (int Sample_Size, cVector <double> X, cVector <double> Y, cMatrix <double> *Main_Matrix)
{
// Construct J_Start, J_End,  X_Index
        int nn = X.size() -1;
        cVector <int> J_Start = cVector<int> (4*nn);
        cVector <int> J_End = cVector<int> (4*nn);
        cVector <int> X_Index = cVector<int> (4*nn);
        cVector <double> Var_Vector = cVector <double> (4);
// Create Y & X_index
        X_Index [4*nn-2] = 0;
        X_Index [4*nn-1] = nn;
        J_Start [4*nn-2] = 0;
        J_End [4*nn-2] = 4;
        J_Start [4*nn-1] = 4*nn-4;
        J_End [4*nn-1] = 4*nn;
        for (int i=0; i< 4*nn ; i++)
        {
            if (i==0)
            {
                Main_Matrix->modifyCellValue (i,4*nn,Y[0]);
                X_Index [i] = 0;
                J_Start [i] = 0;
                J_End [i] = 4;
            }
            if (i==1)
            {
                Main_Matrix->modifyCellValue (i,4*nn,Y[1]);
                X_Index [i] = 1;
                J_Start [i] = 0;
                J_End [i] = 4;
            }
            if ( i>1 && i<(2*nn))
            {
            X_Index [i] = X_Index [i-2] +1;
            Main_Matrix->modifyCellValue (i,4*nn, Y[X_Index [i]]);
            J_Start [i] = J_Start [i-2]+4;
            J_End [i] = J_End [i-2] +4;
            }
            if (i ==2*nn || i==3*nn-1)
            {
                X_Index [i] = 1;
                J_Start [i] = 0;
                J_End [i] = 4;
            }
            if ((i > 2*nn && i <3*nn-1)||(i > 3*nn-1 && i <4*nn-2))
            {
                X_Index [i] = X_Index [i-1] + 1;
                J_Start [i] = J_Start[i-1]+4;
                J_End [i] = J_End [i-1]+4;
            }

        }
// Last Two Rows
        Var_Vector = function03(X[0]);
        for ( int j= J_Start [4*nn-2]; j < J_End [4*nn-2] ; j++)
        {
            Main_Matrix->modifyCellValue (4*nn-2,j,Var_Vector[j-J_Start[4*nn-2]]);
        }
        Var_Vector = function03(X[nn]);
        for ( int j= J_Start [4*nn-1]; j < J_End [4*nn-1] ; j++)
        {
            Main_Matrix->modifyCellValue (4*nn-1,j,Var_Vector[j-J_Start[4*nn-1]]);
        }
// Evaluate Matrix Element
        for (int i=0; i< 4*nn ; i++)
        {
            if (i>=0 && i<2*nn)
            {
                Var_Vector = function01(X[ X_Index [i]]);
                for (  int j= J_Start [i]; j < J_End [i] ; j++)
                {
                    Main_Matrix->modifyCellValue (i,j,Var_Vector[j-J_Start[i]]);
                }
            }
            if ((i>=2*nn) && i<(3*nn-1))
            {
                    Var_Vector = function02(X[ X_Index [i]]);
                    for ( int j= J_Start [i]; j < J_End [i] ; j++)
                    {
                        Main_Matrix->modifyCellValue (i,j,Var_Vector[j-J_Start[i]]);
                        Main_Matrix->modifyCellValue (i, j+4,-Var_Vector[j-J_Start[i]] );
                    }

            }
            if (i>=(3*nn-1) && i<((4*nn)-2))
            {
                        Var_Vector = function03(X[ X_Index [i]]);
                        for ( int j= J_Start [i]; j < J_End [i] ; j++)
                        {
                            Main_Matrix->modifyCellValue (i,j,Var_Vector[j-J_Start[i]]);
                            Main_Matrix->modifyCellValue (i, j+4,-Var_Vector[j-J_Start[i]] );
                        }
             }
        }
}

