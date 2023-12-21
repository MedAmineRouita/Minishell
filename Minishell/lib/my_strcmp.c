/*
** EPITECH PROJECT, 2022
** B-PSU-101-MPL-1-1-minishell1-mohamed-amine.rouita
** File description:
** my_strcmp
*/

#include <stdio.h>

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1) {
        if (*str1 != *str2) {
            return 1;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

int my_strncmp(int index, const char *str1, const char *str2)
{
    while (index != 0 && *str1 == *str2) {
        if (*str1 == '\0')
            return 0;
        ++str1;
        ++str2;
        --index;
    }
    if (index != 0)
        return *str1 - *str2;
    return 0;
}