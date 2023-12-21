/*
** EPITECH PROJECT, 2021
** B-PSU-100-MPL-1-1-myprintf-mohamed-amine.rouita
** File description:
** my_putstr
*/

#include <unistd.h>
#include "../include/my.h"

int my_putstr(char const *str)
{
    int h = 0;

    while (str[h] != '\0') {
        my_putchar(str[h]);
        h++;
        }
    return 0;
}
