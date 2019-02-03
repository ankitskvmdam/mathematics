
typedef struct{
    char *data;
    int digits;
}math_int;

typedef struct{
    char *data;
    int digits;
    math_int data_before_decimal;
    math_int data_after_decimal;
}math_float;