/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** utils.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

void print_turn_action(char *id, int line, int nbmatch)
{
    if (!id)
        return;
    my_putstr(id);
    my_putstr(" removed ");
    my_put_nbr(nbmatch);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putchar('\n');
}

void print_map(char **map)
{
    if (!map)
        return;
    for (int i = 0; map[i] != NULL; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
    if (char_found_in_dbtab('|', map))
        my_putchar('\n');
}

void free_map(char **map)
{
    if (map) {
        for (int i = 0; map[i] != NULL; i++)
            free(map[i]);
        free(map);
    }
}