/*
** EPITECH PROJECT, 2024
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** get_robots
*/

#include "../../include/my.h"

// open file and get only first line
// be aware of comments and non numerical values

int total_robots(char **arr)
{
    int total = 0;
    char **arr_words;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            continue;
        arr_words = string_to_array(arr[i], ' ');
        if (arr_words[1] != NULL || my_str_isnum(arr_words[0]) == 0){
            return -1;
        }
        total = my_getnbr(arr_words[0]);
        return total;
    }
    return -1;
}
