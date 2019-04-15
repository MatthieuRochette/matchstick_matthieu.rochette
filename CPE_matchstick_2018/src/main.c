/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** main.c
*/

#include "my.h"
#include "matchstick.h"

int char_found(char c, char *str)
{
    int ret = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            ret++;
    }
    return (ret);
}

int char_found_in_dbtab(char c, char **tab)
{
    int ret = 0;

    if (!tab)
        return (-1);
    for (int i = 0; tab[i] != NULL; i++) {
        ret += char_found(c, tab[i]);
    }
    return (ret);
}

int gameloop(int nb_lines, int remove_max, char **map)
{
    print_map(map);
    while (char_found_in_dbtab('|', map) > 0) {
        map = player_turn(nb_lines, remove_max, map);
        if (!map)
            return (MY_SUCCESS);
        if (char_found_in_dbtab('|', map) == 0) {
            my_putstr("You lost, too bad...\n");
            return (2);
        }
        map = ai_turn(nb_lines, remove_max, map);
    }
    my_putstr("I lost... snif... but I'll get you next time!!\n");
    return (1);
}

int matchstick(int nb_lines, int remove_max)
{
    int error = MY_SUCCESS;
    char **map = gen_game_board(nb_lines);

    if (!map)
        return (MY_FAILURE);
    error = gameloop(nb_lines, remove_max, map);
    if (map)
        free_map(map);
    return (error);
}

int main(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        print_help();
        if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h'
                && my_strlen(av[1]) == 2)
            return (MY_SUCCESS);
        else
            return (MY_FAILURE);
    } else if (not_posnum(av[1], 1) || not_posnum(av[2], 1)) {
        write(2, BAD_ARG, my_strlen(BAD_ARG));
        return (84);
    } else {
        if (my_getnbr(av[1]) >= 100 || my_getnbr(av[1]) <= 0) {
            write(2, BAD_RANGE_ERR, my_strlen(BAD_RANGE_ERR));
            return (84);
        } else if (ac == 2)
            return (matchstick(my_getnbr(av[1]), 2147483647));
        else
            return (matchstick(my_getnbr(av[1]), my_getnbr(av[2])));
    }
}