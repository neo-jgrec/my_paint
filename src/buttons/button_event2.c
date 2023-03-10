/*
** EPITECH PROJECT, 2023
** paint
** File description:
** button_event2
*/

#include "my.h"

void open_file(game_t *game)
{
    if (game->panel == FILE_PANEL) {
        game->input_box->action = LOAD;
        game->input_box->title = "Load file";
        game->scene = INPUT_SCENE;
    }
}
