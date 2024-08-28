/*
** EPITECH PROJECT, 2024
** B-CPE-200-BAR-2-1-amazed-oliver.uttrup
** File description:
** get_robots
*/

#include "../../include/my.h"

char *get_file_content(void)
{
    char *file = malloc(sizeof(char) * 10000);
    int size = read(0, file, 10000);
    char *buffer = malloc(sizeof(char) * size + 1);

    if (size == -1)
        return NULL;
    buffer[size] = '\0';
    my_strcpy(buffer, file);
    return buffer;
}
