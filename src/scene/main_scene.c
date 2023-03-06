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

    if (game->event.type == sfEvtResized) {
        sfVector2u size = sfRenderWindow_getSize(game->window);
        sfView_setSize(game->view, (sfVector2f) {size.x, size.y});
        sfRenderWindow_setView(game->window, game->view);
        game->board->size = (sfVector2f) {size.x - game->board->pos.x,
        size.y - game->board->pos.y};
    }
}

void update_main_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        event_handler(game);
    draw_on_board(game);
    is_button_hover(game);
    button_action(game);
}

void main_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(69, 69, 69));
    sfRenderWindow_drawSprite(game->window, game->board->sprite, NULL);
    display_buttons(game);
    sfRenderWindow_display(game->window);
}
