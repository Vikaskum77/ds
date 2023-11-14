#include <stdio.h>
#include <string.h>

int main() {

  char string1[10] = "Hello";
  char string2[10] = "World";
  strcat(string1, string2);
  printf("Output string after concatenation: %s", string1);

}
