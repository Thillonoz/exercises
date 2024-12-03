#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 8
#define NUMBER_OF_USERS 5

const char *names[] = {"Emil", "Jesper", "Casper", "Perra", "Erik"};

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int id;
} user_t;

void fillUsers(user_t users[]);
void generate_random_name(char *name);
void printUser(user_t user);
void writeBinary(user_t *user);

int main()
{
    srand(time(NULL));
    user_t users[NUMBER_OF_USERS];

    fillUsers(users);

    for (size_t i = 0; i < NUMBER_OF_USERS; i++)
    {
        printUser(users[i]);
    }

    writeBinary(users);

    return 0;
}

void fillUsers(user_t users[])
{
    // srand(time(NULL));
    // int random = rand;
    for (size_t i = 0; i < NUMBER_OF_USERS; i++)
    {
        generate_random_name(users[i].name);
        users[i].id = i + 1;
    }
}

void generate_random_name(char *name)
{

    // char generateName[MAX_NAME_LENGTH] = name[i];

    for (int i = 0; i < MAX_NAME_LENGTH; i++)
    {
        name[i] = 'A' + rand() % 26; // Random uppercase letter
    }
}

void printUser(user_t user)
{
    (void)printf("%s, %d\n", user.name, user.id);
}

void writeBinary(user_t *user)
{
    char buffer[100];

    FILE *fptr = fopen("users.bin", "wb");
    fwrite(user, MAX_NAME_LENGTH, sizeof(user_t) - 5, fptr);
    fclose(fptr);
    FILE *fptr1 = fopen("users.bin", "rb");

    fread(user, MAX_NAME_LENGTH, sizeof(user_t), fptr);

    fclose(fptr);
}