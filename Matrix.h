/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#ifndef Matrix_Class
#define Matrix_Class

#include <iostream>
#include "datatypes.h"
/*
This header file contains a c++ MMatrix amnpulation library. It can be used for transposing and multiplying a matrix using
the MatrixTranspose() and MatrixMutiply() functions.
The matrix can be constructed using either one of the constructors.
The matrix is created by passing the rows and columns within <>.
*/
template<UInt32 m_uRows, UInt32 m_uColumns ,class T>
class CMatrix{
    private:
        // array for stroing thr contents of the matrix
        T * m_tMatrixArray = new T[m_uRows * m_uColumns];
    public:
        //the constructor for initalizing all the matrix elements as 0
        CMatrix()
        {
            for(UInt32 i =0; i< m_uRows * m_uColumns ; i++)
            {
                m_tMatrixArray[i] = 0;
            }
        }
        void MatCopy( T * parr_matrix_array)
        {
            for(UInt32 i =0; i< m_uRows * m_uColumns ; i++)
            {
            m_tMatrixArray[i] = parr_matrix_array[i];
            }
        }
        //Function for coyping an array into the matrix class
       //the constructor for creating a matrix by taking in a array
        CMatrix(T * parr_matrix_array)
        {
            MatCopy(parr_matrix_array);
        }
        //A copy constructor
        CMatrix(const CMatrix<m_uRows, m_uColumns, T> & cmat_matrix_ref)
        {
            MatCopy(cmat_matrix_ref.m_tMatrixArray);
        }
        //A Copy assignment operator
        CMatrix< m_uRows,  m_uColumns , T>& operator =( const CMatrix< m_uRows,  m_uColumns, T> & cmat_matrix_ref )
        {
            if(this != &cmat_matrix_ref)
                MatCopy(cmat_matrix_ref.m_tMatrixArray);
            return *this;
        }
        //The user can access and change the value of the matrix by using () operator
        T & operator() (UInt32 i_rows, UInt32 i_columns)
        {
            if(i_rows < m_uRows && i_columns<m_uColumns)
            {
                return m_tMatrixArray[i_rows*m_uColumns + i_columns];
            }
        }

        T  operator() (UInt32 i_rows, UInt32 i_columns) const
        {
            if(i_rows < m_uRows && i_columns<m_uColumns)
            {
                return m_tMatrixArray[i_rows*m_uColumns + i_columns];
            }
        }
        //A function to print the values of the matrix
        void PrintMatrix() const
        {
            for(UInt32 i =0; i < m_uRows; i++ )
            {
                for(UInt32 j =0; j < m_uColumns; j++)
                {
                    std::cout << m_tMatrixArray[i*m_uColumns + j]<< "\t";
                }
                std::cout<<"\n";
            }
        }
        //Destructor
        ~CMatrix()
        {
            delete[] m_tMatrixArray;
        }
        //Equivalance operator. Can check if 2 matrices are equal or not
        bool operator == (const CMatrix< m_uRows,  m_uColumns , T> & cmat_matrix_ref )
        {
            for(UInt32 i = 0; i <m_uRows * m_uColumns ;i ++)
           {
                if(this->m_tMatrixArray[i] != cmat_matrix_ref.m_tMatrixArray[i])
                {
                    return false;

                }
            }
            return true;
        }
        //Addition operator
        void operator += (const CMatrix< m_uRows,  m_uColumns, T> & cmat_matrix_ref )
        {
            for(UInt32 i = 0; i <m_uRows * m_uColumns ;i ++)
                {
                    this->m_tMatrixArray[i] += cmat_matrix_ref.m_tMatrixArray[i];
                }
        }
        //Subtraction operator
        void operator -= (const CMatrix< m_uRows,  m_uColumns, T> & cmat_matrix_ref )
        {
            for(UInt32 i = 0; i <m_uRows * m_uColumns ;i ++)
                {
                    this->m_tMatrixArray[i] -= cmat_matrix_ref.m_tMatrixArray[i];
                }
        }
        CMatrix< m_uRows,  m_uColumns, T > operator + (const CMatrix< m_uRows,  m_uColumns, T > & cmat_matrix_ref )
        {
            CMatrix< m_uRows,  m_uColumns, T> TempMatrix = *this;
            TempMatrix += cmat_matrix_ref;
             return TempMatrix;
        }

        CMatrix< m_uRows,  m_uColumns, T > operator - (const CMatrix< m_uRows,  m_uColumns,T> & cmat_matrix_ref )
        {
            CMatrix< m_uRows,  m_uColumns, T > TempMatrix = *this;
            TempMatrix -= cmat_matrix_ref;
            return TempMatrix;
        }
        //Matrix transpose function. By calling this function a temporary matrix will get created that will be the transpose of the current matrix
        CMatrix< m_uRows,  m_uColumns,T> MatrixTranspose()
        {

            T * TempArray = new T[m_uRows * m_uColumns];

            for(UInt32 i = 0; i<m_uRows; i++)
            {
                for(UInt32 j = 0; j<m_uRows; j++)
                {
                    TempArray[j * m_uRows + i] = this->m_tMatrixArray[i * m_uColumns + j];

                }
            }
             CMatrix < m_uColumns,  m_uRows, T> TempMatrix(TempArray);
            return TempMatrix;
        }
        //A matrix multiplication function that will multiply 2 matrices provided that the first matrix column and second matrix row are the same.
        template < UInt32 MultiMatColumn >
         CMatrix< m_uRows,  MultiMatColumn,T> MatrixMultiply(const CMatrix< m_uColumns,  MultiMatColumn,T> & cmat_matrix_ref)
        {

            T * TempArray = new T[m_uRows * MultiMatColumn];
            for(UInt32 i = 0; i<m_uRows; i++)
            {
                for(UInt32 j = 0; j<MultiMatColumn; j++)
                {   TempArray[i*MultiMatColumn +j] = 0;
                    for(UInt32 k = 0; k<m_uColumns; k++)
                    {
                        TempArray[i*MultiMatColumn +j] += this->m_tMatrixArray[i*m_uColumns + k] + cmat_matrix_ref.m_tMatrixArray[k*MultiMatColumn + j];
                    }

                }

            }

            CMatrix < m_uRows,  MultiMatColumn,T> TempMatrix(TempArray);
            return TempMatrix;

        }
};

#endif
