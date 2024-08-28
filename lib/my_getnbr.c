/*
** EPITECH PROJECT, 2023
** LIBMY
** File description:
** my_getnbr
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int neg = 1;
    int result = 0;
    int i = 0;

    for (i; str[i] == '+' || str[i] == '-'; i++)
        if (str[i] == '-')
            neg = neg * -1;
    for (i; str[i] >= '0' && str[i] <= '9'; i++)
        result = result * 10 + str[i] - '0';
    return result * neg;
}
