/*
** EPITECH PROJECT, 2023
** paint
** File description:
** input_str
*/

#include "my.h"

static char fetch_number(sfKeyCode key)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift)) {
        (key == sfKeyNum0) ? ({return '1';}) : (0);
        (key == sfKeyNum1) ? ({return '2';}) : (0);
        (key == sfKeyNum2) ? ({return '3';}) : (0);
        (key == sfKeyNum3) ? ({return '4';}) : (0);
        (key == sfKeyNum4) ? ({return '5';}) : (0);
        (key == sfKeyNum5) ? ({return '6';}) : (0);
        (key == sfKeyNum6) ? ({return '7';}) : (0);
        (key == sfKeyNum7) ? ({return '8';}) : (0);
        (key == sfKeyNum8) ? ({return '9';}) : (0);
        (key == sfKeyNum9) ? ({return '0';}) : (0);
    } else {
        (key == sfKeyNum5) ? ({return '(';}) : (0);
        (key == sfKeyNum6) ? ({return '-';}) : (0);
        (key == sfKeyNum8) ? ({return '_';}) : (0);
    }
    return -1;
}

char fetch_char(sfKeyCode key)
{
    for (int i = 0; i < 26; i++)
        if (key == sfKeyA + i)
            return 'a' + i;
    if (key == sfKeySpace)
        return ' ';
    if (key == sfKeyBack)
        return '\b';
    if (key == sfKeyPeriod)
        return '.';
    if (key == 48)
        return '.';
    if (key == 52)
        return '/';
    if (fetch_number(key) != -1)
        return fetch_number(key);
    for (int i = 0; i < 10; i++)
        if (key == sfKeyNumpad0 + i)
            return '0' + i;
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
