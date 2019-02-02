void displayFloat(math_float a){

    printf("\nData before decimal: %s", a.data_before_decimal.data);
    printf("\nLength: %d", a.data_before_decimal.digits);

    printf("\nData after decimal: %s", a.data_after_decimal.data);
    printf("\nLength: %d", a.data_after_decimal.digits);

    printf("\nData: %s", a.data);
    printf("\nLength: %d", a.digits);
}