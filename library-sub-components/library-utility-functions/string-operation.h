
void reverseString(char *str, int len){
    int i;
    char temp;
    for( i = 0; i < len/2; i++){
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
}