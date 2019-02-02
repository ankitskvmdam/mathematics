char* allocateMemory( len ){
    char *p;
    p = (char *)malloc(sizeof(char) * len );
    return p;
}

char* allocateMemoryForFactorialFunction( num ){
    int no_of_digits = (int)(num * log10( num/2.0 )) + 2;
    return allocateMemory(no_of_digits);
}

char* allocateMemoryForPowerFunction( base, power ){
    int no_of_digits = (int)(power * log10(base)) + 3;
    return allocateMemory(no_of_digits);
}

char* allocateMemoryForAddition( len ){
    return allocateMemory(len + 4);
}