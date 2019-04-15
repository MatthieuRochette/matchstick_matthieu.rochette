/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2018
** File description:
** matchstick.h
*/

#ifndef MATCH_H
#define MATCH_H

#include <stdio.h>
#include <stdlib.h>

#define BAD_ARG "Arguments must be positive numbers.\n"
#define NB_ARG_NEEDED "The program takes two positive numbers as argument.\n"
#define BAD_RANGE_ERR "Number of lines must be between 0 and 100.\n"
#define NON_ENTRY "Error: invalid input (positive number expected)\n"

#define LINE_REMOVE 0
#define NB_REMOVE 1
#define STOP_ASK 2

int char_found_in_dbtab(char c, char **tab);
int char_found(char c, char *str);
int not_posnum(char *arg, int test_pos);
void print_help(void);
int matchstick(int nb_lines, int remove_max);
char **gen_game_board(int ymax);
char *my_gen_normal_line(int nb_matchstick, int xmax);
char *gen_star_line(int xmax);
char **update_game_board(int line, int nb_matches, char **map, int ymax);
char **player_turn(int nb_lines, int remove_max, char **map);
char **ai_turn(int nb_lines, int remove_max, char **map);
void print_err_remmax(int remove_max, int nbmatch_line);
void print_turn_action(char *id, int line, int nbmatch);
void print_map(char **map);
void free_map(char **map);
int is_empty(char *arg);

#endif