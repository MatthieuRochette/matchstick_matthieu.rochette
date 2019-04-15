/*
** EPITECH PROJECT, 2018
** strcpy
** File description:
** copy a string
*/

#include <unistd.h>

char *my_strstr(char *str, char const *to_find)
{
    int x;

    if (!str || !to_find)
        return (NULL);
    for (x = 0; str[x] != '\0' && to_find[x] != '\0'; x ++) {
        if (str[x] == to_find[x])
            return (0);
    }
    return (0);
}