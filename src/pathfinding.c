/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** nodes.c
*/

#include "my.h"

node_t *init_node(node_t *parent, room_t *room)
{
    node_t *node;

    if (room == NULL)
        return NULL;
    node = malloc(sizeof(node_t));
    node->parent = parent;
    node->room = room;
    node->next = NULL;
    return node;
}

static void change_status(room_status_t *status, room_status_t tothis)
{
    if (*status != START)
        *status = tothis;
}

static void change_minlen(room_status_t status, int length, int *minlength)
{
    if (status == END)
        *minlength = length;
}

static node_t *check_if_got_shorter(int got_shorter, node_t *current)
{
    if (got_shorter == 1)
        return current;
    else
        return NULL;
}

static void make_shorter(node_t *shorter, node_t *current, int *got_shorter)
{
    if (shorter != NULL){
        current->next = shorter;
        *got_shorter = 1;
    }
}

node_t *find_path(node_t *parent, room_t *room, int length, int *minlength)
{
    node_t *current;
    node_t *shorter;
    int got_shorter = 0;

    if (room == NULL || room->status == OCCUPIED || length >= *minlength)
        return NULL;
    current = init_node(parent, room);
    change_minlen(room->status, length, minlength);
    if (room->status == END)
        return current;
    change_status(&(room->status), OCCUPIED);
    for (tunnel_t *tmp = room->unions; tmp != NULL; tmp = tmp->next) {
        if (tmp->link->status == START)
            continue;
        shorter = find_path(current, tmp->link, length + 1, minlength);
        make_shorter(shorter, current, &got_shorter);
    }
    change_status(&(room->status), EMPTY);
    return check_if_got_shorter(got_shorter, current);
}
