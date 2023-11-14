#include <stdio.h>
#include <string.h>

int main() {

  char string1[20] = "ScalerAcademy";
  printf("Length of string string1 when maxlen is 25: %d \n", strnlen(string1, 25));
  printf("Length of string string1 when maxlen is 5: %d", strnlen(string1, 5));
}
