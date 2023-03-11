/*
** EPITECH PROJECT, 2023
** paint
** File description:
** input_str
*/

#include "my.h"

char fetch_char(sfKeyCode key)
{
    for (int i = 0; i < 26; i++)
        if (key == sfKeyA + i)
            return 'a' + i;
    if (key == sfKeySpace)
        return ' ';
    if (key == sfKeyBack)
        return '\b';
    if (key == sfKeyNum8)
        return '_';
    if (key == sfKeyPeriod)
        return '.';
    if (key == 48)
        return '.';
    if (key == 52)
        return '/';
    return 0;
}

void manage_str(game_t *game, char c)
{
    if (c != 0) {
        if (c == '\b') {
            (game->input_box->str[0] != 0) ? (game->input_box->str[strlen(
            game->input_box->str) - 1] = 0) : (0);
        } else {
            (my_strlen(game->input_box->str) < 20) ? ({
                char *tmp = malloc(sizeof(char) * 2);
                tmp[0] = c;
                tmp[1] = 0;
                game->input_box->str = my_strcat(game->input_box->str, tmp);
                free(tmp);
            }) : (0);
        }
    }
}
