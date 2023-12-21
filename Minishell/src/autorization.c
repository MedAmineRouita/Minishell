/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** autorization
*/

#include <stdio.h>
#include "../include/my.h"

int authoriz_sh(char *str)
{
    int var = 0;
    char *tb[] = {"exit", "cd", "setenv", "unsetenv"};
    int i = 0;

    while (tb[i]) {
        if (my_strcmp(str, tb[i]) != 0) {
            var += 0;
        } else {
            var++;
        }
        i++;
    }
    if (var == 0)
        return 0;
    return 1;
}