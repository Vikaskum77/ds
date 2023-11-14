#include <stdio.h>
#include <string.h>

int main() {

  char s1[20] = "ScalerAcademy";
  char s2[20] = "vikasAcademy.COM";
  /* it only compares first 5 characters of both strings*/
  if (strncmp(s1, s2, 5) == 0) {
    printf("string 1 and string 2 are equal");
  } else {
    printf("string 1 and 2 are different");
  }

}
