/*
** EPITECH PROJECT, 2018
** strcpy
** File description:
** copy a string
*/

#include <unistd.h>

char *my_strcpy(char *dest, char const *src)
{
    int i;

    if (!src || !dest)
        return (NULL);
    for (i = 0; src[i] != '\0'; i ++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}