#include "part4.h"
#include <ctype.h>

void strlower(char *str, char *buffer){
    /*
    while(str[i]){
        buffer[i] = tolower(str[i]);
        i++;
    }
    */
    while(*str){
        *buffer++ = tolower(*str++);
    }
    
}


void str_lowermutate(char *str){
    while(*str){
        *str = tolower(*str);
        str++;
    }
}

