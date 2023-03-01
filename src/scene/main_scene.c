/*
** EPITECH PROJECT, 2023
** paint
** File description:
** display
*/

#include "my.h"

static void event_handler(game_t *game)
{
    if (game->event.type == sfEvtClosed ||
    (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEscape))
        sfRenderWindow_close(game->window);
}

void update_main_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        event_handler(game);
    draw_on_board(game);
}

void main_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(47, 79, 79));
    sfRenderWindow_drawSprite(game->window, game->board->sprite, NULL);
    sfRenderWindow_display(game->window);
}
