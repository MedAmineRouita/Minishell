/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** disp_prmpt
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

char *remove_n(char *str)
{
    char *last = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;

    while (str[i] != '\0') {
        if (str[i] != '\n') {
            last[j] = str[i];
            j++;
        }
        i++;
    }
    last[j] = '\0';
    return last;
}

int index_word(char *str)
{
    int index = 0;
    int var = 1;

    for (; str[index] != '\0'; index++) {
        if (str[index] == ' ')
            var++;
    }
    return var;
}

void command_exe(char *buff, char **env)
{
    if (my_strcmp(buff, "env\n") != 1)
        my_getenv(env);
    if (index_word(buff) == 2) {
        my_pf_long(buff);
    } else
        my_pf_short(buff);
}


int prmpt_display(char **env)
{
    size_t bufsz = 256;
    char *buff = malloc(sizeof(char) * bufsz);
    size_t charac;

    buff[0] = 0;
    if (buff == NULL)
        return 84;
    while (my_strcmp(buff, "exit\n") != 0) {
        write(1, "$> ", 3);
        charac = getline(&buff, &bufsz, stdin);
        buff[charac - 1] = 0;
        (my_detector(buff) > 0) ? separator(buff, env) : command_exe(buff, env);
    }
    return 0;
}

int mouli_test(char **env)
{
    size_t bufsz = 256;
    char *buf = malloc(sizeof(char) * bufsz);
    size_t charac;

    charac = getline(&buf, &bufsz, stdin);
    buf = remove_n(buf);
    if (buf == NULL)
        return 84;
    (my_detector(buf) > 0) ? separator(buf, env) : command_exe(buf, env);
    return 0;
}