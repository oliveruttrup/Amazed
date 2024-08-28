/*
** EPITECH PROJECT, 2023
** MY.H
** File description:
** task02
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <time.h>
    #include <pwd.h>
    #include <grp.h>
    #include <sys/wait.h>
    #include <stdbool.h>

typedef enum {
    START,
    END,
    EMPTY,
    OCCUPIED
} room_status_t;

typedef struct room_s room_t;
typedef struct tunnel_s tunnel_t;

typedef struct robot_s {
    int id;
    struct robot_s *next;
} robot_t;

struct room_s {
    char *r_name;
    room_status_t status;
    robot_t *robot;
    tunnel_t *unions;
    int x;
    int y;
};

struct tunnel_s {
    room_t *link;
    tunnel_t *next;
};

typedef struct info_s {
    int tot_rob;
    int tot_rooms;
    int tot_tunnels;
    room_t **rooms;
    int c_start;
    int c_end;
    int coord_count;
    room_status_t status;
} info_t;

typedef struct node_s {
    struct node_s *parent;
    room_t *room;
    struct node_s *next;
}node_t;

void my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_count(int nb, int *count);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strdup(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char *src);
int my_strncmp(const char *s1, const char *s2, int n);
int my_putstr_error(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
bool is_alphanumeric(char *str);
bool char_is_alphanumeric(char character);
int my_getnbr(char const *str);

int main(int argc, char **argv, char **__environ);
void print_arr(char **arr);
int array_len(char **arr);

// Utilities
int array_len(char **arr);
void print_room_array(room_t **rooms);
void print_room_and_connected_rooms(room_t **rooms);

// Prints
void print_total_robots(int tot_rob);
void print_tunnels(char **arr);
void print_rooms(char **arr);
void print_tunnels_error(char **arr, room_t **rooms);

// File parsing
char **string_to_array(char *str, char token);
char *get_file_content(void);
int total_robots(char **arr);

// Rooms
void check_room_print(char **arr, int i);
void print_rooms(char **arr);
int check_start_end(char **arr, info_t *info);
int check_numeric_coordinates(char **arr, info_t *info);
int check_room_total_elements(char **arr);
int count_rooms(char **arr);
int total_rooms(char **arr, info_t *info);

room_t *create_room(char *name, room_status_t status, int x, int y);
void destroy_room(room_t *room);
room_t **create_room_arr(room_t **rooms, char **arr, info_t *info);

// Tunnels
int count_tunnels(char **arr);
int check_room_existence(char **arr, room_t **rooms);
int check_room_existence(char **arr_words, room_t **rooms);
int check_tunnel_validity(char **arr_words, room_t **rooms);
int process_file(char **arr, room_t **rooms, info_t *info);
room_t **search_and_connect_rms(char **arr, room_t **rooms, int tunnel_count);

node_t *find_path(node_t *parent, room_t *room, int length, int *minlength);
void print_path(node_t *start);

robot_t *create_robots(int robots);
void robot_movement(node_t *path, robot_t **robots);
bool is_path_empty(node_t *path);

#endif
