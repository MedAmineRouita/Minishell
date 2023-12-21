/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my_strlen
*/

#include <unistd.h>

int my_strlen(char const *str)
{
    int k;

    k = 0;
    while (str[k] != '\0') {
        k++;
    }
    return (k);
}