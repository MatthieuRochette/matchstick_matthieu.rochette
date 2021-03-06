/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** concatenate two strings
*/

#include <unistd.h>

char *my_strcat(char *dest, char const *src)
{
    int i;
    int j;

    if (!dest || !src)
        return (NULL);
    for (i = 0; dest[i] != '\0'; i ++);
    for (j = 0; src[j] != '\0'; j ++) {
        dest[i + j] = src[j];
    }
    dest[i + j] = '\0';
    return (dest);
}