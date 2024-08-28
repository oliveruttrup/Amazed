/*
** EPITECH PROJECT, 2024
** B-PSU-100-BAR-1-1-myls-oliver.uttrup
** File description:
** string_to_arr
*/

#include "../include/my.h"

int rows_str(char *str, char token)
{
    int rows = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == token) {
            rows++;
        }
    }
    rows++;
    return rows;
}

char **init_array(char *str, char token)
{
    int rows = rows_str(str, token);
    char **array = malloc((rows + 1) * sizeof(char *));

    if (array == NULL)
        return NULL;
    array[0] = malloc((50) * sizeof(char));
    return array;
}

char **string_to_array(char *str, char token)
{
    char **array = init_array(str, token);
    int i = 0;
    int j = 0;

    for (int k = 0; str[k] != '\0'; k++) {
        if (str[k] == token) {
            k++;
            array[i][j] = '\0';
            j = 0;
            i++;
            array[i] = malloc((50) * sizeof(char));
        }
        array[i][j] = str[k];
        j++;
    }
    array[i][j] = '\0';
    array[i + 1] = NULL;
    return array;
}
