/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** my_isalphanum
*/

#include "../include/my.h"

bool is_alphanumeric(char *str)
{
    int i = 0;

    while (str != NULL && str[i] != '\0') {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9')) {
            i++;
        } else
            return false;
    }
    return true;
}

bool char_is_alphanumeric(char character)
{
    if ((character >= 'A' && character <= 'Z') ||
        (character >= 'a' && character <= 'z') ||
        (character >= '0' && character <= '9')) {
        return true;
    } else
        return false;
}
