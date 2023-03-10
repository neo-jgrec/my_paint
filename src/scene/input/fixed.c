/*
** EPITECH PROJECT, 2023
** paint
** File description:
** fixec
*/

#include "my.h"

void fixed_compo(game_t *game)
{
    sfText *text = sfText_create();
    sfText_setString(text, game->input_box->title);
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, (sfVector2f) {
        sfRenderWindow_getSize(game->window).x / 2 - sfText_getGlobalBounds\
        (text).width / 2, 10 });
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);

    sfRectangleShape *rect = sfRectangleShape_create();
    sfRectangleShape_setSize(rect, (sfVector2f) { 400, 50 });
    sfRectangleShape_setPosition(rect, (sfVector2f) {
        sfRenderWindow_getSize(game->window).x / 2 - sfRectangleShape_getSize\
        (rect).x / 2, 200 });
    sfRectangleShape_setFillColor(rect, sfColor_fromRGB(255, 255, 255));
    sfRenderWindow_drawRectangleShape(game->window, rect, NULL);
}
