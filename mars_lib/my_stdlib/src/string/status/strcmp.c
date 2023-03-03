/*
** EPITECH PROJECT, 2023
** mars_lib
** File description:
** my_strcmp
*/

#include "my_stdlib.h"

int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}

int my_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (s1[i] - s2[i]);
}
