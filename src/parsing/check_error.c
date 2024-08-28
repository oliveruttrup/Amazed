/*
** EPITECH PROJECT, 2024
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** check_error
*/

#include "../../include/my.h"

void check_room_print(char **arr, int i)
{
    if (my_strcmp(arr[i], "##start") == 0)
        my_putstr("##start\n");
    if (my_strcmp(arr[i], "##end") == 0)
        my_putstr("##end\n");
}

void print_rooms_error(char **arr, int limit)
{
    char **arr_words;

    my_putstr("#rooms\n");
    for (int i = 0; i < limit; i++) {
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

int total_rooms(char **arr, info_t *info)
{
    int total_rooms = 0;

    if (check_numeric_coordinates(arr, info) == -1) {
        print_rooms_error(arr, info->coord_count);
        return -1;
    }
    if (check_start_end(arr, info) == -1) {
        print_rooms(arr);
        return -1;
    }
    total_rooms = count_rooms(arr);
    return total_rooms;
}

    // if (check_room_total_elements(arr) == -1)
    //     return -1; assume that's good for the moment
