#include "cvector.h"
#include "cmatrix.h"

<<<<<<< HEAD
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
=======
void function01 (double XX , cVector<double> *function_Vector)
{
    function_Vector->setValueAtIndex(0,XX * XX * XX);
    function_Vector->setValueAtIndex(1,XX * XX);
    function_Vector->setValueAtIndex(2,XX);
    function_Vector->setValueAtIndex(3,1);
}

void function02 (double XX , cVector<double> *function_Vector)
{
    function_Vector->setValueAtIndex(0,3*(XX *XX));
    function_Vector->setValueAtIndex(1,2* XX);
    function_Vector->setValueAtIndex(2,1);
    function_Vector->setValueAtIndex(3,0);
}

void function03 (double XX , cVector<double> *function_Vector)
{
    function_Vector->setValueAtIndex(0,6 * XX);
    function_Vector->setValueAtIndex(1,2);
    function_Vector->setValueAtIndex(2,0);
    function_Vector->setValueAtIndex(3,0);
>>>>>>> Beta Version
}

void  CubicSpline (int Sample_Size, cVector <double> X, cVector <double> Y, cMatrix <double> *Main_Matrix)
{
<<<<<<< HEAD
// Construct J_Start, J_End,  X_Index
        int nn = X.size() -1;
=======

// Construct J_Start, J_End,  X_Index
        int nn = X.size() -1;
        ofstream log("log2.txt",ios_base::app);
        log << "    n = " << nn;
>>>>>>> Beta Version
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
<<<<<<< HEAD
            if (i==0)
            {
                Main_Matrix->modifyCellValue (i,4*nn,Y[0]);
=======

            if (i==0)
            {
                Main_Matrix->modifyCellValue (i,4*nn,Y[0]);
                //log << "   Y Value at i=0:" << Y[0];
>>>>>>> Beta Version
                X_Index [i] = 0;
                J_Start [i] = 0;
                J_End [i] = 4;
            }
            if (i==1)
            {
                Main_Matrix->modifyCellValue (i,4*nn,Y[1]);
<<<<<<< HEAD
=======
                //log << "   Y Value at i=1::" << Y[1];
>>>>>>> Beta Version
                X_Index [i] = 1;
                J_Start [i] = 0;
                J_End [i] = 4;
            }
            if ( i>1 && i<(2*nn))
            {
            X_Index [i] = X_Index [i-2] +1;
            Main_Matrix->modifyCellValue (i,4*nn, Y[X_Index [i]]);
<<<<<<< HEAD
=======
            //log << "   Y Value at other:" << Y[X_Index [i]];
>>>>>>> Beta Version
            J_Start [i] = J_Start [i-2]+4;
            J_End [i] = J_End [i-2] +4;
            }
            if (i ==2*nn || i==3*nn-1)
            {
                X_Index [i] = 1;
                J_Start [i] = 0;
                J_End [i] = 4;
<<<<<<< HEAD
=======
                Main_Matrix->modifyCellValue (i,4*nn, 0);
>>>>>>> Beta Version
            }
            if ((i > 2*nn && i <3*nn-1)||(i > 3*nn-1 && i <4*nn-2))
            {
                X_Index [i] = X_Index [i-1] + 1;
                J_Start [i] = J_Start[i-1]+4;
                J_End [i] = J_End [i-1]+4;
<<<<<<< HEAD
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
=======
                Main_Matrix->modifyCellValue (i,4*nn, 0);

            }

        }
        Main_Matrix->modifyCellValue (4*nn-2,4*nn, 0);
        Main_Matrix->modifyCellValue (4*nn-1,4*nn, 0);
// Evaluation Code Need Check
// Last Two Rows   
        function03(X[0], &Var_Vector);
        for (int i=0; i<Var_Vector.size(); i++)
        {
            log<< "\n Function03 Output at X[0]:" << Var_Vector[i];
        }


        for ( int j= J_Start [4*nn-2]; j < J_End [4*nn-2] ; j++)
        {
            Main_Matrix->modifyCellValue (4*nn-2,j,Var_Vector[j-J_Start[4*nn-2]]);

        }
       // Var_Vector = function03(X[nn]);
        function03(X[nn], &Var_Vector);
        for (int i=0; i<Var_Vector.size(); i++)
        {
            log<< "\n Function03 Output at X[nn]:" << Var_Vector[i];
        }

        for ( int j= J_Start [4*nn-1]; j < J_End [4*nn-1] ; j++)
        {
            Main_Matrix->modifyCellValue (4*nn-1,j,Var_Vector[j-J_Start[4*nn-1]]);

>>>>>>> Beta Version
        }
// Evaluate Matrix Element
        for (int i=0; i< 4*nn ; i++)
        {
            if (i>=0 && i<2*nn)
            {
<<<<<<< HEAD
                Var_Vector = function01(X[ X_Index [i]]);
=======
                function01(X[ X_Index [i]], &Var_Vector);
                for (int k=0; k<Var_Vector.size(); k++)
                {
                    log<< "\n Function01 Output at X[" << X_Index[i] << "]:" << Var_Vector[k];
                }
                //Var_Vector = function01(X[ X_Index [i]]);
>>>>>>> Beta Version
                for (  int j= J_Start [i]; j < J_End [i] ; j++)
                {
                    Main_Matrix->modifyCellValue (i,j,Var_Vector[j-J_Start[i]]);
                }
            }
            if ((i>=2*nn) && i<(3*nn-1))
            {
<<<<<<< HEAD
                    Var_Vector = function02(X[ X_Index [i]]);
=======
                    //Var_Vector = function02(X[ X_Index [i]]);
                    function02(X[ X_Index [i]], &Var_Vector);
                    for (int k=0; k<Var_Vector.size(); k++)
                    {
                        log<< "\n Function02 Output at X[" << X_Index[i] << "]:" << Var_Vector[k];
                    }
>>>>>>> Beta Version
                    for ( int j= J_Start [i]; j < J_End [i] ; j++)
                    {
                        Main_Matrix->modifyCellValue (i,j,Var_Vector[j-J_Start[i]]);
                        Main_Matrix->modifyCellValue (i, j+4,-Var_Vector[j-J_Start[i]] );
                    }

            }
            if (i>=(3*nn-1) && i<((4*nn)-2))
            {
<<<<<<< HEAD
                        Var_Vector = function03(X[ X_Index [i]]);
                        for ( int j= J_Start [i]; j < J_End [i] ; j++)
                        {
                            Main_Matrix->modifyCellValue (i,j,Var_Vector[j-J_Start[i]]);
                            Main_Matrix->modifyCellValue (i, j+4,-Var_Vector[j-J_Start[i]] );
                        }
             }
        }
=======
                        //Var_Vector = function03(X[ X_Index [i]]);
                        function03(X[ X_Index [i]], &Var_Vector);
                        for (int k=0; k<Var_Vector.size(); k++)
                        {
                            log<< "\n Function03 Output at X[" << X_Index[i] << "]:" << Var_Vector[k];
                        }
                        for ( int j= J_Start [i]; j < J_End [i] ; j++)
                        {
                            Main_Matrix->modifyCellValue (i,j,Var_Vector[j-J_Start[i]]);
                            Main_Matrix->modifyCellValue (i,j+4,-Var_Vector[j-J_Start[i]] );
                        }
             }
        }
// End Evaluation Code Need Check
        // Test Result
        //log << "\n We will display X_Input" ;
        for (int i = 0; i<X_Index.size(); i++)
        {

                log << "\n We will display X_Index " << X_Index[i];
                log << "\n" ;

        }
        log << "End  display X_Input" ;
        for (int i = 0; i<J_Start.size(); i++)
        {

                log << "\n We will display J_Start " << J_Start[i];
                log << "\n" ;

        }
        log << "End  display J_Start" ;
        for (int i = 0; i<J_End.size(); i++)
        {

                log << "\n We will display J_end " << J_End[i];
                log << "\n" ;

        }
        log << "End  display J_end" ;

        for (int i = 0; i<4*nn; i++)
        {

                log << "\n We will display Y " << Main_Matrix->getCellValue(i,4*nn);
                log << "\n" ;

        }
        log << "End  display Y" ;


>>>>>>> Beta Version
}

