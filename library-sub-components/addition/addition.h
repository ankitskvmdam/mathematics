int carry = 0;

math_int intAddition( math_int a, math_int b ){
    
    math_int c;         //Variable to store the final result.
    int i;              //Loop control variable.

    //Reversing the integer and perpare them for addition.
    reverseString( a.data, a.digits );
    reverseString( b.data, b.digits );

    //Getting the max and min len so that memory for final integer allocated.
    int max_len = ( a.digits > b.digits ) ? a.digits : b.digits;
    int min_len = ( a.digits < b.digits ) ? a.digits : b.digits;

    //Allocating the memory and pointing to the free space.
    c.data = allocateMemoryForAddition( max_len );

    //Loop to add
    for( i = 0; i < min_len; i++){
        int temp;

        //Converting character to integer and adding unit place integer.
        temp = (int)( a.data[i] - '0' ) + (int)( b.data[i] - '0' );
        temp = temp + carry;

        c.data[i] = '0' + (temp % 10);      //Saving the remainder.
        carry = temp / 10;                  //Carry bit.
    }

    //If given integer are not of same length.
    if( b.digits == min_len ){              //If first integer has more number of digits.
        for( ; i < max_len; i++){
            int temp;
            temp = (int)( a.data[i] - '0' );
            temp = temp + carry;
            c.data[i] = '0' + (temp % 10);
            carry = temp / 10;
        }
    }

    else{
        for( ; i < max_len; i++){          //If second integer has more number of digits.
            int temp;
            temp = (int)( b.data[i] - '0' );
            temp = temp + carry;
            c.data[i] = '0' + (temp % 10);
            carry = temp / 10;
        }
    }

    //Checking if carry is empty or not.
    if(carry != 0)
        c.data[i++] = '0' + carry;
    
    c.data[i] = '\0';   //Adding the null character at the last.
    c.digits = i;       //Store the number of digits in the result.

    //Reversing the string to see the output in desired form.
    reverseString( c.data, c.digits );

    //Resetting the given two integer.
    reverseString( a.data, a.digits );
    reverseString( b.data, b.digits );

    //Resetting Carry
    carry = 0;

    return c;
}

// math_ addFloatingValue( char *floating_a, char *floating_b ){

// }

void floatAddition( math_float a, math_float b ){
    math_int data_before_decimal, data_after_decimal;
    data_before_decimal = intAddition( a.data_before_decimal, b.data_before_decimal );

    printf("%s", data_before_decimal.data);
    // return c;
}