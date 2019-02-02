// ------->>> Function for allocation of memory <<<-------------
char* allocateMemory( len ){
    char *p;
    p = (char *)malloc(sizeof(char) * len );
    return p;
}

// --------->>> Function for allocation of memory form final result of factorial <<<----------
char* allocateMemoryForFactorialFunction( num ){
    int no_of_digits = (int)(num * log10( num/2.0 )) + 2;
    return allocateMemory(no_of_digits);
}

// ------------->>> Function for allocation of mermory for final result of power function <<<-----
char* allocateMemoryForPowerFunction( base, power ){
    int no_of_digits = (int)(power * log10(base)) + 3;
    return allocateMemory(no_of_digits);
}

// ---------------->>> Function for allocation of memroy for final result of addition <<<------------
char* allocateMemoryForAddition( len ){
    return allocateMemory(len + 4);
}

// ---------------->>> Function for allocation of memroy for final result of subtraction <<<------------
char* allocateMemoryForSubtraction( len ){
    return allocateMemory(len + 2);
} 