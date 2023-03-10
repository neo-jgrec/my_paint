/*
** EPITECH PROJECT, 2023
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
    sfText_setString(text, "HELP");
    sfText_setFont(text, game->font);
    sfText_setCharacterSize(text, 100);
    sfText_setPosition(text, (sfVector2f) {100, 100});
    sfRenderWindow_drawText(game->window, text, NULL);
    sfRenderWindow_display(game->window);
    sfText_destroy(text);
}
