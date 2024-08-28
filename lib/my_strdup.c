/*
** EPITECH PROJECT, 2023
** MY_STRDUP
** File description:
** task01
*/

#include "../include/my.h"

char *my_strdup(char const *str)
{
    char *result = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int n = 0; n <= my_strlen(str) + 1; n++){
        result[n] = '\0';
    }
    for (int i = 0; i <= my_strlen(str); i++){
        result[i] = str[i];
    }
    return result;
}
