#include "mathematics.h"
#include "test/test.h"

int main(void){
    
    math_float a, b, c;
    getMathFloat(&a);
    getMathFloat(&b);

    c = floatAddition(a, b);
    displayFloat(c);

    return 0;
}


