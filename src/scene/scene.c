/*
** EPITECH PROJECT, 2023
** paint
** File description:
** scene
*/

#include "my.h"

void scene_handler(game_t *game)
{
    switch (game->scene) {
        case MAIN:
            update_main_scene(game);
            main_scene(game);
            break;
        case EXIT:
            sfRenderWindow_close(game->window);
            break;
    }
}
