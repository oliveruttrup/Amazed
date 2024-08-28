/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** nodes.c
*/

#include "my.h"

room_t *create_room(char *name, room_status_t status, int x, int y)
{
    room_t *room = malloc(sizeof(room_t));

    room->r_name = my_strdup(name);
    room->robot = NULL;
    room->status = status;
    room->unions = NULL;
    room->x = x;
    room->y = y;
    return room;
}

void destroy_room(room_t *room)
{
    tunnel_t *tmp;

    free(room->r_name);
    if (room->robot != NULL)
        free(room->robot);
    while (room->unions != NULL)
        tmp = room->unions->next;
        free(room->unions);
        room->unions = tmp;
    free(room);
}

void connect_rooms(room_t *room1, room_t *room2)
{
    tunnel_t *union1 = malloc(sizeof(tunnel_t));
    tunnel_t *union2 = malloc(sizeof(tunnel_t));

    union1->link = room2;
    union1->next = room1->unions;
    room1->unions = union1;
    union2->link = room1;
    union2->next = room2->unions;
    room2->unions = union2;
}

static void set_status(info_t *info, int i, char **arr)
{
    if (my_strcmp(arr[i], "##start") == 0)
        info->status = START;
    else if (my_strcmp(arr[i], "##end") == 0)
        info->status = END;
}

room_t **create_room_arr(room_t **rooms, char **arr, info_t *info)
{
    char **arr_words;
    int j = 0;

    info->status = EMPTY;
    for (int i = 0; arr[i] != NULL; i++) {
        if (arr[i][0] == '#') {
            set_status(info, i, arr);
            continue;
        }
        arr_words = string_to_array(arr[i], ' ');
        if (arr_words[1] == NULL)
            continue;
        rooms[j] = create_room(arr_words[0], info->status,
        my_getnbr(arr_words[1]), my_getnbr(arr_words[2]));
        j++;
        info->status = EMPTY;
    }
    return rooms;
}

static int find_room_index(char *room_name, room_t **rooms)
{
    for (int j = 0; rooms[j] != NULL; j++) {
        if (my_strcmp(room_name, rooms[j]->r_name) == 0) {
            return j;
        }
    }
    return -1;
}

static int process_line(char *line, room_t **rooms)
{
    char **arr_words = string_to_array(line, '-');
    int room1_index = 0;
    int room2_index = 0;

    if (arr_words[1] == NULL)
        return 0;
    room1_index = find_room_index(arr_words[0], rooms);
    room2_index = find_room_index(arr_words[1], rooms);
    if (room1_index != -1 && room2_index != -1) {
        connect_rooms(rooms[room1_index], rooms[room2_index]);
        return 1;
    }
    return 0;
}

room_t **search_and_connect_rms(char **arr, room_t **rooms, int tunnel_count)
{
    int i = 0;
    int count = 0;

    for (i = 0; count < tunnel_count; i++) {
        if (arr[i][0] == '#')
            continue;
        count += process_line(arr[i], rooms);
    }
    return rooms;
}
