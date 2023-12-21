/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** strtowordarray
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

char **long_arr(char *str, char **tb, char spc, int count)
{
    int var1 = 0;
    int var2 = 0;

    for (int a = 0; a < count - 1; a++)
        tb[a] = malloc(sizeof(char) * my_strlen(str));

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] != spc) {
            tb[var2][var1] = str[index];
            var1++;
        }
        if (str[index] == spc && str[index + 1] != spc \
            && str[index + 1] != '\t' && str[index + 1] != 0) {
            tb[var2][var1] = 0;
            var1 = 0;
            var2++;
        }
        if (str[index + 1] == 0)
            tb[var2][var1] = 0;
    }
    return tb;
}

char *space_remove(char *str)
{
    char *res = malloc(sizeof(char) * my_strlen(str) + 1);
    int index = 0;

    res[my_strlen(str)] = 0;
    for (; *str == ' '; str++);
    for (; str[index] != 0; index++) {
        if (str[index] == ' ')
            break;
        res[index] = str[index];
    }
    res[index] = 0;
    return res;
}


char **short_arr(char *str)
{
    char **tb = malloc(sizeof(char *) * 2);

    tb[1] = NULL;
    tb[0] = str;
    tb[0] = space_remove(tb[0]);
    return tb;
}

char **my_str_to_word_array(char *str, char spc)
{
    int count = 2;
    char **tb;

    for (; *str == ' '; str++);
    for (int index = 0; str[index] != 0; index++)
        if (str[index] == spc && str[index + 1] != spc \
            && str[index + 1] != '\t' && str[index + 1] != 0)
            count++;
    tb = malloc(sizeof(char *) * count);
    tb[count - 1] = NULL;
    if (count == 2) {
        return short_arr(str);
    } else
        return long_arr(str, tb, spc, count);
}