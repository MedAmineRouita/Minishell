/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-mohamed-amine.rouita
** File description:
** separator
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <fcntl.h>

int detect_str_in_str(char *str, char *exp)
{
    int var1 = 0;
    int var2 = 0;
    int len_str = my_strlen(str);
    int len_exp = my_strlen(exp);

    for (var1 = 0; var1 < len_str; var1++) {
        if (str[var1] == exp[var2]) {
            var2++;
            if (var2 == len_exp)
                return var1 - var2 + 1;
        } else
            var2 = 0;
    }
    return -1;
}

int for_len(char *str)
{
    int a = 1;
    int i = 0;

    for (;str[i] != '\0';i++)
        if (str[i] == ' ')
            a++;
    return a;
}

int my_detector(char *str)
{
    int var = 0;

    for (int index = 0; str[index] != '\0'; index++)
        if (str[index] == ';' || str[index] == '|' || str[index] == '<' || str[index] == '>')
            var++;
    return var;
}



int detect_in_str(char *var, char ch)
{
    while (*var) {
        if (*var == ch)
            return 0;
        var++;
    }

    return 1;
}

int separator(char *str, char **env)
{
    if (detect_in_str(str, ';') == 0)
        my_comma(str, env);
    if (detect_in_str(str, '|') == 0)
        detect_pipe(str, env);
    if (detect_str_in_str(str, ">>") > 0) {
        basic_redirect2(str, env);
        return 0;
    }
    if (detect_in_str(str, '>') == 0)
        basic_redirect(str, env);
    return (0);
}