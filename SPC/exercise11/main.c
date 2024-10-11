#include <stdio.h>

int main() {
  int ch;
  int numch = 0;

  while (1) {
    ch = getchar();
    if (ch == '\n') {
      break;
    }
    numch++;
  }

  printf("%d\n", numch);
  return 0;
}