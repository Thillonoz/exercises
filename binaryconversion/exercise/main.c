#include <stdio.h>

int main(){
    int D = 45;
    D = (D & (~(1 << 3))) | (D << 3);
    printf("Answer: %d\n", D);
    return 0;
}