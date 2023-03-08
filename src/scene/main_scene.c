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
    button_action(game);
}

void main_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(69, 69, 69));
    sfRenderWindow_drawSprite(game->window, game->board->sprite, NULL);
    display_all_buttons(game);
    if (game->overlay == HELP) {
        sfText *text = sfText_create();
        sfText_setString(text, "Press 'H' to hide the help");
        sfText_setFont(text, game->font);
        sfText_setCharacterSize(text, 20);
        sfText_setPosition(text, (sfVector2f) {10, 10});
        sfRenderWindow_drawText(game->window, text, NULL);
        sfText_destroy(text);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft))
        game->overlay = NONE_OVERLAY;
    sfRenderWindow_display(game->window);
}
