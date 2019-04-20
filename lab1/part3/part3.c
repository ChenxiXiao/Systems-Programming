#include "math.h"
#include "part3.h"

double sum(int *array, int x){
    int sum = 0;
    int i;
    for(i = 0; i < x; i++)
    {
        sum += array[i]; 
    }    
    return sum;
}
