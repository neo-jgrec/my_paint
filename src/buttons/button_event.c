/*
** @neo-jgrec, 2023
** paint
** File description:
** button_event
*/

#include "my.h"

void new_file(game_t *game)
{
    if (game->panel == FILE_PANEL) {
        game->board->image = sfImage_createFromColor(700, 400, sfWhite);
        game->board->texture = sfTexture_createFromImage(game->board->image,
        NULL);
        sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
        game->panel = NONE;
    }
}

void help(game_t *game)
{
    if (game->panel == HELP_PANEL) {
        if (game->scene == HELP_SCENE)
            game->scene = MAIN;
        else
            game->scene = HELP_SCENE;
        game->panel = NONE;
    }
}

void about(game_t *game)
{
    if (game->panel == HELP_PANEL) {
        if (game->about->is_about == true)
            game->about->is_about = false;
        else
            game->about->is_about = true;
        game->panel = NONE;
    }
}

void button_exit(game_t *game)
{
    game->scene = EXIT;
}

void save_file(game_t *game)
{
    if (game->panel == FILE_PANEL) {
        game->input_box->action = SAVE;
        game->input_box->title = "Save";
        game->scene = INPUT_SCENE;
    }
}
