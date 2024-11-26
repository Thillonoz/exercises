#include <stdio.h>
#include "module.h"

void module_print_int(int x){
    printf("X = %d\n", x);
}

void module_print_string(const char *str){
    printf("X = %s\n", str);
}