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

void eraser_button(game_t *game)
{
    if (game->panel == EDIT_PANEL) {
        game->board->color = sfColor_fromRGBA(255, 255, 255, 0);
    }
}

void switch_brush(game_t *game)
{
    if (game->panel == EDIT_PANEL) {
        (sfClock_getElapsedTime(game->clock).microseconds > 100000) ? ({
            if (game->board->brush_type == CIRCLE) {
                game->board->brush_type = RECTANGLE;
                game->board->brush = create_rectangle_shape((sfVector2f){game->board->size_brush, game->board->size_brush}
                , ((game->board->color.a == 0) ? sfBlack : game->board->color));
                sfRectangleShape_setSize(game->board->brush, (sfVector2f){game->board->size_brush, game->board->size_brush});
            } else if (game->board->brush_type == RECTANGLE) {
                game->board->brush_type = CIRCLE;
                game->board->brush = create_circle_shape(game->board->size_brush, ((game->board->color.a == 0) ? sfBlack : game->board->color));
            }
            if (game->board->color.a == 0)
                game->board->color = sfBlack;
            sfClock_restart(game->clock);
        }) : ({});
    }
}
