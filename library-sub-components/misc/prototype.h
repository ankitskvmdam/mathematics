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

