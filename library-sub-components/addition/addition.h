int carry = 0;              //Global variable to store carry
int flag_for_carry = FALSE;     //Global variable to say whether to add last carry or not. Useful for float addition.

/*
    NOTE:
        This function assumes that a is greater than b.
        Please process the input before calling this function.
 */

math_int addition( math_int a, math_int b ){
    
    math_int c;         //Variable to store the final result.
    int i;              //Loop control variable.

    //Reversing the integer and perpare them for addition.
    reverseString( a.data, a.digits );
    reverseString( b.data, b.digits );

    //Getting the max and min len so that memory for final integer allocated.
    int max_len = a.digits;
    int min_len = b.digits;

    //Allocating the memory and pointing to the free space.
    c.data = allocateMemoryForAddition( max_len );

    //Loop to perform addition operation
    for( i = 0; i < min_len; i++){
        int unit, unit_a, unit_b;     // unit for storing unit digit sum. unit_a and unit_b store unit place of a and b.

        //Assign negative sign (if encounter) value to 0 so if have no effect on calculation.
        unit_a = ( a.data[i] != '-' ) ? ( int )( a.data[i] - '0' ) : 0;
        unit_b = ( b.data[i] != '-' ) ? ( int )( b.data[i] - '0' ) : 0;

        //Converting character to integer and adding unit place integer.
        unit = unit_a + unit_b + carry;

        c.data[i] = '0' + (unit % 10);      //Saving the remainder.
        carry = unit / 10;                  //Carry bit.
    }

    //If given integer are not of same length.
    for( ; i < max_len; i++){
        int unit;
        
        //Assign negative sign (if encounter) value to 0 so if have no effect on calculation.
        unit = ( a.data[i] != '-' ) ? ( int )( a.data[i] - '0' ) : 0;

        unit = unit + carry;
        c.data[i] = '0' + (unit % 10);
        carry = unit / 10;
    }

    //Checking if carry is empty or not and flag for carry bit is 0
    if(carry != 0 && flag_for_carry == FALSE)
        c.data[i++] = '0' + carry;
    
    c.data[i] = '\0';   //Adding the null character at the last.
    c.digits = i;       //Store the number of digits in the result.

    //Reversing the string to see the output in desired form.
    reverseString( c.data, c.digits );

    //Resetting the given two integer.
    reverseString( a.data, a.digits );
    reverseString( b.data, b.digits );

    //Resetting Carry
    if(flag_for_carry == FALSE)
        carry = 0;

    return c;
}

//First process the integer and the perform addition
math_int intAddition( math_int a, math_int b){

    if(a.digits > b.digits){

        return (addition(a, b));
    }

    else{

        return (addition(b, a));
    }
}

math_float floatAddition( math_float a, math_float b ){
    math_float result;
    math_int data_before_decimal, data_after_decimal, trailing_zero_number;

    flag_for_carry = TRUE;

    //First adding the number after decimal.
    if( a.data_after_decimal.digits > b.data_after_decimal.digits ){
        trailing_zero_number = addTrailingZero( b.data_after_decimal, a.data_after_decimal.digits );
        data_after_decimal = intAddition( a.data_after_decimal, trailing_zero_number);
    }

    else{
        trailing_zero_number = addTrailingZero( a.data_after_decimal, b.data_after_decimal.digits );
        data_after_decimal = intAddition( b.data_after_decimal, trailing_zero_number );
    }

    //Adding the number before decimal
    data_before_decimal = intAddition( a.data_before_decimal, b.data_before_decimal );

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

    //Resetting the value of carry and flag for carry.
    carry = 0;
    flag_for_carry = FALSE;

    return result;
}