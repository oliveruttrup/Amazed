/*
** EPITECH PROJECT, 2023
** MY_PUTSTR
** File description:
** task02
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0'){
        my_putchar(str[i]);
        i = i +1;
    }
}
