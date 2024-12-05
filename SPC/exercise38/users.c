#include "users.h"

void clear_ibuffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

bool fillUser(user_t *user, uint32_t ID, const char *name, uint8_t age)
{
    bool status = true;
    if (user == NULL || name == NULL || ID >= NUMBER_OF_USERS)
    {
        (void)printf("Failing here.\n");
        status = false;
    }
    else
    {
        user[ID].id = ID;
        strncpy(user[ID].name, name, MAX_NAME_LENGTH);
        user[ID].age = age;
    }
    return status;
}

bool printUsers(const user_t *users, uint8_t len)
{
    bool status = false;
    (void)printf("====================\n");
    (void)printf("ID\tName\tAge\n");
    if (users != NULL && len > 0)
    {
        status = true;
        for (size_t i = 1; i <= len; i++)
        {
            if (*users[i].name == ' ' || users[i].age == 0)
            {
                continue;
            }

            (void)printf(USER_FORMAT, users[i].id, users[i].name, users[i].age);
        }
    }
    (void)printf("\n");
    return status;
}

bool writeUsers(const user_t *users, const char *filename, size_t ID, uint8_t age)
{
    bool status = true;
    if (users == NULL || filename == NULL || ID < 1 || ID > NUMBER_OF_USERS)
    {
        (void)printf("Invalid arguments to writeUsers.\n");
        status = false;
    }

    FILE *file = fopen(filename, "wb+");
    if (file == NULL)
    {
        (void)printf("Failed to open file");
        status = false;
    }

    // Calculate the offset for the user based on the ID
    size_t offset = ID * sizeof(user_t);
    if (fseek(file, offset, SEEK_SET) != 0)
    {
        (void)printf("Failed to seek to position");
        fclose(file);
        status = false;
    }

    fwrite(&users[ID], sizeof(user_t), ID, file);

    fclose(file);
    return status;
}

bool updateUser(user_t *user, size_t ID, const char *name, uint8_t age)
{
    bool status = true;
    if ((name == NULL) || (ID == 0))
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
            while (0 == feof(file))
            {
                long int pos = ftell(file);

                if (1 != fread(user, sizeof(user_t), 1, file))
                {
                    status = false;
                    break;
                }

                if (user[ID].id == ID)
                {
                    strncpy(user[ID].name, name, MAX_NAME_LENGTH);
                    user[ID].age = age;
                    if (0 != fseek(file, pos, SEEK_SET))
                    {
                        status = false;
                    }
                    else
                    {
                        if (1 != fwrite(user, sizeof(user_t), 1, file))
                        {
                            status = false;
                        }
                    }
                    break;
                }
            }
            fclose(file);
        }
    }

    return status;
}
bool delete_user(user_t *user, uint32_t ID)
{
    bool status = true;
    if (ID < 1 || ID > NUMBER_OF_USERS)
    {
        (void)printf("Invalid ID. Must be between 1 and %u.\n", NUMBER_OF_USERS);
        status = false;
    }

    // Open the file in read mode
    FILE *file = fopen(FILENAME, "rb");
    if (file == NULL)
    {
        perror("Failed to open file for reading");
        status = false;
    }

    // Load all users into memory
    user_t users[NUMBER_OF_USERS] = {0};
    size_t numUsers = fread(users, sizeof(user_t), NUMBER_OF_USERS, file);
    fclose(file);

    if (numUsers == 0)
    {
        printf("No users found in the file.\n");
        status = false;
    }

    // Create a new array excluding the deleted user
    user_t updatedUsers[NUMBER_OF_USERS] = {0};
    size_t updatedCount = 0;
    for (size_t i = 0; i < numUsers; i++)
    {
        if (users[i].id != ID)
        {
            updatedUsers[updatedCount++] = users[i];
        }
    }

    // Write the updated user list back to the file
    file = fopen(FILENAME, "wb");
    if (file == NULL)
    {
        perror("Failed to open file for writing");
        status = false;
    }

    if (fwrite(updatedUsers, sizeof(user_t), updatedCount, file) != updatedCount)
    {
        perror("Failed to write updated user data");
        fclose(file);
        status = false;
    }

    fclose(file);
    (void)printf("User with ID %u successfully deleted.\n", ID);
    return status;
}