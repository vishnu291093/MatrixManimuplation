/*
This file is to show the features of the Matrix library
All the functionality is shown here with examples

*/
#include "Matrix.h"

int main()
{
    UInt16 g[] = {3,2,4,2,4,2,2,4,3};   //Create an array of the values to be placed inside the matrix
    CMatrix<3,3,UInt16 > Mat1();   //Creating a matrix of size 3,3 with values of type Unsigned int.
    CMatrix<3,3,UInt16 > Mat2(g);      //Creating a Matrix of size 3,3 and passing the values of the array inside it.
    CMatrix<3,3,UInt16 > Mat3(Mat2);    //Copy Constructor
    CMatrix<3,3,UInt16 > Mat5;
    Mat5 = Mat2;                        //Copy assignment operator
    CMatrix<3,3,UInt16 > Mat6();
    Mat3= Mat5-Mat2;                    //Subraction Operation
    Mat3 = Mat5+Mat2;                   //Addition operation
    Mat3=Mat3.MatrixTranspose();        //Transpose Operation
    Mat3 = Mat3.MatrixMultiply(Mat5);   //Multiplication Operation
    Mat3.PrintMatrix();                 //Print Operation

}
