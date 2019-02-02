#include "mathematics.h"

int main(void){
    math_int a, b, c;
    getMathInt(&a);
    getMathInt(&b);

    c = intAddition(a, b);

    printf("%s", c.data);
    return 0;
}

