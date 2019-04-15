/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** player_turn.c
*/

#include "../include/my.h"
#include "../include/matchstick.h"

int count_match_line(char *line)
{
    int nb = 0;

    for (int i = 0; line[i] != '\0'; i++)
        nb += line[i] == '|' ? 1 : 0;
    return (nb);
}

int get_line_remove(int line_max)
{
    size_t buffsize = 0;
    char *buff = NULL;
    int nb = 0;
    int a = 1234;

    do {
        my_putstr("Line: ");
        if ((a = getline(&buff, &buffsize, stdin)) < 0) {
            free(buff);
            return (-1);
        }
        if (not_posnum(buff, 0) == MY_TRUE) {
            write(1, NON_ENTRY, my_strlen(NON_ENTRY));
            return (0);
        }
        nb = my_getnbr(buff);
        if (nb > line_max || nb <= 0)
            my_putstr("Error: this line is out of range\n");
    } while (nb <= 0 || nb > line_max);
    free(buff);
    return (nb);
}

int get_nb_match_remove(int remove_max, int *asking_ok, char* line)
{
    size_t buffsize = 0;
    char *buff = NULL;
    int nb;
    int nb_match_on_line = count_match_line(line);

    my_putstr("Matches: ");
    if (getline(&buff, &buffsize, stdin) < 0) {
        free(buff);
        return (-1);
    }
    if (not_posnum(buff, 0))
        return (write(1, NON_ENTRY, my_strlen(NON_ENTRY)) ? 0 : 0);
    nb = my_getnbr(buff);
    if (nb > remove_max || nb > nb_match_on_line)
        print_err_remmax(remove_max, nb_match_on_line);
    else if (nb <= 0)
        my_putstr("Error: you have to remove at least one match\n");
    else
        *asking_ok = 1;
    free(buff);
    return (nb);
}

char **player_turn(int nb_lines, int remove_max, char **map)
{
    int action[3] = {0, 0, 0};

    my_putstr("Your turn:\n");
    while (action[STOP_ASK] == 0) {
        action[LINE_REMOVE] = get_line_remove(nb_lines);
        if (action[LINE_REMOVE] == -1)
            return (NULL);
        if (action[LINE_REMOVE] > 0)
            action[NB_REMOVE] = get_nb_match_remove(remove_max,
                                &action[STOP_ASK], map[action[LINE_REMOVE]]);
        if (action[NB_REMOVE] == -1)
            return (NULL);
    }
    print_turn_action("Player", action[LINE_REMOVE], action[NB_REMOVE]);
    update_game_board(action[LINE_REMOVE], action[NB_REMOVE], map, nb_lines);
    print_map(map);
    return (map);
}