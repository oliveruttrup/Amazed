/*
** EPITECH PROJECT, 2024
** B-PSU-100-BAR-1-1-myls-oliver.uttrup
** File description:
** my_strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int destlen = my_strlen(dest);
    int srclen = my_strlen(src);
    char *cat = malloc(sizeof(char) * (destlen + srclen + 1));

    cat = my_strcpy(cat, dest);
    while (src[i] != '\0') {
        cat[destlen] = src[i];
        destlen++;
        i++;
    }
    cat[destlen] = '\0';
    return cat;
}
