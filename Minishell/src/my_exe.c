/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my_exe
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

int my_pf_long(char *str)
{
    char **tb = my_str_to_word_array(str, ' ');
    char *bin = my_strcat("/usr/bin/", tb[0]);

    if (my_strcmp(tb[0], "cd") == 0)
        my_cd(tb);
    exe_long(bin, tb);
    return 0;
}

int my_pf_short(char *str)
{
    char **tb = my_str_to_word_array(str, ' ');
    char *bin = my_strcat("/usr/bin/", tb[0]);

    if (my_strcmp(tb[0], "cd") == 0)
        my_cd(tb);
    exe_short(tb[0], bin, tb);
}

int exe_long(char *pth, char **tb)
{
    int pidw;
    char *argone = tb[1];
    int var;
    pid_t pid;
    char *arg[] = {tb[0], argone, NULL};
    char *env[] = {NULL};
    int auth = authoriz_sh(tb[0]);

    pid = fork();
    if (pid == 0) {
        var = execve(pth, arg, env);
        if (var == -1 && auth == 0) {
            my_putstr(arg[0]);
            my_putstr(": Command not found.\n");
        }
    }
    if (pid < 0) {
        return 84;
    } else
        waitpid(pid, &pidw, 0);
}

int exe_short(char *com, char *pth, char **tb)
{
    int pidw;
    int var;
    pid_t pid;
    char **arg = tb;
    char *env[] = {NULL};
    int auth = authoriz_sh(tb[0]);

    pid = fork();
    if (pid == 0)
        var = execve(pth, arg, env);
        if (var == -1 && auth == 0) {
            my_putstr(arg[0]);
            my_putstr(": Command not found.\n");
        }
    if (pid < 0) {
        return 84;
    } else
        waitpid(pid, &pidw, 0);
}