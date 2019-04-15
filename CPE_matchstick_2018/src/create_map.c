/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** create_map.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

char *gen_n_times_c(int n, char c, char *ret, int *offset)
{
    int i;

    if (!ret || !offset)
        return (NULL);
    for (i = 0; i < n; i++)
        ret[i + *offset] = c;
    *offset += i;
    return (ret);
}

char *gen_star_line(int xmax)
{
    char *ret = malloc(sizeof(char) * (xmax + 2 + 1));
    int i;

    if (!ret)
        return (NULL);
    for (i = 0; i < xmax + 2; i++)
        ret[i] = '*';
    ret[i] = '\0';
    return (ret);
}

char *my_gen_normal_line(int nb_matchstick, int xmax)
{
    int nb_spaces = xmax - nb_matchstick;
    char *ret = malloc(sizeof(char) * (xmax + 2 + 1));
    int offset = 1;

    if (!ret)
        return (NULL);
    ret[0] = '*';
    ret = gen_n_times_c(nb_spaces / 2, ' ', ret, &offset);
    ret = gen_n_times_c(nb_matchstick, '|', ret, &offset);
    ret = gen_n_times_c(nb_spaces / 2, ' ', ret, &offset);
    ret[offset] = '*';
    ret[offset + 1] = '\0';
    return (ret);
}

char **gen_game_board(int ymax)
{
    int xmax = 1 + 2 * ymax - 2;
    char **ret = malloc(sizeof(char *) * (ymax + 2 + 1));
    int i;

    if (!ret)
        return (NULL);
    ret[0] = gen_star_line(xmax);
    for (i = 0; 1 + (2 * i) <= xmax; i++) {
        ret[i + 1] = my_gen_normal_line(1 + (2 * i), xmax);
        if (!ret[i])
            return (NULL);
    }
    ret[i + 1] = gen_star_line(xmax);
    ret[i + 2] = NULL;
    return (ret);
}