/*
    NOTE:
        In every function of memory allocation there is buffer taken.
        This is taken to reduce the changes of overflow.
 */

// ------->>> Function for allocation of memory <<<-------------
char* allocateMemory( int len ){
    char *p;
    p = (char *)malloc(sizeof(char) * len );
    return p;
}

// --------->>> Function for allocation of memory form final result of factorial <<<----------
char* allocateMemoryForFactorialFunction( int num ){
    int no_of_digits = (int)(num * log10( num/2.0 )) + 4;
    return allocateMemory(no_of_digits);
}

// ------------->>> Function for allocation of mermory for final result of power function <<<-----
char* allocateMemoryForPowerFunction( int base, int power ){
    int no_of_digits = (int)(power * log10(base)) + 4;
    return allocateMemory(no_of_digits);
}

// ---------------->>> Function for allocation of memroy for final result of addition <<<------------
char* allocateMemoryForAddition( int len ){
    return allocateMemory(len + 4);
}

// ---------------->>> Function for allocation of memroy for final result of subtraction <<<------------
char* allocateMemoryForSubtraction( int len ){
    return allocateMemory(len + 4);
} 