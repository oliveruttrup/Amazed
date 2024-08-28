/*
** EPITECH PROJECT, 2024
** lucas
** File description:
** prints
*/

#include "../include/my.h"

void print_total_robots(int tot_rob)
{
    my_putstr("#number_of_robots\n");
    my_put_nbr(tot_rob);
    my_putchar('\n');
}

void print_rooms(char **arr)
{
    char **arr_words;

    my_putstr("#rooms\n");
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#') {
            check_room_print(arr, i);
            continue;
        }
        arr_words = string_to_array(arr[i], ' ');
        if (arr_words[1] == NULL)
            continue;
        my_putstr(arr[i]);
        my_putchar('\n');
    }
}

void print_tunnels(char **arr)
{
    char **arr_words;

    my_putstr("#tunnels\n");
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            continue;
        arr_words = string_to_array(arr[i], '-');
        if (arr_words[1] == NULL)
            continue;
        my_putstr(arr[i]);
        my_putchar('\n');
    }
}

void print_tunnels_error(char **arr, room_t **rooms)
{
    char **arr_words;

    my_putstr("#tunnels\n");
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            continue;
        arr_words = string_to_array(arr[i], '-');
        if (arr_words[1] == NULL)
            continue;
        if (check_room_existence(arr_words, rooms) == -1) {
            break;
        }
        my_putstr(arr[i]);
        my_putchar('\n');
    }
}
