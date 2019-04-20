#include <stdio.h>

#include "checkit.h"
#include "part3.h"

void test_sum_1()
{
   int arr[4] = {10,20,30,40};
   checkit_int(sum(arr, 4), 100);
}

void test_sum_2()
{
   int arr[7] = {0, 5, 7, 5, 10, 2, 1};
   checkit_int(sum(arr, 7), 30);
}


void test_sum()
{
   test_sum_1();
   test_sum_2();
}

int main(void)
{
   test_sum();

   return 0;
}
