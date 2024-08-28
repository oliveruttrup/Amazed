/*
** EPITECH PROJECT, 2023
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** robots.c
*/

#include "my.h"

robot_t *create_robots(int robots)
{
    robot_t *main = NULL;
    robot_t *tmp;

    for (robots; robots > 0; robots--){
        tmp = malloc(sizeof(robot_t));
        tmp->id = robots;
        tmp->next = main;
        main = tmp;
    }
    return main;
}

static void print_movement(int id, char *r_name)
{
    my_putstr("P");
    my_put_nbr(id);
    my_putstr("-");
    my_putstr(r_name);
    my_putstr(" ");
}

void move_robot(node_t *prev, robot_t **robots)
{
    robot_t *current_robot = prev->room->robot;

    prev->room->robot = NULL;
    if (prev->room->status == START){
        current_robot = (*robots);
        if (current_robot == NULL)
            return;
        (*robots) = (*robots)->next;
    }
    if (current_robot == NULL){
        return;
    }
    print_movement(current_robot->id, prev->next->room->r_name);
    if (prev->next->room->status == END)
        free(current_robot);
    else
        prev->next->room->robot = current_robot;
}

void robot_movement(node_t *path, robot_t **robots)
{
    if (path->room->status == END)
        return;
    robot_movement(path->next, robots);
    move_robot(path, robots);
}

bool is_path_empty(node_t *path)
{
    node_t *tmp = path;

    while (tmp != NULL){
        if (tmp->room->robot != NULL)
            return false;
        tmp = tmp->next;
    }
    return true;
}
