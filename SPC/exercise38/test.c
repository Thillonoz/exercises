#include <stdio.h>

typedef struct
{
    char name[10];
    int id;
} user_t;

int main(void)
{
    user_t users[5] = {0};
    user_t buffer[10];
    char username[10] = "Emil";
    user_t user1;
    user1.id = 1;
    for (size_t i = 0; i < 10; i++)
    {
        user1.name[i] = username[i];
    }

    printf("%d : %s\n", user1.id, user1.name);

    FILE *filewrite = fopen("test.bin", "wb");
    if (filewrite == NULL)
    {
        printf("Failed to open for write.\n");
    }

    fwrite(users, sizeof(user_t), 1, filewrite);
    fclose(filewrite);

    FILE *fileread = fopen("test.bin", "rb");
    if (fileread == NULL)
    {
        printf("Failed to open for read.\n");
    }
    fread(&buffer, sizeof(user_t), 1, fileread);
    fgetc(fileread);
    fclose(fileread);

    printf("%s\n", buffer);

    return 0;
}