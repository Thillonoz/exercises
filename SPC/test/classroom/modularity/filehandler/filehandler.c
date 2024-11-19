#include "filehandler.h"

void createFile(const char *name)
{
    FILE *file = fopen(name, "w");
    if (file == NULL)
    {
        (void)printf("Failed to open the file!\n");
        exit(1);
    }
}

// // Using a for loop write "Hello World!\n" 10 times to the file
// for (int i = 0; i < WRITE_NUM; i++)
// {
//     if (EOF == fputs(STRING, file))
//     {
//         (void)fclose(file);
//         (void)printf("Failed to write to the file!\n");
//         exit(1);
//     }
// }

void destroyFile(const char *fileName)
{

    if (0 != fclose(fileName))
    {
        (void)printf("Failed to close the file!\n");
        exit(1);
    }
}

void openFile(const char *fileName)
{
    FILE *file = fopen(fileName, "r");
    if (file == NULL)
    {
        (void)printf("Failed to open the file!\n");
        exit(1);
    }
}