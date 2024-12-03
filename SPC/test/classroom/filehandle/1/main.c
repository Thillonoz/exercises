#include <stdio.h>

int main(void)
{

    char buffer[100];
    char buffer1[100];
    FILE *firstFile = fopen("example", "w");
    FILE *secondFile = fopen("test", "a");

    if (firstFile == NULL)
    {
        printf("Could not write to file.\n");
        return 0;
    }

    if (EOF == fputs("Hello World!", firstFile))
    {
        fclose(firstFile);
        printf("Failed to write to text.txt\n");
        return 0;
    }

    rewind(firstFile);

    firstFile = fopen("example", "r");

    fgets(buffer, 100, firstFile);

    puts(buffer);

    fputs(buffer, secondFile);

    if (EOF == fclose(firstFile))
    {
        printf("Failed to close\n");
        return 0;
    }
    rewind(secondFile);
    secondFile = fopen("test", "r");

    fgets(buffer, 100, secondFile);

    puts(buffer);

    if (EOF == fclose(secondFile))
    {
        printf("Failed to close text.txt\n");
        return 0;
    }

    if (rename("example", "new") != 0)
    {
        printf("Failed to rename the file\n");
    }

    return 0;
}