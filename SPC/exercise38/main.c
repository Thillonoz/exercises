#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAX_NAME_LENGTH 10U
#define NUMBER_OF_USERS 5U
#define USER_FORMAT "%d: %s\n"
#define FILENAME "users.bin"

const char *names[] = {"Emil", "Jesper", "Casper", "Perra", "Erik"};

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int id;
} user_t;

void clear_ibuffer(void);
static bool fillUser(user_t *user, uint8_t ID, const char *name);
static bool printUsers(const user_t *user, size_t length);
static bool writeUsers(const user_t *user, const char *name);
static bool read_user(user_t *user, size_t userID);
static bool update_user(uint32_t id, const char *name);

int main()
{
    bool status = true;
    user_t users[NUMBER_OF_USERS] = {0};
    char choice = '0';
    char inputID = '0';
    char inputName = '0';
    char name[MAX_NAME_LENGTH] = "";
    uint8_t count = 0;

    do
    {
        (void)printf("Student Record Management\n\n");
        (void)printf("1.Create Student Record\n");
        (void)printf("2.Read Student Record\n");
        (void)printf("3.Update Student Record\n");
        (void)printf("4.Delete Student Record\n");
        (void)printf("5.Exit\n");
        if (1 != scanf("%d", &choice))
        {
            (void)printf("Invalid choice, try again\n");
            // Clear the input buffer
            clear_ibuffer();
            continue;
        }

        switch (choice)
        {
        case 1:
            clear_ibuffer();
            (void)printf("Input ID (1-5)\n");
            while (1 != scanf("%d", &inputID))
            {
                (void)printf("Only input 1-5 is valid\n");
                clear_ibuffer();
            }
            clear_ibuffer();
            (void)printf("Input name\n");
            while (1 != scanf("%10s", &inputName))
            {
                (void)printf("Too many characters, try again\n");
                // Clear the input buffer
                clear_ibuffer();
            }
            count++;

            if (!fillUser(users, inputID, &inputName))
            {
                printf("Failed to fill user.\n");
                break;
            }

            if (!writeUsers(&users[inputID], FILENAME))
            {
                printf("Failed to write user to file.\n");
            }
            else
            {
                printf("User added successfully.\n");
            }
            break;

        case 2:
            clear_ibuffer();
            printf("Which ID to read? (1-5):\n");
            while (scanf("%d", &inputID) != 1)
            {
                printf("Invalid ID. Must be between 1 and 5.\n");
                clear_ibuffer();
            }

            if (read_user(&users[inputID], inputID))
            {
                printUsers(&users[inputID], inputID);
            }
            else
            {
                printf("Failed to read user data. User might not exist.\n");
            }
            break;

        default:
            (void)printf("Only input 1-5 is valid\n");
            status = false;
            break;
        }
    } while (status == true);

    return 0;
}

void clear_ibuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

static bool fillUser(user_t *user, uint8_t ID, const char *name)
{
    bool status = true;
    ID = ID - 1;
    if (user == NULL || name == NULL || ID >= NUMBER_OF_USERS)
    {
        status = false;
    }
    else
    {
        user->id = ID;
        strncpy(user->name, name, MAX_NAME_LENGTH);
    }
    return status;
}

static bool printUsers(const user_t *user, size_t ID)
{
    bool status = false;
    ID = ID - 1;
    if (user != NULL)
    {
        status = true;

        (void)printf(USER_FORMAT, user[ID].id, user[ID].name);
    }

    return status;
}

bool writeUsers(const user_t *user, const char *filename)
{
    bool status = true;
    if (user == NULL || filename == NULL)
    {
        status = false;
    }
    FILE *file = fopen(FILENAME, "ab");
    if (file == NULL)
    {
        status = false;
    }
    else
    {
        (void)memset(user, 0, sizeof(user_t));
        if (fwrite(user, sizeof(user_t), 1, file))
        {
            status = false;
        }
    }
    fclose(file);
    return status;
}

static bool read_user(user_t *user, size_t userID)
{
    bool status = true;

    if ((user == NULL) || (userID == 0))
    {
        status = false;
    }
    else
    {
        FILE *file = fopen(FILENAME, "rb");
        // Calculate the offset based on the user ID
        size_t offset = (userID - 1) * sizeof(user_t);

        (void)memset(user, 0, sizeof(user_t));

        // Seek to the user's location in the file
        if (fseek(file, offset, SEEK_SET) != 0)
        {
            perror("Failed to seek in file");
            status = false;
        }

        // Read the user data into the provided user_t pointer
        if (fread(user, sizeof(user_t), 1, file) != 1)
        {
            perror("Failed to read user data");
            status = false;
        }
        fclose(file);
    }

    return status;
}

static bool update_user(uint32_t id, const char *name)
{
    bool status = true;
    if ((name == NULL) || (id == 0))
    {
        status = false;
    }
    else
    {
        FILE *file = fopen(FILENAME, "r+b");

        if (file == NULL)
        {
            status = false;
        }
        else
        {
            user_t user = {0};
            while (0 == feof(file))
            {
                long int pos = ftell(file);

                if (1 != fread(&user, sizeof(user_t), 1, file))
                {
                    status = false;
                    break;
                }

                if (user.id == id)
                {
                    (void)strncpy(user.name, name, MAX_NAME_LENGTH);
                    if (0 != fseek(file, pos, SEEK_SET))
                    {
                        status = false;
                    }
                    else
                    {
                        if (1 != fwrite(&user, sizeof(user_t), 1, file))
                        {
                            status = false;
                        }
                    }
                    break;
                }
            }

            (void)fclose(file);
        }
    }

    return status;
}