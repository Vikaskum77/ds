#include <stdio.h>
#include <string.h>

int main() {

  char s1[35] = "string 1"; // string1
  char s2[35] = "I'll be copied to string 1."; // string2
  strcpy(s1, s2); // copying string2 to string1
  printf("String s1 is: %s", s1); // printing string1

}
