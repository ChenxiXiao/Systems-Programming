#include <stdio.h>
#include "checkit.h"
#include "swap.h"

void test_int1()
{
   int x = 5, y = 4;

   swap(&x,&y);

   checkit_int(x, 4);
   checkit_int(y, 5);
}

void test_int2()
{
    int x = 10, y = 0;

   swap(&x,&y);

   checkit_int(x, 0);
   checkit_int(y, 10);
}



void test_swap()
{
   test_int1();
   test_int2();
}

int main(void)
{
   test_swap();

   return 0;
}
