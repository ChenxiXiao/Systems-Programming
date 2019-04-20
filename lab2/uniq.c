/*
Function: a filter, removing adjacent duplicate line that is identical
to the previous line will be discarded rather than copied to stdout.

No limits on file size or line length.

function char *read long line(FILE *file) 
-- will read an arbitrarily long line from the given file into newly-allocated space.
-- Be careful to free memory once you are done with it.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
char *readlongline(FILE *);

int main(int argc, char *argv[]) {
    FILE *fp = fopen(argv[1], "w");
    char *line, *prev = NULL;
    if(argc <= 1){
        /*take in lines on terminal */
            fprintf(stderr, "uniq: not enough arguments\n");
            exit(2);
    }
    else{
        if(fp  == NULL){
            fprintf(stderr, "uniq: can't open %s\n", argv[0]);
            exit(1);
        }
        else{
            while(!feof(fp)){
                /* tests the end-of-file indicator for the given stream.
                return non zero if EOF */
                line = readlongline(fp);
                if(strcmp(prev,line)){
                    /*shallow copy forbidden*/
                   fprintf(stdout,"%s", line);
                }
                strcpy(prev,line);

            }

        }
    }


    return 0;
}

char *readlongline(FILE *file){
    /*read arbitrarily long line from given file into newly allocated space*/
    char c = getc(file);
    int i;
    char *new, *line;
    char *str = (char *)malloc(sizeof(char) * SIZE);
    int size = SIZE;
    while ((c != '\n') && (c != EOF)) {
        if(i == size){
            /*reallocate*/
            size += SIZE; /*new size(+ 100)*/
            new = realloc(str, size);
            if(new == NULL){
                perror("safe_realloc");
                exit(3);
            }
            str = new; 
        }
        str[i] = c;
        i++;
        c = getc(file);
    }
    str[i] = '\0';
    line = str;
    free(str);
    return line;
}    
