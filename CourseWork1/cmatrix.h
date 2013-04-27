#ifndef CMATRIX_H
#define CMATRIX_H

#include <string>
#include<iostream>

using namespace std;

template <class T>
class cMatrix
{
    private:
        int numberOfRows_;
        int numberOfCols_;
        T **mat;

    public:
        cMatrix();
        cMatrix(int rows, int columns) // Zero-based array
        {
            numberOfRows_ = rows;
            numberOfCols_ = columns;
            mat = new T*[rows];
            for(int i=0;i<rows;i++)
                mat[i] = new T[columns];
        }
        cMatrix(int rows, int columns, const T &value) //Initialize to constant
        {
            numberOfRows_ = rows;
            numberOfCols_ = columns;
            mat = new T*[rows];
            for(int i=0;i<rows;i++)
            {
                mat[i] = new T[columns];
                for(int j=0;j<columns;j++)
                    mat[i][j] = value;
            }
        }

        cMatrix(int rows, int columns, const T *matrix) // Initialize to array
        {
            numberOfRows_ = rows;
            numberOfCols_ = columns;
            mat = new T*[rows];
            for(int i=0;i<rows;i++)
            {
                mat[i] = matrix[i];
               // for(int j=0;j<columns;j++)
                //    mat[i][j] = *(value);
            }
        }

        cMatrix(const cMatrix &rhs) // Copy constructor
        {
            numberOfRows_ = rhs.getNumberOfRows();
            numberOfCols_ = rhs.getNumberOfColumns();
            mat = new T*[numberOfRows_];
            for(int i=0;i<numberOfRows_;i++)
            {
                //mat[i] = rhs[i];
                for(int j=0;j<numberOfCols_;j++)
                    mat[i][j] = rhs[i][j];
            }
        }

        cMatrix & operator=(const cMatrix &rhs) //assignment
        {
            return cMatrix(rhs);
        }

        inline T* operator[](const int i) //subscripting: pointer to row i
        {
            if(i<numberOfRows_)
                return mat[i];
        }

        inline const T* operator[](const int i) const
        {
            if(i<numberOfRows_)
                return mat[i];
        }

        inline int getNumberOfRows() const
        {
            return numberOfRows_;
        }

        double getCellValue(int rr, int cc)
        {
            return mat[rr][cc];
        }

        void modifyCellValue (int rr, int cc, const T &value)
        {
            mat[rr][cc] = value;
        }

        inline int getNumberOfColumns() const
        {
            return numberOfCols_;
        }
        void resize(int RowsCount, int ColumnsCount) // resize (contents not preserved)
        {
            //First back-up the previous matrix
            T* tmpMat = new T*[numberOfRows_];
            for(int i=0;i<numberOfRows_;i++)
            {
                tmpMat[i] = new T[numberOfCols_];
                for(int j=0;j<numberOfCols_;j++)
                    tmpMat[i][j] = mat[i][j];

                delete[] mat[i];
            }
            delete[] mat;

            numberOfRows_ = RowsCount;
            numberOfCols_ = ColumnsCount;
            mat = new T*[numberOfRows_];
            for(int i=0;i<numberOfRows_;i++)
            {
                mat[i] = new T[numberOfCols_];
                for(int j=0;j<numberOfCols_;j++)
                    mat[i][j] = tmpMat[i][j];
                delete[] tmpMat[i];
            }
            delete[] tmpMat;
        }

        void assign(int RowsCount, int ColumnsCount, const T &value) // resize and assign a constant value
        {
            for(int i=0;i<numberOfRows_;i++)
                delete[] mat[i];
            delete[] mat;

            numberOfRows_ = RowsCount;
            numberOfCols_ = ColumnsCount;
            mat = new T*[numberOfRows_];
            for(int i=0;i<numberOfRows_;i++)
            {
                mat[i] = new T[numberOfCols_];
                for(int j=0;j<numberOfCols_;j++)
                    mat[i][j] = *(value);

            }
        }

        string toString()
        {
            string ret="";
            char buffer [33];

            for(int i=0;i<numberOfRows_;i++)
            {
                for(int j=0;j<numberOfCols_;j++)
                {
                    itoa(mat[i][j],buffer,10);
                    ret+=buffer;
                }
                ret+="\n";
            }
            return ret;
        }
        ~cMatrix()
        {
            for(int i=0;i<numberOfRows_;i++)
                delete[] mat[i];

            delete[] mat;
        }
};

#endif // CMATRIX_H
