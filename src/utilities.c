/*
** EPITECH PROJECT, 2024
** lucas
** File description:
** utilities
*/

#include "../include/my.h"

int array_len(char **arr)
{
    int i = 0;

    while (arr[i] != NULL)
        i++;
    return i;
}

void print_room_array(room_t **rooms)
{
    for (int i = 0; rooms[i] != NULL; i++) {
        my_putstr(rooms[i]->r_name);
        my_putchar(' ');
        my_put_nbr(rooms[i]->x);
        my_putchar(' ');
        my_put_nbr(rooms[i]->y);
        my_putchar(' ');
        my_put_nbr(rooms[i]->status);
        my_putchar('\n');
    }
}

void print_room_and_connected_rooms(room_t **rooms)
{
    tunnel_t *current_tunnel;

    for (int i = 0; rooms[i] != NULL; i++) {
        my_putstr(rooms[i]->r_name);
        my_putstr(" is connected to: ");
        current_tunnel = rooms[i]->unions;
        while (current_tunnel != NULL) {
            my_putstr(current_tunnel->link->r_name);
            my_putstr(" ");
            current_tunnel = current_tunnel->next;
        }
        my_putchar('\n');
    }
}
