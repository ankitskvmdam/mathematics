int borrow = 0;                 //Global variable to store borrow
int flag_for_borrow = 0;        //Global variable to say whether to add last borrow or not. Useful for float addition.
int add_negative = FALSE;       //This tell subtraction function whether to add negative sign or not.

/*
    NOTE:
        This function assumes that a is greater than b.
        Please process the input before calling this function.
 */
math_int subtraction( math_int a, math_int b){
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

    if( add_negative == TRUE ){     //If negative is added.
        c.digits = removeLeadingZero(&c.data[1]);
    }

    else{                           //If negative is not added.
        c.digits = removeLeadingZero(c.data);
    }

    //Resetting the given two integer and add_negative.
    reverseString( a.data, a.digits );
    reverseString( b.data, b.digits );
    add_negative = FALSE;

    return c;

}

math_int intSubtraction ( math_int a, math_int b){
    if( a.digits > b.digits ){
        add_negative = FALSE;
        return subtraction( a, b);
    }

    else{
        add_negative = TRUE;
        return subtraction( b, a );
    }
}

