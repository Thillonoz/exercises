#include "filehandler.h"
#include <stdio.h>

int main()
{
    char name[] = "text.txt";
    createFile(name);

    destroyFile(name);
    return 0;
}