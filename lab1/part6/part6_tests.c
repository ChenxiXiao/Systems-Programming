#include <stdio.h>

#include "checkit.h"
#include "part6.h"

/* define testing functions */
void test_create_point1(void)
{
   struct point p = create_point(1.9, -2.7);

   checkit_double(p.x, 1.9);
   checkit_double(p.y, -2.7);
}

void test_create_point2(void)
{
   struct point p = create_point(0.2, 12.1);

   checkit_double(p.x, 0.2);
   checkit_double(p.y, 12.1);
}

void test_create_point(void)
{
   test_create_point1();
   test_create_point2();
}

void test_rec1(void)
{
   struct point p = create_point(2, 4);
   struct point t = create_point(4, 2);
   struct rectangle rec;
   rec.top_left = p;
   rec.bottom_right = t;
   checkit_boolean(is_a_square(rec), 1);
}

void test_rec2(void)
{
   struct point p = create_point(1, 4);
   struct point t = create_point(4, 2);
   struct rectangle rec;
   rec.top_left = p;
   rec.bottom_right = t;
   checkit_boolean(is_a_square(rec), 0);
}


void test_rec(void)
{
   test_rec1();
   test_rec2();
}

int main(int arg, char *argv[])
{
   /* call testing function(s) here */
   test_create_point();
   test_rec();

   return 0;
}
