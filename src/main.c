/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** main grep -rin bool
*/

#include "my.h"

void scene_handler(game_t *game)
{
    switch (game->scene) {
        case MAIN:
            // main_scene(game);
            break;
        case EXIT:
            sfRenderWindow_close(game->window);
            break;
    }
}

void event_handler(game_t *game)
{
    if (game->event.type == sfEvtClosed ||
    (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEscape))
        sfRenderWindow_close(game->window);
}

void main_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            event_handler(game);
        scene_handler(game);
    }
}

int main(int ac, char **av)
{
    game_t *game;

    if (ac > 2)
        return (84);
    game = malloc(sizeof(game_t));
    init_game(game, (ac == 2) ? av[1] : NULL);
    main_loop(game);
    return (0);
}
