#ifndef USERS_H
#define USERS_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 32U
#define NUMBER_OF_USERS 100
#define USER_FORMAT "%d\t%s\t%d\n"
#define FILENAME "users.bin"

typedef struct
{
    char name[MAX_NAME_LENGTH];
    uint32_t id;
    uint8_t age;
} user_t;

/**
 * @brief Function to clear the input buffer
 *
 */
void clear_ibuffer(void);

/**
 * @brief Function to fill users
 *
 * @param user
 * @param ID
 * @param name
 * @param age
 * @return true
 * @return false
 */
bool fillUser(user_t *user, uint32_t ID, const char *name, uint8_t age);

/**
 * @brief Function to print all users
 *
 * @param user
 * @param len
 * @return true
 * @return false
 */
bool printUsers(const user_t *user, uint8_t len);

/**
 * @brief Function to write users to file
 *
 * @param users
 * @param filename
 * @param ID
 * @param age
 * @return true
 * @return false
 */
bool writeUsers(const user_t *users, const char *filename, size_t ID, uint8_t age);

/**
 * @brief Function to update a user in the DB
 *
 * @param id
 * @param name
 * @param age
 * @return true
 * @return false
 */
bool updateUser(user_t *user, size_t ID, const char *name, uint8_t age);

/**
 * @brief Function to delete a user in the DB
 *
 * @param user
 * @param ID
 * @return true
 * @return false
 */
bool delete_user(user_t *user, uint32_t ID);

#endif