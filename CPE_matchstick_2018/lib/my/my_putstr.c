/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** test
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int i = 0;

    if (!str)
        return (84);
    write(1, str, my_strlen(str));
    return (0);
}