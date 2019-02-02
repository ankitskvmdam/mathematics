#include "mathematics.h"

int main(void){
    math_float a;
    getMathFloat(&a);
    printf("\nBefore decimal: %s", a.data_before_decimal);
    printf("\nLength: %d", a.digits_before_decimal);

    printf("\nAfter decimal: %s", a.data_after_decimal);
    printf("\nLength: %d", a.digits_after_decimal);

    printf("\nNumber: %s", a.data);
    printf("\nLength: %d", a.digits);
    return 0;
}

