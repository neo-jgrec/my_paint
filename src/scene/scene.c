/*
** EPITECH PROJECT, 2023
** paint
** File description:
** scene
*/

#include "my.h"

void scene_handler(game_t *game)
{
    (game->scene == MAIN) ? ({
        update_main_scene(game);
        main_scene(game);
    }) : ({});
    (game->scene == HELP_SCENE) ? ({
        update_help_scene(game);
        help_scene(game);
    }) : ({});
    (game->scene == INPUT_SCENE) ? ({
        update_input_scene(game);
        input_scene(game);
    }) : ({});
    (game->scene == COLOR_SCENE) ? ({
        update_color_scene(game);
        color_scene(game);
    }) : ({});
    (game->scene == EXIT) ? ({
        sfRenderWindow_close(game->window);
    }) : ({});
}
