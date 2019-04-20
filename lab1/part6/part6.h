#ifndef PART5_H
#define PART5_H

struct point
{
   double x;
   double y;
};

struct rectangle
{
   struct point top_left;
   struct point bottom_right;
} rectangle;



struct point create_point(double x, double y);
int is_a_square(struct rectangle rec);
#endif
