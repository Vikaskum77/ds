#include <stdio.h>
#include <string.h>

int main() {

  char string1[30] = "string 1";
  char string2[40] = "Only 12 characters will be copied.";
  strncpy(string1, string2, 12);
  printf("String s1 is: %s", string1);
}
