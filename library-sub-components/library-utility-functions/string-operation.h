
//Function to reverse the string.
void reverseString( char *str, int len ){
    int i;          //Loop control variable.
    char temp;      //Store current element temporarily.

    //Loop to reverse the string.
    for( i = 0; i < len/2; i++){
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}

//Function to remove the leading zero.
int removeLeadingZero( char *str ){
    int i;          //Loop control variable.
    int k = 0;      //To store new length of number.
    char temp;      //Store current element temporarily.

    for( i = 0; str[i] != '\0'; i++){
        if( str[i] != '0')
            break;
    }

    if(str[i] == '\0'){
        /*
            This is only true if str contains only zero. 
            If this happens then only return 1 zero.
        */
       
        str[k++] = '0';     //Adding zero at index 0.
        str[k] = '\0';      //Adding null charater.
        return k;           //Return new charater length.
    }

    for( ; str[i] !='\0'; i++, k++ ){
        str[k] = str[i];
    }

    str[k] = '\0';

    return k;
}