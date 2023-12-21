/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my_getenv
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char **my_getenv(char **env)
{
    int i = 0;

    while (env[i]) {
        my_putstr(env[i++]);
        my_putchar('\n');
    }
}

int my_envpars(char **tb)
{
    char *var = tb[0];

    if (my_strcmp(var, "unsetenv") == 0) {
        my_unsetenv(tb);
    }
    if (my_strcmp(var, "setenv") == 0) {
        my_envset(tb);
    }
    return 0;
}

char *my_envset(char **tb)
{
    char *def = tb[1];
    char *val = tb[2];
    char *var = my_strcat(def, "=");
    int len = my_strlen(def) + my_strlen(val) + 1;
    char *add = malloc(sizeof(char*) * len);

    add = my_strcat(var, val);
    return add;
}

char *my_unsetenv(char **tb)
{
    char *def = tb[1];
    
    return def;
}