/*
** EPITECH PROJECT, 2024
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** get_rooms
*/

#include "../../include/my.h"

// function to see how many rooms there are
// function to see if there are any start or end rooms
// function to see if repeated start / end
// function to see if repeated IDs / coords
// function to see if there are any tunnels

// after all of that
// count how many rooms there are
// create and fill array of rooms

// tunnels later

// structure for end and start counts

void check_room(char **arr, info_t *info, int i)
{
    if (my_strcmp(arr[i], "##start") == 0)
        info->c_start++;
    if (my_strcmp(arr[i], "##end") == 0)
        info->c_end++;
}

int check_start_end(char **arr, info_t *info)
{
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#') {
            check_room(arr, info, i);
        }
    }
    if (info->c_start != 1 || info->c_end != 1) {
        return -1;
    }
    return 0;
}

int check_numeric_coordinates(char **arr, info_t *info)
{
    char **arr_words;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            continue;
        arr_words = string_to_array(arr[i], ' ');
        if (arr_words[1] == NULL)
            continue;
        if (my_str_isnum(arr_words[1]) == 0 ||
        my_str_isnum(arr_words[2]) == 0) {
            info->coord_count = i;
            return -1;
        }
    }
    return 0;
}

int count_rooms(char **arr)
{
    int total = 0;
    char **arr_words;
    int count = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            continue;
        arr_words = string_to_array(arr[i], ' ');
        if (arr_words[1] == NULL)
            continue;
        count++;
    }
    return count;
}
