/*
** EPITECH PROJECT, 2018
** str upcase
** File description:
** transform everything in upcase
*/

#include <unistd.h>

int my_str_isprintable(char const *str)
{
    int i;

    if (!str)
        return (NULL);
    for (i = 0; str[i] != '\0'; i ++) {
        if (str[i] < 32)
            return (0);
    }
    return (1);
}