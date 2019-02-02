#include "mathematics.h"
#include "test/test.h"

int main(void){
    // math_int a, b, c;
    // getMathInt(&a);
    // getMathInt(&b);

    // c = intAddition(a, b);

    // printf("\n%s", c.data);
    math_int a, b, c;
    getMathFloat(&a);
    getMathFloat(&b);

    floatAddition(a, b);
    displayFloat(a);

    return 0;
}

/*
384797583758375837598378957349587349857398573948753489753498757593875934759385 347857297598379578374957982734759832759832745897
*/

