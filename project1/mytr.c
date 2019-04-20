#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(char *, char *);
char *copy(char *);
void escape(char *, int *);
void delete(char *, int);

int main(int argc, char *argv[]){
    /*char *res;*/
    int size_set1;
    char *set1, *set2;
    if(argc < 3){
       fprintf(stderr, "mytr: missing operand\nUsage: %s <Set1 or -d> <Set2>\n", argv[0]);
       exit(1);
    }
    if(argc >= 4){
        fprintf(stderr, "mytr: extra operand '%s'\nUsage: %s <Set1 or -d> <Set2>\n", argv[3], argv[0]);
        exit(1);
        /*Usage: ¦¦[¦1¦¦¦ÍC¦¦P¦@ <Set1 or -d> <Set2> --> missing an variable*/ 
    }
    else if(strcmp(argv[1], "-d") == 0){
        /* delete */
        size_set1 = strlen(argv[2]);
        set1 = copy(argv[2]);
        delete(set1, size_set1);
        free(set1);
    }
    
    else{
        /* translate */
        set1 = copy(argv[1]);
        set2 = copy(argv[2]);
        trans(set1, set2);
        free(set1);
        free(set2);
    }
    
    return 1;
}


void delete(char *set, int size)
{
    char c;
    int i;
    escape(set, &size);
    while ((c = getchar()) != EOF)
    {
        /* for loop checks the indexes to see if any of the replacement chars are found*/
        for (i = 0; i < size; i++)
        {
            if (c == set[i])
            {
                break;
            }
            if(i == (size-1)){
                putchar(c); 
            }
        }
    }   
    putchar('\n');
    return;
}

void trans(char *set1, char *set2){
    int size_set1, size_set2, i; 
    char c; 
    int j; 
    char match = '\0';
    char addition;
    size_set1 = strlen(set1);
    size_set2 = strlen(set2);
    /*amend sets format */
    char newset[100];
    strcpy(newset, set2);
    
    escape(set1, &size_set1);
    escape(set2, &size_set2);
    if(size_set2 < size_set1){
        addition = set2[size_set2-1];
        for(i = size_set2; i < size_set1; i++){
            newset[i] = addition;
        }
        set2 = newset;
    }
    while((c = getchar()) != EOF){
       /* for(j = 0; j < size_set1; j++){
         
            if(c == set1[j]){
                putchar(set2[j]);
                break;
            }   
            if(j == (size_set1-1)){
                putchar(c); 
            }
        }
        */
        for(j = 0; j < size_set1; j++){
        /*for(j = 0; j < size_set1; j++){
            printf("char, size(s1), j: %c, %d, %d\n", c,size_set1, j);
            */
            if(c == set1[j]){
                match = set2[j];
            }  
        }
        
        if(match){
            putchar(match);
            match = '\0';
        }
        else{
            putchar(c); 
        }
    }
    putchar('\n');
    return;
}


void escape(char *set, int *size){
    /* tackle with sets other than single character entries */
    /* expected return: amended set and size */
    int i;
    int j = 0;
    char new[100] ={};
    for(i = 0; i < *size; i++){
        if(set[i] == '\\'){
            switch(set[++i]){
            case 'n':
                /*set[i] = '\n'; */
                new[j] = '\n';
                j++;
                break;
            case 't':
                /*set[i] = '\t';*/
                new[j] = '\t';
                j++;
                break;
            case '\\':
                /*set[i] = '\\';*/
                new[j] = '\\';
                j++;
                break;
            default:
            /* if \ is followed by any other char, tr will ignore \ and delete it from set  */
                break;
            }
        }
        else{
            new[j] = set[i];
            j++;
        }
    }
    strcpy(set, new);
    *size = j;
}

char* copy(char *string){
    const size_t len = strlen(string) + 1; /*empty \0 */
    char *new = (char *)malloc(len);
    strncpy(new, string, len);
    return new;
}





/*
Review: 
stdin stdout stderr
putchar not working 
core dump
copy string 
str is a *char, str[0] is a char
---
getchar() will just pause until the terminal gives it a complete line of text after you hit enter.
Then it'll return a character at a time until the standard input buffer is empty 
wait again for more input to be provided by the kernel.
--
difference between putchar puts stdout
puts(const char*)

------
strcat --> seg fault 
You need a real array of char, or some malloc'ed memory to strcat with
char s[100] = "hello";
strcat( s, " world" );
-----
strcmp(char, char) --> seg fault

————
need dynamic allocation 
---
test macros???
    */
