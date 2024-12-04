#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define MAX_NAME_LENGTH 10U
#define NUMBER_OF_USERS 5U
#define USER_FORMAT "%u: %s\n"
#define FILENAME "users.bin"

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int id;
} user_t;

void clear_ibuffer(void);
static bool fillUser(user_t *user, uint8_t ID, const char *name);
static bool printUsers(user_t *user, size_t length);
bool writeUsers(const user_t *users, const char *filename, size_t ID);
static bool read_user(user_t *user, size_t userID);
static bool update_user(uint32_t id, const char *name);
static bool delete_user(uint32_t id);

int main()
{
    bool status = true;
    user_t users[NUMBER_OF_USERS] = {0};
    char choice = '0';
    uint8_t inputID = 0;
    char inputName[MAX_NAME_LENGTH] = "";
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
                clear_ibuffer();
            }
            count++;

            if (!fillUser(users, 1, "Emil"))
            {
                printf("Failed to fill user.\n");
                break;
            }

            if (!writeUsers(users, FILENAME, 1))
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

            if (read_user(&users[1], 1))
            {
                printUsers(&users[1], 1);
            }
            else
            {
                printf("Failed to read user data. User might not exist.\n");
            }
            break;
        case 4:
            delete_user(1);
            break;

        case 5:
            exit(1);
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
        strncpy(user[ID - 1].name, name, MAX_NAME_LENGTH - 1);
        user[ID - 1].name[MAX_NAME_LENGTH - 1] = '\0'; // Null-terminate
    }
    return status;
}

static bool printUsers(user_t *user, size_t ID)
{
    bool status = false;
    if (user != NULL)
    {
        status = true;
        printf(USER_FORMAT, user->id, user->name);
    }

    return status;
}
// bool writeUsers(const user_t *users, const char *filename, size_t ID)
// {
//     bool status = true;
//     if (users == NULL || filename == NULL || ID < 1 || ID > NUMBER_OF_USERS)
//     {
//         printf("Invalid arguments to writeUsers.\n");
//         status = false;
//     }

//     // Open the file in read+write mode to modify a specific record
//     FILE *file = fopen(filename, "wb+");
//     if (file == NULL)
//     {
//         perror("Failed to open file");
//         status = false;
//     }

//     // Calculate the offset for the user based on the ID
//     size_t offset = ID * sizeof(user_t);

//     // Move the file pointer to the correct position
//     if (fseek(file, offset, SEEK_SET) != 0)
//     {
//         perror("Failed to seek to position");
//         fclose(file);
//         status = false;
//     }

//     // Write the user data
//     if (fwrite(&users[ID - 1], sizeof(user_t), 1, file) != 1)
//     {
//         perror("Failed to write user data");
//         fclose(file);
//         status = false;
//     }

//     fclose(file);
//     return status;
// }

bool writeUsers(const user_t *users, const char *filename, size_t ID)
{
    if (users == NULL || filename == NULL || ID < 1 || ID > NUMBER_OF_USERS)
    {
        printf("Invalid arguments to writeUsers.\n");
        return false;
    }

    FILE *file = fopen(filename, "wb+");
    if (file == NULL)
    {
        perror("Failed to open file");
        return false;
    }

    // Calculate the offset for the user based on the ID
    size_t offset = (ID - 1) * sizeof(user_t);
    if (fseek(file, offset, SEEK_SET) != 0)
    {
        perror("Failed to seek to position");
        fclose(file);
        return false;
    }

    // Serialize the user data
    const user_t *user = &users[ID - 1];
    for (size_t i = 0; i < sizeof(user->id); i++)
    {
        if (fputc(((unsigned char *)&user->id)[i], file) == EOF)
        {
            perror("Failed to write user ID");
            fclose(file);
            return false;
        }
    }

    for (size_t i = 0; i < MAX_NAME_LENGTH; i++)
    {
        if (fputc(users[ID - 1].name[i], file) == EOF)
        {
            perror("Failed to write user name");
            fclose(file);
            return false;
        }
    }

    fclose(file);
    return true;
}
static bool read_user(user_t *user, size_t userID)
{
    if (user == NULL || userID < 1 || userID > NUMBER_OF_USERS)
    {
        printf("Invalid ID. Must be between 1 and %u.\n", NUMBER_OF_USERS);
        return false;
    }

    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Failed to open file for reading");
        return false;
    }

    // Calculate the offset for the user based on the ID
    size_t offset = (userID - 1) * sizeof(user_t);
    if (fseek(file, offset, SEEK_SET) != 0)
    {
        perror("Failed to seek to user position");
        fclose(file);
        return false;
    }

    // Deserialize the user data
    for (size_t i = 0; i < sizeof(user->id); i++)
    {
        int byte = fgetc(file);
        if (byte == EOF)
        {
            perror("Failed to read user ID");
            fclose(file);
            return false;
        }
        ((unsigned char *)&user->id)[i] = (unsigned char)byte;
    }

    for (size_t i = 0; i < MAX_NAME_LENGTH; i++)
    {
        int byte = fgetc(file);
        if (byte == EOF)
        {
            perror("Failed to read user name");
            fclose(file);
            return false;
        }
        user->name[i] = (char)byte;
    }
    user->name[MAX_NAME_LENGTH - 1] = '\0'; // Null-terminate
    fclose(file);
    return true;
}

// static bool read_user(user_t *user, size_t userID)
// {
//     bool status = true;

//     if ((user == NULL) || (userID == 0))
//     {
//         status = false;
//     }
//     else
//     {
//         FILE *file = fopen(FILENAME, "rb");
//         if (file == NULL)
//         {

//             status = false;
//         }
//         else
//         {
//             // Calculate the offset based on the user ID
//             size_t offset = (userID - 1) * sizeof(user_t);

//             (void)memset(user, 0, sizeof(user_t));

//             // Seek to the user's location in the file
//             if (fseek(file, offset, SEEK_SET) != 0)
//             {
//                 perror("Failed to seek in file");
//                 fclose(file);
//                 status = false;
//             }

//             // Read the user data into the provided user_t pointer
//             if (fread(user, sizeof(user_t), 1, file) != 1)
//             {
//                 perror("Failed to read user data");
//                 fclose(file);
//                 status = false;
//             }
//         }
//         for (size_t i = 0; i < MAX_NAME_LENGTH; i++)
//         {
//             (void)printf(USER_FORMAT, user[userID].id, user[userID].name[i]);
//         }
//         fclose(file);
//     }

//     return status;
// }

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

static bool delete_user(uint32_t id)
{
    if (id < 1 || id > NUMBER_OF_USERS)
    {
        printf("Invalid ID. Must be between 1 and %u.\n", NUMBER_OF_USERS);
        return false;
    }

    // Open the file in read mode
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Failed to open file for reading");
        return false;
    }

    // Load all users into memory
    user_t users[NUMBER_OF_USERS] = {0};
    size_t numUsers = fread(users, sizeof(user_t), NUMBER_OF_USERS, file);
    fclose(file);

    if (numUsers == 0)
    {
        printf("No users found in the file.\n");
        return false;
    }

    // Create a new array excluding the deleted user
    user_t updatedUsers[NUMBER_OF_USERS] = {0};
    size_t updatedCount = 0;
    for (size_t i = 0; i < numUsers; i++)
    {
        if (users[i].id != id)
        {
            updatedUsers[updatedCount++] = users[i];
        }
    }

    // Check if the user was found and deleted
    if (updatedCount == numUsers)
    {
        printf("User with ID %u not found.\n", id);
        return false;
    }

    // Write the updated user list back to the file
    file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
        perror("Failed to open file for writing");
        return false;
    }

    if (fwrite(updatedUsers, sizeof(user_t), updatedCount, file) != updatedCount)
    {
        perror("Failed to write updated user data");
        fclose(file);
        return false;
    }

    fclose(file);
    printf("User with ID %u successfully deleted.\n", id);
    return true;
}