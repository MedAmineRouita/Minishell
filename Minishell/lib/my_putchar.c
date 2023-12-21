/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my_putchar
*/

#include <unistd.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
