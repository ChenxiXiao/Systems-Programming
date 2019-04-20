/******************************************************************************
copy string
*******************************************************************************/
#include <string.h>
#include <stdio.h>
char* copy(char *);
int main()
{
    char *str = "yoyo check it\n";
    char *new;
    new = copy(str);
    printf("%s", new);
    return 0;
}

char* copy(char *string){
    const size_t len = strlen(string) + 1; /*empty \0 */
    char *new = (char *)malloc(len);
    strncpy(new, string, len);
    return new;
}

/******************************************************************************
Translate
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void trans(char *, char *);
void escape(char *, int *);

int main()
{
    
    char *set1, *set2;
    printf("started\n");
    set1 = "abcde";
    set2 = "de";
    trans(set1, set2);
    printf("ended\n");
    
    return 1;
}

void trans(char *set1, char *set2){
    int size_set1, size_set2, i, j; 
    char c; 
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
        for(j = 0; j < size_set1; j++){
         
            if(c == set1[j]){
                putchar(set2[j]);
                break;
            }   
            if(j == (size_set1-1)){
                putchar(c); 
            }
        }
    }
    putchar('\n');
    return;
}

void escape(char *set, int *size){
    /* tackle with sets other than single character entries */
    /* expected return: amended set and size */
    int i;
    for(i = 0; i < *size; i++){
        if(set[i] == '\\'){
            *size--;
            switch(set[++i]){
            case 'n':
                set[i] = '\n';
                break;
            case 't':
                set[i] = '\t';
                break;
            default:
            /* if \ is followed by any other char, tr will ignore \ and delete it from set  */
                set[i] = '\\';
                break;
            }
        }
    }
}
    

