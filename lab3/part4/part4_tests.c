#include <stdio.h>

#include "checkit.h"
#include "part4.h"

void test_str_1()
{
   char arr[5] = {"OK"};
   char buffer[5] = {};
   strlower(arr, buffer);
   checkit_string(buffer, "ok");
}

void test_str_2()
{
   char arr[20] = {"Nevermind YOYO"};
   char buffer[20];
   strlower(arr, buffer);
   checkit_string(buffer, "nevermind yoyo");
}

void test_str_mutate(){
   char arr[20] = {"Nevermind YOYO"};
   str_lowermutate(arr);
   checkit_string(arr, "nevermind yoyo");
}

void test_str_mutate2(){
   char arr[20] = {"OKAY"};
   str_lowermutate(arr);
   checkit_string(arr, "okay");
}


void test_str()
{
   test_str_1();
   test_str_2();
   test_str_mutate();
   test_str_mutate2();
}

int main(void)
{
   test_str();

   return 0;
}
