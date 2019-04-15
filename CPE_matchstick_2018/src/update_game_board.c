/*
** EPITECH PROJECT, 2018
** CPE_matchstick_bootstrap_2018
** File description:
** print_updated_game_board.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

char **update_game_board(int line, int nb_matches, char **map, int ymax)
{
    int xmax = 1 + 2 * ymax;
    int pos;
    int passed = 0;

    if (!map)
        return (NULL);
    for (pos = 1; (map[line][pos] != ' ' || map[line][pos] != '*') &&
                                passed == 0; pos++) {
        if (map[line][pos] == '|')
            passed = 1;
    }
    for (; map[line][pos] != ' ' && map[line][pos] != '*'; pos++);
    for (int i = 1; i <= nb_matches && i <= xmax + 2; i++)
        map[line][pos - i] = map[line][pos - i] == '|' ?
                            ' ' : map[line][pos - i];
    return (map);
}