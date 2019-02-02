#define BEFORE_DECIMAL 0
#define AFTER_DECIMAL 1

typedef struct{
    char *data;
    int digits;
}math_int;

typedef struct{
    char *data;
    char *data_before_decimal;
    char *data_after_decimal;
    
    int digits;
    int digits_before_decimal;
    int digits_after_decimal;
}math_float;

