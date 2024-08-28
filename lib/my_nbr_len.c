/*
** EPITECH PROJECT, 2023
** MY PRINTF
** File description:
** return nb length
*/

#include "../include/my.h"

int my_nbr_len(int nb)
{
    int count = 1;

    if (nb < 0){
        count++;
    } else {
        nb = nb * - 1;
    }
    for (int i = -10; i >= nb; i = i * 10){
        count++;
    }
    return count;
}
