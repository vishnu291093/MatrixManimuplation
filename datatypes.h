
#ifndef DATATYPES_H
#define DATATYPES_H
// 1 byte
typedef unsigned char UInt8; //0 to 255
typedef signed char SInt8;   //-128 to 127
/***********/

// 2 bytes
typedef unsigned short int  UInt16;  //0 to 65,535
typedef signed short int  SInt16;    //-32768 to 32767
/***********/

// 4 bytes
typedef unsigned int UInt32;  //0 to 4294967295
typedef signed int SInt32;    //-2147483648 to 2147483647
/*************/

// 8 bytes

typedef signed long long SInt64; //-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
typedef unsigned long long UInt64; // 0 to 18,446,744,073,709,551,615

/*************/

//4 Bytes
typedef float RealF;

/*************/

// 8 bytes

typedef double RealD;

/*************/
#endif // DATATYPES_H
