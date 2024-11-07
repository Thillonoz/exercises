#include <stdio.h>

// Define the correct format
#define FORMAT "YYYYMMDD-NNNN"
#define PERS_NUM_LEN 10

int main(void)
{
    // Hardcode the number at first
    int personNummer[10] = {9, 2, 0, 8, 0, 7, 0, 7, 1, 5};
    int doubleCheck[10] = {8, 1, 1, 2, 1, 8, 9, 8, 7, 6};
    printf("To check the array ");
    for (int i = 0; i < PERS_NUM_LEN; i++)
    {
        printf("%d", personNummer[i]);
    }
    printf("\n");
    // Arithmetic for checking the personnummer
    for (int i = 0; i < PERS_NUM_LEN; i++)
    {
        if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8)
        {
            doubleCheck[i] *= 2;
        }
        else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9)
        {
            doubleCheck[i] *= 1;
        }
    }
    /*          THIS IS TO CHECK THE ARRAY IF IT'S WHAT'S EXPECTED
        printf("To check if the array is changed to what's expected ");
        for (int i = 0; i < PERS_NUM_LEN ; i++)
        {
            printf("%d", personNummer[i]);
        }

        printf("\n");
    */
    double divideTen = 0.0;
    int sum = 0;
    /* divideTen = personNummer[0] / 10.0;

     sum += (int)divideTen;
     divideTen -= 1.0;
     divideTen *= 10;
     sum += (int)divideTen;*/

    for (int i = 0; i < PERS_NUM_LEN - 1; i++)
    {
        if (doubleCheck[i] > 10)
        {
            divideTen = 0.0;
            divideTen = doubleCheck[i] / 10.0;
            sum += (int)divideTen;
            divideTen -= 1.0;
            divideTen *= 10.0;

            sum += (int)divideTen;
        }
        else
        {
            sum += doubleCheck[i];
        }
    }

    sum = (10 - (sum % 10)) % 10;
    // sscanf for formatted input

    // call to function checking input

    // display output

    printf("%d", sum);

    printf("\n");

    return 0;
}