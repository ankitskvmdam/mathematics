char* allocateMemoryForFactorialFunction( num ){
    char *p;
    int no_of_digits = (int)(num * log10( num/2.0 )) + 2;
    p = (char *)malloc(sizeof(char) * no_of_digits);
    return p;
}

char* allocateMemoryForPowerFunction( base, power ){
    char *p;
    int no_of_digits = (int)(power * log10(base)) + 3;
    p = (char *)malloc(sizeof(char) * no_of_digits);
    return p;
}