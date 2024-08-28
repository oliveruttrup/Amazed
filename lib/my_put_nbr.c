/*
** EPITECH PROJECT, 2023
** MY_PUT_NBR
** File description:
** task07
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0){
        my_putchar('-');
    } else {
        nb = nb * - 1;
    }
    if (nb <= -10){
        my_put_nbr(nb / -10);
    }
    my_putchar(nb % 10 * - 1 + '0');
}

int my_put_nbr_count(int nb, int *count)
{
    if (nb < 0){
        my_putchar('-');
        (*count)++;
    } else {
        nb = nb * - 1;
    }
    if (nb <= -10){
        my_put_nbr_count(nb / -10, count);
    }
    my_putchar(nb % 10 * - 1 + '0');
    (*count)++;
}
