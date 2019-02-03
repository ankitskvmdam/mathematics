#include "mathematics.h"
#include "test/test.h"
int main(void){
    
    math_float a, b, c;
    getMathFloat(&a);
    getMathFloat(&b);

    c = floatSubtraction(a, b);
    // displayFloat(c);

    printf("%s", c.data);
    // math_int a, b, c;
    // getMathInt(&a);
    // getMathInt(&b);
    // c = intSubtraction(a, b);
    // printf("%s", c.data);
    return 0;
}

