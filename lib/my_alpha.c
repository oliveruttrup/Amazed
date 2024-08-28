/*
** EPITECH PROJECT, 2023
** epitech
** File description:
** my_str_isalpha.c
*/

#include "../include/my.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z' ||
            str[i] >= 'a' && str[i] <= 'z') {
            i++;
        } else
            return 0;
    }
    return 1;
}
