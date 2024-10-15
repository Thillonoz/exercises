#include <stdio.h>

int main()
{
    int firstChoice = 0;
    int secondChoice = 0;
    printf("1. Sten\n2. Sax\n3. Påse\nSkriv ditt första val: ");
    scanf("%d", &firstChoice);
    printf("Skriv ditt andra val: ");
    scanf("%d", &secondChoice);

    switch (firstChoice)
    {
    case 2: // sax
        switch (secondChoice)
        {
        case 2: // sax
            printf("Sax mot sax, oavgjort.\n");
            break;
        case 3: // påse
            printf("Sax mot påse, sax vinner.\n");
            break;

        default: // sten
            printf("Sax mot sten, sten vinner.\n");
            break;
        }
        break;

    case 3: // påse
        switch (secondChoice)
        {
        case 2: // sax
            printf("Påse mot sax, sax vinner.\n");
            break;
        case 3: // påse
            printf("Påse mot påse, oavgjort.\n");
            break;

        default: // sten
            printf("Påse mot sten, påse vinner.\n");
            break;
        }
        break;

    default: // sten
        switch (secondChoice)
        {
        case 2: // sax
            printf("Sten mot sax, sten vinner.\n");
            break;
        case 3: // påse
            printf("Sten mot påse, påse vinner.\n");
            break;

        default: // sten
            printf("Sten mot sten, oavgjort.\n");
            break;
        }
        break;
    }

    return 0;
}