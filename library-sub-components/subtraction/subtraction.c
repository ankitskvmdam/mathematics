#include "../../mathematics.h"

int borrow = 0;                 //Global variable to store borrow
int add_negative = FALSE;       //This tell subtraction function whether to add negative sign or not.

/*
    NOTE:
        This function assumes that a is greater than b.
        Please process the input before calling this function.
 */

math_int subtraction( math_int a, math_int b, int remove_zero){
    int i;          //Loop control variable.
    math_int c;

    //Reversing the integer and perpare them for subtraction.
    reverseString( a.data, a.digits );
    reverseString( b.data, b.digits );

    //Allocating memory for result
    c.data = allocateMemoryForSubtraction( a.digits );

    int max_len = a.digits;     //Storing the maximum length.
    int min_len = b.digits;     //Storing the minimum length.

    //Loop to perform subtraction operation.
    for( i = 0; i < min_len; i++ ){
        int unit, unit_a, unit_b;       // unit for storing unit digit sum. unit_a and unit_b store unit place of a and b.

        //Assign negative sign (if encounter) value to 0 so if have no effect on calculation.
        unit_a = ( a.data[i] != '-' ) ? ( int )( a.data[i] - '0' ) : 0;
        unit_b = ( b.data[i] != '-' ) ? ( int )( b.data[i] - '0' ) : 0;

        unit = unit_a - unit_b - borrow; //Subtracting.

        if( unit < 0 ){
            unit = unit + 10;
            borrow = 1;
        }

        else borrow = 0;
        c.data[i] = unit + '0';
    }

    for( ; i < max_len; i++){
        int unit;

        //Assign negative sign (if encounter) value to 0 so if have no effect on calculation.
        unit = ( a.data[i] != '-' ) ? ( int )( a.data[i] - '0' ) : 0;

        unit = unit - borrow;

        if( unit < 0 ){
            unit = unit + 10;
            borrow = 1;
        }

        else borrow = 0;

        c.data[i] = unit + '0';
    }

    //If we have to add negative sign.
    if( add_negative == TRUE){
        c.data[i++] = '-';
    }

    c.data[i] = '\0';   //Adding the null character at the last.
    c.digits = i;       //Store the number of digits in the result.

    //Reversing the string to see the output in desired form.
    reverseString( c.data, c.digits );

    if( add_negative == TRUE &&  remove_zero == TRUE){     //If negative is added.
        c.digits = removeLeadingZero(&c.data[1]);
    }

    else if(remove_zero == TRUE){                           //If negative is not added.
        c.digits = removeLeadingZero(c.data);
    }

    //Resetting the given two integer and add_negative.
    reverseString( a.data, a.digits );
    reverseString( b.data, b.digits );
    add_negative = FALSE;

    return c;

}

//Prepocessor function for subtraction of two integer number.
math_int intSubtraction ( math_int a, math_int b){
    int check = checkGreaterInt( a, b );

    if( check == FIRST_ONE ){
        add_negative = FALSE;
        return subtraction( a, b, TRUE );
    }

    else if( check == SECOND_ONE ){
        add_negative = TRUE;
        return subtraction( b, a, TRUE );
    }

    else    //We know that both number are same. then just return 0;
    {
        math_int c;
        c.data = allocateMemory(4);
        c.digits = 1;
        c.data[0] = '0';
        c.data[1] = '\0';

        return c;
    }
    
}

//Prepocessor function for subtraction of two floating number.
math_float floatSubtraction( math_float a, math_float b ){
    int check = checkGreaterInt( a.data_before_decimal, b.data_before_decimal );
    math_float result;       //To Store the final result.
    math_int trailing_zero_number, data_after_decimal, data_before_decimal;  //To store trailing zero number.

    if( check == BOTH_EQUAL ){      //If Integer part is same then check form after decimal part.
        check = checkGreaterInt( a.data_after_decimal, b.data_after_decimal );
    }

    if( check == BOTH_EQUAL ){      //If both the floating point number is same.
        result.data_before_decimal.data = allocateMemory(4); //Allocating memory to store before decimal part.
        result.data_after_decimal.data = allocateMemory(4);  //Allocating memory to store after decimal part.

        //Setting the value to 0.0
        result.data_after_decimal.digits = result.data_before_decimal.digits = 1;
        result.data_after_decimal.data[0] = result.data_before_decimal.data[0] = '0';
        result.data_after_decimal.data[1] = result.data_before_decimal.data[1] = '\0';

        return result;
    }

    else if( check == FIRST_ONE ){
        add_negative = FALSE;

        if( a.data_after_decimal.digits > b.data_after_decimal.digits ){
            //Adding trailing zero
            trailing_zero_number = addTrailingZero( b.data_after_decimal, a.data_after_decimal.digits );
            data_after_decimal = subtraction( a.data_after_decimal, trailing_zero_number, FALSE );
        }

        else{
            //Adding trailing zero
            trailing_zero_number = addTrailingZero( a.data_after_decimal, b.data_after_decimal.digits );
            data_after_decimal = subtraction( trailing_zero_number, b.data_after_decimal, FALSE );
        }

        data_before_decimal = subtraction( a.data_before_decimal, b.data_before_decimal, TRUE);
    }

    else{
        add_negative = FALSE;

        if( a.data_after_decimal.digits > b.data_after_decimal.digits ){
            //Adding trailing zero
            trailing_zero_number = addTrailingZero( b.data_after_decimal, a.data_after_decimal.digits );
            data_after_decimal = subtraction( trailing_zero_number, a.data_after_decimal, FALSE );
        }

        else{
            //Adding trailing zero
            trailing_zero_number = addTrailingZero( a.data_after_decimal, b.data_after_decimal.digits );
            data_after_decimal = subtraction( b.data_after_decimal, trailing_zero_number, FALSE );
        }

        add_negative = TRUE;
        data_before_decimal = subtraction( b.data_before_decimal, a.data_before_decimal, TRUE );
    }

    add_negative = FALSE;

    //Stroing the number of digit in result.
    result.digits = data_before_decimal.digits + data_after_decimal.digits;

    //Allocating memory for results variable
    result.data_before_decimal.data = allocateMemory( data_before_decimal.digits + 1 );
    result.data_after_decimal.data = allocateMemory( data_after_decimal.digits + 1 );
    result.data = allocateMemory( result.digits + 1 );
    
    // //Updating the value of result.
    strcpy(result.data_before_decimal.data, data_before_decimal.data);
    strcpy(result.data_after_decimal.data, data_after_decimal.data);
    result.data_after_decimal.digits = data_after_decimal.digits;
    result.data_before_decimal.digits = data_before_decimal.digits;

    // //Copying the floating number in memory.
    strcpy(result.data, data_before_decimal.data);
    strcat(result.data, ".");
    strcat(result.data, data_after_decimal.data);

    //Stroing the number of digit in result.
    result.digits = data_before_decimal.digits + data_after_decimal.digits;

    return result;
}

