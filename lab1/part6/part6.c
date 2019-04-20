#include "part6.h"
#include <stdio.h>
#include <stdlib.h>

struct point create_point(double x, double y)
{
   struct point p = {x, y};
   return p;
}

int is_a_square(struct rectangle rec){
   if (abs(rec.top_left.x - rec.bottom_right.x) == abs(rec.top_left.y - rec.bottom_right.y)){
      return 1;
   }
   return 0;
}