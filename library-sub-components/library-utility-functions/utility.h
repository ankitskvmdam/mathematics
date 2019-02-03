//Structure for input stream
struct input_stream{
    char c;
    struct input_stream *link;
}*front, *rear;             //Variable to control the input stream inputs.


int lengthOfInputStream;    //To count the length of input stream.

// Initial variables.
void initialize(){
    front = NULL;
    rear = NULL;
    lengthOfInputStream = -1;
}

void addToInputStream( char c ){
    struct input_stream *new_pointer;

    //Allocating space with buffer to avoid overflow.
    new_pointer = (struct input_stream *)malloc((sizeof(int) + sizeof(char)) + 2);  
    
    // Assign value to new pointer and give null to link part.
    new_pointer->c = c;
    new_pointer->link = NULL;

    // If Input Stream didn't contain any element.
    if(rear == NULL){
        front = rear = new_pointer; //Assign the value of new_pointer to front and rear both.
        lengthOfInputStream++;      //Counting input stream length.
        return;                     //Return from the function.
    }

    rear->link = new_pointer;   //Linking the previous stream bit to next stream bit.
    rear = new_pointer;         //Moving the rear pointer from previous to current stream bit.
    lengthOfInputStream++;  //Counting input stream length.

}

void setValueToMathInt( math_int *a ){
    //New pointer to access data and temp to delete accessed data from memeory.
    struct input_stream *new_pointer, *temp;

    char *data;                 //To store data.

    //Memory allocation for data variable.
    data = (char *)malloc(sizeof(char) * (lengthOfInputStream + 2));

    new_pointer = front;        //Getting the address of first element.
    int i = 0;                  //Loop control variable.

    //Loop to get data and free memory.
    while( i <= lengthOfInputStream ){
        data[i] = new_pointer->c;
        
        temp = new_pointer;     //Storing address of current data.
        new_pointer = new_pointer->link;    //Moving to the next data address.
    
        free(temp);      //Delete previous data from memory.

        i++;
    }

    //If there is no num in the input stream the assign 0. This is useful for float.
    if(lengthOfInputStream == -1){
        data[i] = '0';
        i++;
        lengthOfInputStream++;
    }

    data[i] = '\0'; //Adding Null at the last of array.
    
    //Reducing the size of the digit if first input stream in - .
    if(data[0] == '-'){
        i = lengthOfInputStream = removeLeadingZero(&data[1]) - 1;
    }
    else i = lengthOfInputStream = removeLeadingZero(data) - 1;

    a->data = data; //Assing data to main variable.
    a->digits = lengthOfInputStream + 1; // Assiging the number of digits.
    
}

//---------->>> Function to get MathInt  <<<------------------

void getMathInt( math_int *a ){
    initialize();       //Initialize variables.
    
    char c;             //To extract character form input buffer.

    c = getchar();
    
    if( c == '-' ){
        addToInputStream(c);    //Adding negative sign to the input stream.
        c = getchar();          //Getting the next element.
    }

    while( c >= '0' && c <= '9' ){
        addToInputStream(c);    //Adding to input stream.
        c = getchar();          //Getting the next element.
    }

    setValueToMathInt(a);       //Function to set value to the main variable.
}

//---------->>> Function to get MathFloat  <<<------------------
void getMathFloat( math_float *a ){
   initialize();                //Initialize variables.
    
    char c;                     //To extract character form input buffer.

    c = getchar();

    if( c == '-' ){
        addToInputStream(c);    //Adding negative sign to the input stream.
        c = getchar();          //Getting the next element.
    }

    while( c >= '0' && c <= '9' ){
        addToInputStream(c);    //Adding to input stream.
        c = getchar();          //Getting the next element.
    }

    //Set before decimal.
    setValueToMathInt( &a->data_before_decimal );

    //Reinitialize for data after decimal part;
    initialize();

    if(c == '.')
        c = getchar();
    while( c >= '0' && c <= '9' ){
        addToInputStream(c);    //Adding to input stream.
        c = getchar();          //Getting the next element.
    }

    //Set after decimal part.
    setValueToMathInt( &a->data_after_decimal );

    //Saving the length of the floating number without decimal
    a->digits = a->data_before_decimal.digits + a->data_after_decimal.digits;

    //Allocating the required space for storing the floating number
    a->data = (char *)malloc((sizeof(char) * (a->digits + 2))); 

    //Copying the floating number in memory.
    strcpy(a->data, a->data_before_decimal.data);
    strcat(a->data, ".");
    strcat(a->data, a->data_after_decimal.data);
}


//-------------->>> Function to add trailing zero for calculation purpose <<<--------------
math_int addTrailingZero( math_int b, int len ){
    math_int trailing_zero_number;      //Variable to store trailing zero number.
    int i;                              //Loop control varialbe.

    //Allocating space for trailing zero number and copying initial value.
    trailing_zero_number.data = (char *)malloc(sizeof(char) * (len + 3));
    strcpy(trailing_zero_number.data, b.data);
    
    //Loop to copy trailing zero at the end to the desire length.
    for( i = b.digits; i < len; i++){
        trailing_zero_number.data[i] = '0';
    }

    //Add null charater to the end.
    trailing_zero_number.data[i] = '\0';

    //Setting the length of the trailing zero number
    trailing_zero_number.digits = len;

    //Returning the new trailing zero number.
    return trailing_zero_number;
}