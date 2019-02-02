struct input_stream{
    char c;
    struct input_stream *link;
}*front, *rear;

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

    rear->link = new_pointer;
    rear = new_pointer;
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

    data[i] = '\0'; //Adding Null at the last of array.
    a->data = data; //Assing data to main variable.
    a->digits = lengthOfInputStream + 1; // Assiging the number of digits.
}


void setValueToMathFloat( math_float *a, int type ){
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

    data[i] = '\0'; //Adding Null at the last of array.


    if( type == BEFORE_DECIMAL ){                            //Assign data to before decimal part.
        a->data_before_decimal = data;                      //Assing data to main variable.
        a->digits_before_decimal = lengthOfInputStream + 1;  //Assiging the number of digits.
    }

    else if ( type == AFTER_DECIMAL ){                       //Assign data to after decimal part.
        a->data_after_decimal = data;                       //Assing data to main variable.
        a->digits_after_decimal = lengthOfInputStream + 1;   //Assiging the number of digits.
    }
    
}

//---------->>> Function to get MathInt  <<<------------------

void getMathInt( math_int *a ){
    initialize();       //Initialize variables.
    
    char c;             //To extract character form input buffer.

    c = getchar();
    while( c >= '0' && c <= '9' ){
        addToInputStream(c);    //Adding to input stream.
        c = getchar();          //Getting the next element.
    }

    setValueToMathInt(a);       //Function to set value to the main variable.
}

//---------->>> Function to get MathFloat  <<<------------------
void getMathFloat ( math_float *a ){
   initialize();                //Initialize variables.
    
    char c;                     //To extract character form input buffer.

    c = getchar();
    while( c >= '0' && c <= '9' ){
        addToInputStream(c);    //Adding to input stream.
        c = getchar();          //Getting the next element.
    }

    //Set before decimal.
    setValueToMathFloat( a, BEFORE_DECIMAL );

    //Reinitialize for data after decimal part;
    initialize();

    c = getchar();
    while( c >= '0' && c <= '9' ){
        addToInputStream(c);    //Adding to input stream.
        c = getchar();          //Getting the next element.
    }

    //Set after decimal part.
    setValueToMathFloat( a, AFTER_DECIMAL );

    //Saving the length of the floating number without decimal
    a->digits = a->digits_before_decimal + a->digits_after_decimal;

    //Allocating the required space for storing the floating number
    a->data = (char *)malloc((sizeof(char) * (a->digits + 2))); 

    //Copying the floating number in memory.
    strcpy(a->data, a->data_before_decimal);
    strcat(a->data, ".");
    strcat(a->data, a->data_after_decimal);
}