#include<stdio.h>
#include<string.h>
int main()
{
   char str[20] = "Test String";
   printf("Original string is : %s", str);
   printf("Test string after strset() : %s",strset(str,'#'));
   printf("After string set: %s",str);
   return 0;
}