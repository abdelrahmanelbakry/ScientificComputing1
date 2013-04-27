#include "cvector.h"
#include "cmatrix.h"



cVector<double>  NewtonInterPolation (int Sample_Size, cVector <double> X, cVector <double> Y)
{
    if (Sample_Size == X.size() && Sample_Size == Y.size()  )
    {
      cMatrix <double> fdd ( Sample_Size -1 , Sample_Size -1);
      for (int u = 0; u<Sample_Size-1 ; u++)
      {
          for (int g = 0; g< Sample_Size-1-u; g++)
          {
              double addedValue;
              if (u==0)
              {
                  addedValue = (Y[(g+1)] - Y[g]) / (X[g+1] - X[g]);
              }
              else
              {
                  addedValue = (fdd.getCellValue(u-1,g+1) - fdd.getCellValue(u-1,g)) / (X[g+u+1] - X[g]);
              }

              fdd.modifyCellValue(u,g,addedValue);
          }
      }

      cVector <double> b (Sample_Size);
      b[0] = Y[0];
      for (int z = 1; z<Sample_Size ; z++)
      {
          b[z] = fdd.getCellValue(z-1,0);
      }

       return b;
    }
    else
    {
      cVector <double> error (1);
      error[0] = 0;

      return error;
    }
}
