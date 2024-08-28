/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** my_putstr_error
*/

#include "../include/my.h"

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

int my_putstr_error(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar_error(str[i]);
        i = i +1;
    }
}
