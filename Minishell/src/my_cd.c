/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my_cd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <grp.h>
#include <pwd.h>

int my_cd(char **tb)
{
    char *arg1 = tb[1];

    chdir(arg1);
    return 0;
}