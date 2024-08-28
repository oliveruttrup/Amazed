/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** print_file
*/

#include "../include/my.h"

static info_t *init_struct(info_t *info)
{
    info->tot_rob = 0;
    info->tot_rooms = 0;
    info->tot_tunnels = 0;
    info->c_start = 0;
    info->c_end = 0;
    info->coord_count = 0;
    return info;
}

static info_t *initialize_info(void)
{
    info_t *info = malloc(sizeof(info_t));

    init_struct(info);
    return info;
}

static char **get_file_lines(void)
{
    char *buffer = get_file_content();
    char **arr = string_to_array(buffer, '\n');

    return arr;
}

static int handle_robots(info_t *info, char **arr)
{
    info->tot_rob = total_robots(arr);
    if (info->tot_rob == -1 || info->tot_rob < 1)
        return 84;
    print_total_robots(info->tot_rob);
    return 0;
}

static int handle_rooms(info_t *info, char **arr)
{
    info->tot_rooms = total_rooms(arr, info);
    if (info->tot_rooms == -1 || info->tot_rooms < 1)
        return 84;
    print_rooms(arr);
    info->rooms = malloc(sizeof(room_t *) * info->tot_rooms);
    info->rooms = create_room_arr(info->rooms, arr, info);
    return 0;
}

int handle_tunnel_status(info_t *info, char **arr)
{
    int tunnel_status = process_file(arr, info->rooms, info);

    if (tunnel_status == 0)
        return 84;
    if (tunnel_status == -1)
        print_tunnels_error(arr, info->rooms);
    else
        print_tunnels(arr);
    return 0;
}

void connect_rooms_main(info_t *info, char **arr)
{
    info->rooms = search_and_connect_rms(arr, info->rooms, info->tot_tunnels);
}

static int path_has_end(node_t *path)
{
    node_t *tmp = path;

    while (tmp != NULL){
        if (tmp->room->status == END)
            return 0;
        tmp = tmp->next;
    }
    return 84;
}

int processing(info_t *info)
{
    room_t *start;
    int len = __INT_MAX__;
    node_t *path;
    robot_t *robots;

    for (int i = 0; info->rooms[i] != NULL; i++)
        if (info->rooms[i]->status == START)
            start = info->rooms[i];
    path = find_path(NULL, start, 0, &len);
    if (path_has_end(path) == 84)
        return 84;
    robots = create_robots(info->tot_rob);
    my_putstr("#moves\n");
    while (1) {
        if (robots == NULL && is_path_empty(path))
            break;
        robot_movement(path, &robots);
        my_putstr("\n");
    }
}

int main(int argc, char **argv, char **env)
{
    info_t *info = initialize_info();
    char **arr = get_file_lines();
    int status = 0;

    status = handle_robots(info, arr);
    if (status == 84)
        return 84;
    status = handle_rooms(info, arr);
    if (status == 84)
        return 84;
    status = handle_tunnel_status(info, arr);
    if (status == 84)
        return 84;
    connect_rooms_main(info, arr);
    status = processing(info);
    if (status == 84)
        return 84;
    return 0;
}


// int main(int argc, char **argv, char **env)
// {
//     info_t *info = malloc(sizeof(info_t));
//     char *buffer = get_file_content();
//     char **arr = string_to_array(buffer, '\n');
//     init_struct(info);
//     // Robots
//     info->tot_rob = total_robots(arr);
//     if (info->tot_rob == -1 || info->tot_rob < 1)
//         return 84;
//     printf("NUMERO DE ROBOTS: %d\n", info->tot_rob);
//     // Rooms
//     info->tot_rooms = total_rooms(arr, info);
//     if (info->tot_rooms == -1 || info->tot_rooms < 1)
//         return 84;
//     printf("NUMERO DE ROOMS: %d\n", info->tot_rooms);
//     info->rooms = malloc(sizeof(room_t *) * info->tot_rooms);
//     info->rooms = create_room_arr(info->rooms, arr);
//     print_room_array(info->rooms);
//     // Tunnels
//     int tottun = count_tunnels(arr);
//     printf("NUMERO DE TUNELES NO HANDLEADO: %d\n", tottun);
//     info->tot_tunnels = process_file(arr, info->rooms);
//     printf("NEW TOTAL: %d\n", info->tot_tunnels);
//     info->rooms = search_and_connect_rms
//(arr, info->rooms, info->tot_tunnels);
//     print_room_and_connected_rooms(info->rooms);

//     room_t *start = info->rooms[3];
//     node_t *path = find_path(NULL, start);
//     robot_t *robots = create_robots(info->tot_rob);
//     print_path(path);

//     while (1) {
//         if (robots == NULL && is_path_empty(path))
//             break;
//         robot_movement(path, &robots);
//         printf("\n");
//     }
//     return 0;
// }
    // free_array(path_arr);
    // free(full_path);
