/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-mohamed-amine.rouita
** File description:
** my_comma
*/

#include "../include/my.h"
#include <stdlib.h>

int my_comma(char *str, char **env)
{
    char **tab = my_str_to_word_array(str, ';');

    for (int i = 0; tab[i] != NULL; i++) {
        space_remove(tab[i]);
        command_exe(tab[i], env);
    }
    return 0;
}