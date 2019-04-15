/*
** EPITECH PROJECT, 2018
** revstr
** File description:
** copy a string
*/

#include <unistd.h>
int my_strlen(char *str);

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char a;

    if (!str)
        return (NULL);
    while (i < j) {
        a = str[j];
        str[j] = str[i];
        str[i] = a;
        j--;
        i++;
    }
    str[my_strlen(str)] = '\0';
    return (str);
}