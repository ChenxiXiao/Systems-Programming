#include "part4.h"
#include <ctype.h>

void strlower(char str[], char buffer[]){
    int i;
    /*
    while(str[i]){
        buffer[i] = tolower(str[i]);
        i++;
    }
    */
    for(i = 0; str[i]; i++){
        buffer[i] = tolower(str[i]);
    }
    
}

void str_lowermutate(char str[]){
    int i = 0;
    for(i = 0; str[i]; i++){
        str[i] = tolower(str[i]);
    }
}

