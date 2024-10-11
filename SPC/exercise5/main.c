

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

// int countBits(int x);

enum color
{
  RED,
  BLUE,
  GREEN,
  YELLOW,
  WHITE,
  BLACK
};

int main()
{

  printf("Char:\n");

  printf("Size of: %ld\n", sizeof(char));
  printf("Minimum value: %d\n", CHAR_MIN);
  printf("Minimum value: %d\n", CHAR_MAX);

  printf("\nSigned char:\n");

  printf("Size of: %lu\n", sizeof(char));
  printf("Minimum value: %d\n", SCHAR_MIN);
  printf("Maximum value: %d\n", SCHAR_MAX);

  printf("\nUnsigned char:\n");

  printf("Size of: %lu\n", sizeof(unsigned char));
  printf("Minimum value: %d\n", UCHAR_MAX - UCHAR_MAX);
  printf("Maximum value: %d\n", UCHAR_MAX);

  printf("\nSigned int:\n");
  printf("Size of: %ld\n", sizeof(int));
  printf("Minimum value: %d\n", INT_MIN);
  printf("Maximum value: %d\n", INT_MAX);

  printf("\nUnsigned int:\n");
  printf("Size of: %lu\n", sizeof(unsigned int));
  printf("Minimum value: %u\n", UINT_MAX - UINT_MAX);
  printf("Maximum value: %u\n", UINT_MAX);

  /*printf("\nShort:\n");

    printf("Size of: %ld\n", sizeof(short));
    printf("Minimum value: %d\n", -countBits(sizeof(short)));
    printf("Maximum value: %d\n", countBits(sizeof(short)) - 1);
  */
  printf("\nSigned short:\n");

  printf("Size of: %ld\n", sizeof(short));
  printf("Minimum value: %d\n", SHRT_MIN);
  printf("Maximum value: %d\n", SHRT_MAX);

  printf("\nUnsigned short:\n");
  printf("Size of: %lu\n", sizeof(unsigned short));
  printf("Minimum value: %u\n", USHRT_MAX - USHRT_MAX);
  printf("Maximum value: %u\n", USHRT_MAX);

  printf("\nSigned long int:\n");

  printf("Size of: %ld\n", sizeof(long));
  printf("Minimum value: %ld\n", LONG_MIN);
  printf("Maximum value: %ld\n", LONG_MAX);

  printf("\nUnsigned long int:\n");
  printf("Size of: %lu\n", sizeof(unsigned long));
  printf("Minimum value: %lu\n", ULONG_MAX - ULONG_MAX);
  printf("Maximum value: %lu\n", ULONG_MAX);

  printf("\nSigned long long int:\n");

  printf("Size of: %ld\n", sizeof(long long));
  printf("Minimum value: %lld\n", LLONG_MIN);
  printf("Maximum value: %lld\n", LLONG_MAX);

  printf("\nUnsigned long long int:\n");
  printf("Size of: %lu\n", sizeof(unsigned long long));
  printf("Minimum value: %llu\n", ULLONG_MAX - ULLONG_MAX);
  printf("Maximum value: %llu\n", ULLONG_MAX);

  printf("\nFloat:\n");

  printf("Size of: %ld\n", sizeof(float));
  printf("Minimum value: %e\n", FLT_MIN);
  printf("Maximum value: %e\n", FLT_MAX);

  printf("\nDouble:\n");
  printf("Size of: %ld\n", sizeof(double));
  printf("Minimum value: %e\n", DBL_MIN);
  printf("Maximum value: %e\n", DBL_MAX);

  printf("\nLong double:\n");
  printf("Size of: %ld\n", sizeof(long double));
  printf("Minimum value: %Le\n", LDBL_MIN);
  printf("Maximum value: %Le\n", LDBL_MAX);

  printf("\nEnum colors:\n");
  printf("Size of: %ld\n", sizeof(enum color));

  return 0;
}

/*
int countBits(int num)
{
  int x = 1;
  int adding;
  int counting[20];
  int lengthOfLoop = num * 8;
  int pointer;
  for (int i = 0; i < lengthOfLoop; i++)
  {
    counting[0] = 1;
    counting[i + 1] = x * 2;
    adding += counting[i];
    // printf("%d\n", counting[i]);
    x *= 2;
    pointer = counting[i];
  }
  return pointer;
}*/
