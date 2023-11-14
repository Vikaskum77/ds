#include <stdio.h>
#include <string.h>

int main () {

     char string1[10] = "Hello";
     char string2[10] = "World";
     strncat(string1,string2, 3);
     printf("Concatenation using strncat: %s", string1);

     
}
