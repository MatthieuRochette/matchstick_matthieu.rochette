/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** error_management.c
*/

#include "my.h"
#include "matchstick.h"

int not_posnum(char *arg, int test_pos)
{
    if (!arg)
        return (MY_FALSE);
    if (arg[0] == '\n')
        return (MY_TRUE);
    for (int i = 0; arg[i] != '\0'; i++) {
        if (!(arg[i] >= '0' && arg[i] <= '9') && arg[i] != '\n' &&
                !(i == 0 && arg[0] == '-'))
            return (MY_TRUE);
    }
    if (test_pos != 0) {
        if (my_getnbr(arg) <= 0)
                return (MY_TRUE);
    }
    return (MY_FALSE);
}

void print_err_remmax(int remove_max, int nbmatch_line)
{
    if (remove_max <= nbmatch_line) {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(remove_max);
        my_putstr(" matches per turn\n");
    } else
        my_putstr("Error: not enough matches on this line\n");
}

void print_help(void)
{
    write(2, NB_ARG_NEEDED, my_strlen(NB_ARG_NEEDED));
}