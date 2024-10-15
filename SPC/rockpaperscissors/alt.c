#include <stdio.h>
#include <string.h>

int main()
{
    char firstChoice[6];
    char secondChoice[6];
    printf("Sten, sax, påse\nSkriv ditt första val: ");
    scanf("%5s", firstChoice);
    printf("Skriv ditt andra val: ");
    scanf("%5s", secondChoice);

    if (strcmp(firstChoice, "sten") == 0 && (strcmp(secondChoice, "sten")) == 0)
    {

        printf("Sten mot sten, oavgjort.\n");
    }
    else if (strcmp(firstChoice, "sten") == 0 && (strcmp(secondChoice, "sax")) == 0)
    {

        printf("Sten mot sax, sten vinner.\n");
    }
    else if (strcmp(firstChoice, "sten") == 0 && (strcmp(secondChoice, "påse")) == 0)
    {

        printf("Sten mot påse, påse vinner.\n");
    }

    if (strcmp(firstChoice, "sax") == 0 && (strcmp(secondChoice, "sten")) == 0)
    {

        printf("Sax mot sten, sten vinner.\n");
    }
    else if (strcmp(firstChoice, "sax") == 0 && (strcmp(secondChoice, "sax")) == 0)
    {

        printf("Sax mot sax, oavgjort.\n");
    }
    else if (strcmp(firstChoice, "sax") == 0 && (strcmp(secondChoice, "påse")) == 0)
    {

        printf("Sax mot påse, sax vinner.\n");
    }

    if (strcmp(firstChoice, "påse") == 0 && (strcmp(secondChoice, "sten")) == 0)
    {

        printf("Påse mot sten, påse vinner.\n");
    }
    else if (strcmp(firstChoice, "påse") == 0 && (strcmp(secondChoice, "sax")) == 0)
    {

        printf("Påse mot sax, sax vinner.\n");
    }
    else if (strcmp(firstChoice, "påse") == 0 && (strcmp(secondChoice, "påse")) == 0)
    {

        printf("Påse mot påse, oavgjort.\n");
    }

    return 0;
}