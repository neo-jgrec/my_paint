/*
** EPITECH PROJECT, 2023
** paint
** File description:
** display
*/

#include "my.h"

static void event_handler(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEscape) {
        game->overlay = NONE_OVERLAY;
        game->panel = NONE;
        game->scene = MAIN;
    }
    if (game->event.type == sfEvtResized) {
        sfVector2u size = {game->event.size.width, game->event.size.height};
        sfView *view = sfView_createFromRect((sfFloatRect){0, 0,
        (float)size.x, (float)size.y});
        sfRenderWindow_setView(game->window, view);
        sfView_destroy(view);
        sfText_setPosition(game->about->text, (sfVector2f) {
            sfRenderWindow_getSize(\
            game->window).x - sfText_getGlobalBounds(game->about->text).width - 10,
            (0 - sfText_getGlobalBounds(game->about->text).height / 2) + 10
        });
    }
}

void update_main_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        event_handler(game);
    draw_on_board(game);
    button_action(game);
}

void main_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(69, 69, 69));
    sfRenderWindow_drawSprite(game->window, game->board->sprite, NULL);
    display_all_buttons(game);
    if (game->overlay == HELP)
        game->scene = HELP_SCENE;
    if (game->about->is_about == true)
        sfRenderWindow_drawText(game->window, game->about->text, NULL);
    sfRenderWindow_display(game->window);
}
