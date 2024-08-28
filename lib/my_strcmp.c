/*
** EPITECH PROJECT, 2024
** My_strcmp
** File description:
** strcmp function
*/

#include "../include/my.h"

int my_strcmp(const char *s1, char const *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(unsigned char *)s1 - *(unsigned char *)s2;
}
