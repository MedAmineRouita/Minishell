/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-mohamed-amine.rouita
** File description:
** redirect
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

int creat_fd(char *i, char *j, char **env)
{
    int fd = open(j, O_WRONLY|O_CREAT, 0666);

    if (!fork()) {
        close(1);
        dup(fd);
        command_exe(i, env);
    } else {
        close(fd);
    }
    close(fd);
    return 0;
}

int basic_redirect(char *str, char **env)
{
    char *rd = ">";
    char *var1 = strtok(str, rd);
    char *var2 = strtok(NULL, "");
    char *x = space_remove(var1);
    char *y = space_remove(var2);

    if (var1 == NULL || var2 == NULL)
        return 84;
    creat_fd(x, y, env);
    return 0;
}