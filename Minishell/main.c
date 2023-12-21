/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** main
*/

#include "include/my.h"
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **env)
{
    argc += 0;
    argv += 0;

    if (isatty(STDIN_FILENO) == 0)
        mouli_test(env);
    if (isatty(STDIN_FILENO) == 1)
        prmpt_display(env);
    return 0;
}