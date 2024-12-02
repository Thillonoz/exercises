#include <stdio.h>
#include <math.h>

#define N 64

int main(void)
{

    double moves = pow(2, N) - 1;

    double secondsInAYear = 60 * 60 * 24 * 365.25;

    double years = moves / secondsInAYear;

    (void)printf("Finishing the Hanoi Tower with %d blocks would take %lf years.", N, years);

    return 0;
}