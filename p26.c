#include <stdio.h>
#include <string.h>

int main() {

  char string1[30] = "I love to write.";
  printf("%s", strchr(string1, 'w'));
}
