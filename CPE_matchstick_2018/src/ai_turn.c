/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** ai_turn.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int ai_line_remove(int ymax, char **map)
{
    int ret = 0;

    if (char_found_in_dbtab('|', map) > 1) {
        while (char_found('|', map[ret]) == 0) {
            ret = random() % ymax + 1;
            ret = ret < 0 ? 0 : ret;
        }
    } else
        for (; !char_found('|', map[ret]); ret++);
    return (ret);
}

int ai_match_remove(int line, char **map, int ymax, int remmax)
{
    int ret = 0;
    int match_max = char_found('|', map[line]) + 1;

    if (char_found_in_dbtab('|', map) > ymax * 2)
        ret = random() % (match_max - 1) + 1;
    else if (char_found('|', map[line]) > 1)
        ret = match_max - 2;
    else
        ret = 1;
    ret = ret <= 0 ? 1 : ret;
    ret = ret > remmax ? remmax : ret;
    return (ret);
}

char **ai_turn(int nb_lines, int remove_max, char **map)
{
    int action[2] = {0, 0};

    my_putstr("AI's turn...\n");
    action[LINE_REMOVE] = ai_line_remove(nb_lines, map);
    action[NB_REMOVE] = ai_match_remove(action[LINE_REMOVE], map, nb_lines,
                                        remove_max);
    print_turn_action("AI", action[LINE_REMOVE], action[NB_REMOVE]);
    map = update_game_board(action[LINE_REMOVE], action[NB_REMOVE], map,
                            nb_lines);
    print_map(map);
    return (map);
}