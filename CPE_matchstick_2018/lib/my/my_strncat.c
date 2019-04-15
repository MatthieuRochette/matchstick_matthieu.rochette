/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenate two strings
*/

#include <unistd.h>

char *my_strncat(char *dest, char const *src, int nb)
{
    int i;
    int j;

    if (!src || !dest)
        return (NULL);
    for (i = 0; dest[i] != '\0'; i ++);
    for (j = 0; j < nb; j ++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return (dest);
}