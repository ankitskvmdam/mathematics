//Predefined libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//--------------->>>MACROS<<<-----------------------
#define FALSE 0
#define TRUE 1

#define FIRST_ONE 1
#define SECOND_ONE 2
#define BOTH_EQUAL 3 



//----------------->>>New Data Type<<<-----------------

typedef struct{
    char *data;
    int digits;
}math_int;

typedef struct{
    char *data;
    int digits;
    math_int data_before_decimal;
    math_int data_after_decimal;
}math_float;


//--------------->>>Prototypes<<<-------------------
//memory-allocation.h
char *allocateMemory( int );
char *allocateMemoryForAddition( int );
char *allocateMemoryForSubtraction( int );
char *allocateMemoryForFactorialFunction( int );
char *allocateMemoryForPowerFunction( int, int );

//string-operation.h
void reverseString( char *, int );
int removeLeadingZero( char * );

//utility.h
void addToInputStream( char );
void setValueToMathInt( math_int *, int );
void getMathInt( math_int * );
void getMathFloat( math_float * );
math_int addTrailingZero( math_int , int );
int checkGreaterInt ( math_int, math_int );

//subtraction.h
math_int intSubtraction ( math_int, math_int );
math_float floatSubtraction( math_float, math_float );


//addition.h
math_int intAddition ( math_int, math_int );
math_float floatSubtraction( math_float, math_float );




