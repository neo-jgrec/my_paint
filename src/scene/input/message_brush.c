/*
** EPITECH PROJECT, 2023
** paint
** File description:
** message_brush
*/

#include "my.h"

void handle_brush_overload(game_t *game)
{
    if (game->input_box->action == BRUSH_SIZE_ACTION) {
        if (my_strlen(game->input_box->str) > 2)
            game->board->size_brush = 100;
        if (my_atoi(game->input_box->str) > 100)
            game->board->size_brush = 100;
        else
            game->board->size_brush = my_atoi(game->input_box->str);
    }
}

void message_brush_input(game_t *game)
{
    if (game->input_box->action == BRUSH_SIZE_ACTION) {
        sfText_setString(game->input_box->text, "The max size is 100");
        sfText_setPosition(game->input_box->text, (sfVector2f) {
            sfRenderWindow_getSize(game->window).x / 2 - sfText_getGlobalBounds\
            (game->input_box->text).width / 2, 400});
        sfRenderWindow_drawText(game->window, game->input_box->text, NULL);
    }
}
