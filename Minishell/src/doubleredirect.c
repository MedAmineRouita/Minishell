/*
** EPITECH PROJECT, 2022
** B-PSU-210-MPL-2-1-minishell2-mohamed-amine.rouita
** File description:
** doubleredirect
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

char *first_remove(char *str)
{
    char *first = malloc(sizeof(char) * my_strlen(str));
    int j = 0;
    for (int i = 1; str[i] != '\0'; i++) {
        first[j] = str[i];
        j++;
    }
    return first;
}

int creat_fd2(char *i, char *j, char **env)
{
    int fd = open(j, O_WRONLY|O_CREAT|O_APPEND, 0666);

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

int basic_redirect2(char *str, char **env)
{
    char *rd = ">>";
    char *var1 = strtok(str, rd);
    char *var2 = strtok(NULL, "");
    var2 = first_remove(var2);
    char *x = space_remove(var1);
    char *y = space_remove(var2);

    if (var1 == NULL || var2 == NULL)
        return 84;
    creat_fd2(x, y, env);
    return 0;
}