#include "users.h"

uint8_t count = 0;

int main()
{
    bool status = true;
    user_t users[NUMBER_OF_USERS] = {0};
    char choice = '0';
    char updateID = '0';
    uint8_t inputAge = 0;
    uint32_t deleteID = 0;
    char inputName[MAX_NAME_LENGTH] = "";
    char updateName[MAX_NAME_LENGTH] = "";

    while (1)
    {
        (void)printf("======== DB ========\n");
        (void)printf("C) Create A Student\n");
        (void)printf("P) Print All Record\n");
        (void)printf("U) Update A Student\n");
        (void)printf("D) Delete A Student\n");
        (void)printf("E) Exit\n");
        (void)printf("Choose an option: ");
        if (1 != scanf("%c", &choice))
        {
            (void)printf("Invalid choice, try again\n");
            // Clear the input buffer
            clear_ibuffer();
            continue;
        }

        if (choice == 'C' || choice == 'c')
        {
            clear_ibuffer();
            (void)printf("Input name: ");
            while (1 != scanf("%10s", &inputName))
            {
                (void)printf("Too many characters, try again\n");
                clear_ibuffer();
            }
            clear_ibuffer();
            (void)printf("Input age: ");
            while (1 != scanf("%u", &inputAge))
            {
                (void)printf("Invalid input, try again\n");
                clear_ibuffer();
            }
            count++;
            clear_ibuffer();
            if (!fillUser(users, count, inputName, inputAge))
            {
                printf("Failed to fill user.\n");
                if (count > NUMBER_OF_USERS)
                {
                    (void)printf("Trying to create more than allowed users\n");
                    continue;
                }
                
            }
            if (!writeUsers(users, FILENAME, count, inputAge))
            {
                printf("Failed to write user to file.\n");
                clear_ibuffer();
            }
            else
            {
                printf("User added successfully.\n");
            }
        }
        else if (choice == 'P' || choice == 'p')
        {
            clear_ibuffer();

            if (!printUsers(users, count))
            {
                (void)printf("Failed to print users\n");
            }
        }
        else if (choice == 'U' || choice == 'u')
        {
            clear_ibuffer();
            (void)printf("Which user do you want to change? ");
            while (1 != scanf("%u", &updateID))
            {
                (void)printf("Invalid input try again\n");
                clear_ibuffer();
            }
            clear_ibuffer();
            (void)printf("Input new name: ");
            while (1 != scanf("%32s", &inputName))
            {
                (void)printf("Too many characters, try again\n");
                clear_ibuffer();
            }
            clear_ibuffer();
            (void)printf("Input new age: ");
            while (1 != scanf("%u", &inputAge))
            {
                (void)printf("Invalid input, try again\n");
                clear_ibuffer();
            }
            if (!updateUser(users, updateID, inputName, inputAge))
            {
                (void)printf("Failed to update the user.\n");
                clear_ibuffer();
            }
            if (!fillUser(users, updateID, inputName, inputAge))
            {
                printf("Failed to fill user.\n");
                clear_ibuffer();
            }
            clear_ibuffer();
        }
        else if (choice == 'D' || choice == 'd')
        {
            clear_ibuffer();
            (void)printf("Which user do you want to delete? ");
            while (1 != scanf("%u", &deleteID))
            {
                (void)printf("Invalid input try again\n");
                clear_ibuffer();
            }
            clear_ibuffer();
            if (!delete_user(users, deleteID))
            {
                (void)printf("Failed to delete user\n");
                clear_ibuffer();
            }
            *inputName = ' ';
            inputAge = 0;
            if (!fillUser(users, deleteID, inputName, inputAge))
            {
                printf("Failed to fill user.\n");
                clear_ibuffer();
            }
        }
        else if (choice == 'E' || choice == 'e')
        {
            break;
        }
    }

    return 0;
}
