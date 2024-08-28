/*
** EPITECH PROJECT, 2024
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** get_tunels
*/

#include "../../include/my.h"

// iterate through the file
// for each tunel, connect the rooms
// write the tunel to a file

// Error handling cases:
// No tunnels to start or end rooms | first
// If return value is -1, print until tunnel_count
// Else return 0 and tunnel count, used for connecting

// Tunnels to inexistent rooms | second
// If return value is -1, print until tunnel_count
// Else return 0 and tunnel count, used for connecting

// Tunnels to the same room | third
// Authorized, just skip it

// No path to start to end -> Lucas alg enc path
// Just print everything

static int check_room_name(char *room_name, room_t **rooms)
{
    for (int j = 0; rooms[j] != NULL; j++) {
        if (my_strcmp(room_name, rooms[j]->r_name) == 0) {
            return 1;
        }
    }
    return 0;
}

int check_room_existence(char **arr_words, room_t **rooms)
{
    int found = 0;

    for (int k = 0; arr_words[k] != NULL; k++) {
        found = check_room_name(arr_words[k], rooms);
        if (found == 0) {
            return -1;
        }
    }
    return 0;
}

int count_tunnels(char **arr)
{
    int total = 0;
    char **arr_words;
    int count = 0;

    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            continue;
        arr_words = string_to_array(arr[i], '-');
        if (arr_words[1] == NULL)
            continue;
        count++;
    }
    return count;
}

// int check_tunnel_validity(char **arr_words, room_t **rooms)
// {
//     int start_found = 0;
//     int end_found = 0;
//     for (int k = 0; arr_words[k] != NULL; k++) {
//         for (int j = 0; rooms[j] != NULL; j++) {
//             if (my_strcmp(arr_words[k], rooms[j]->r_name) == 0) {
//                 if (rooms[j]->status == START)
//                     start_found = 1;
//                 else if (rooms[j]->status == END)
//                     end_found = 1;
//             }
//         }
//     }
//     if (start_found == 0 || end_found == 0) {
//         printf("Tunnels do not include a room with status START or END\n");
//         return -1;
//     }
//     return 0;
// }
int existence_condition(char **arr_words, room_t **rooms, info_t *info)
{
    if (check_room_existence(arr_words, rooms) == -1) {
        if (info->tot_tunnels == 0)
            return 0;
        return -1;
    }
    return 1;
}

int process_file(char **arr, room_t **rooms, info_t *info)
{
    int i = 0;
    int tunnel_count = 0;
    char **arr_words;
    int condition = 0;

    for (i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#')
            continue;
        arr_words = string_to_array(arr[i], '-');
        if (arr_words[1] == NULL)
            continue;
        condition = existence_condition(arr_words, rooms, info);
        if (condition <= 0)
            return condition;
        info->tot_tunnels++;
    }
    return info->tot_tunnels;
}


// if (check_room_existence(arr_words, rooms) == -1 /*||
// check_tunnel_validity(arr_words, rooms) == -1*/) {
