/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-mohamed-amine.rouita
** File description:
** pipes
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

int exe_pipe(char *a, char *b, char **env)
{
    int pfd[2];
    int pid;

    if (pipe(pfd) == -1)
        return 84;
    if ((pid = fork()) < 0)
        return 84;
    if (pid == 0) {
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        command_exe(a, env);
        return 0;
    } else {
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        command_exe(b, env);
        return 0;
    }
    return 0;
}

int detect_pipe(char *str, char **env)
{
    char *separator = "|";
    char *b = strtok(str, separator);
    char *c = strtok(NULL, "");

    if (b == NULL || c == NULL) {
        return 84;
    }
    b = space_remove(b);
    c = space_remove(c);
    exe_pipe(c, b, env);
    return 0;
}