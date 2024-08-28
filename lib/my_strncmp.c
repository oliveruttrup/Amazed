/*
** EPITECH PROJECT, 2024
** B-PSU-200-BAR-2-1-minishell1-oliver.uttrup
** File description:
** my_strncmp
*/

#include "../include/my.h"

int my_strncmp(const char *s1, const char *s2, int n)
{
    int a = 0;

    while (s1[a] == s2[a] && s1[a] && s2[a] && a < n) {
        a++;
    }
    if ((s1[a] == '\0' && s2[a] == '\0') || a == n) {
        return 0;
    } else if ((unsigned char)s1[a] > (unsigned char)s2[a]) {
        return 1;
    } else {
        return -1;
    }
}
