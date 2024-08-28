/*
** EPITECH PROJECT, 2023
** setting_up
** File description:
** my_strcpy.c
*/

#include "../include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int a = 0;

    while (*src != '\0') {
        dest[a] = *src;
        a++;
        src++;
    }
    dest[a] = '\0';
    return (dest);
}
