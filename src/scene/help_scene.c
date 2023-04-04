/*
** @neo-jgrec, 2023
** paint
** File description:
** help_scene
*/

#include "my.h"

void event_help_handler(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEscape) {
        game->scene = MAIN;
    }
    if (game->event.type == sfEvtResized) {
        sfVector2u size = {game->event.size.width, game->event.size.height};
        sfView *view = sfView_createFromRect((sfFloatRect){0, 0,
        (float)size.x, (float)size.y});
        sfRenderWindow_setView(game->window, view);
        sfView_destroy(view);
    }
}

void update_help_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        event_help_handler(game);
}

void help_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(69, 69, 69));
    sfText *text = sfText_create();
    sfText_setFont(text, game->font);
    sfText_setString(text, "Press ESC to go back to the main menu");
    sfText_setCharacterSize(text, 10);
    sfText_setPosition(text, (sfVector2f) {
        sfRenderWindow_getSize(game->window).x / 2 - 100,
        sfRenderWindow_getSize(game->window).y - 100});
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_setString(text, HELP);
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, (sfVector2f){10, 10});
    sfRenderWindow_drawText(game->window, text, NULL);
    sfRenderWindow_display(game->window);
    sfText_destroy(text);
}
