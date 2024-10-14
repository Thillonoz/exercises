#include <stdio.h>
#include <ctype.h>

int main()
{
  char input;
  int checkSpace = 1;

  printf("Enter your full name: \n");

  while ((input = getchar()) != '\n')
  {
    if (isalpha(input))
    {
      if (checkSpace)
      {
        putchar(toupper(input));
        checkSpace = 0;
      }
      else
      {
        putchar(tolower(input));
      }
    }
    else if (input == ' ')
    {
      if (!checkSpace)
      {
        putchar(' ');
        checkSpace = 1;
      }
    }
  }

  putchar('/n');
  return 0;
}