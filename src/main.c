/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** main grep -rin bool
*/

#include "my.h"

void scene_handler(game_t *game)
{
    switch (game->state) {
        case MENU:
            // menu(game);
            break;
        case GAME:
            // game_loop(game);
            break;
        case PAUSE:
            // pause_menu(game);
            break;
        case END:
            // end_menu(game);
            break;
        case EXIT:
            sfRenderWindow_close(game->window);
            break;
    }
}

void main_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event)) {
            if (game->event.type == sfEvtClosed)
                sfRenderWindow_close(game->window);
        }
        scene_handler(game);
    }
}

void init_game(game_t *game)
{
    game->state = MENU;
    game->window = sfRenderWindow_create((sfVideoMode){1920, 1080, 32},
    "my_paint", sfResize | sfClose, NULL);
    game->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
}

int main( UNUSED int ac, UNUSED char **av)
{
    game_t *game = malloc(sizeof(game_t));
    init_game(game);
    main_loop(game);
    return (0);
}
