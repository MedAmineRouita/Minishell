/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my_strcat
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strcat (char *dest, char const *src)
{
    int var = 0;
    int index = 0;
    int len = my_strlen(dest) + my_strlen(src);
    char *str = malloc(sizeof(char*) * len);

    while (dest[index] != '\0') {
        str[index] = dest[index];
        index++;
    }
    while (src[var] != '\0') {
        str[index] = src[var];
        index++;
        var++;
    }
    return (str);
}