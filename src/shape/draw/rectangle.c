/*
** EPITECH PROJECT, 2023
** paint
** File description:
** rectangle
*/

#include "my.h"

static void draw_line_rectangle(game_t *game, int i, int size_y)
{
    sfVector2f pos = game->board->mouse_pos;
    sfColor color = game->board->color;

    if (VECT2F_MANHATTAN(pos, game->board->last_pos) > 1) {
        sfVector2f dir = VECT2F_SUB(pos, game->board->last_pos);
        sfVector2f dir_norm = VECT2F_NORMALIZE(dir);
        sfVector2f line = game->board->last_pos;
        for (int k = 0; k < VECT2F_MANHATTAN(pos, game->board->last_pos); k++) {
            line = VECT2F_ADD(line, dir_norm);
            (line.x + i < sfImage_getSize(IMAGE).x
            && line.x - i >= 0 && line.y - size_y >= 0
            && line.y + size_y < sfImage_getSize(IMAGE).y) ? ({
                sfImage_setPixel(IMAGE, line.x + i, line.y + size_y, color);
                sfImage_setPixel(IMAGE, line.x - i, line.y + size_y, color);
                sfImage_setPixel(IMAGE, line.x + i, line.y - size_y, color);
                sfImage_setPixel(IMAGE, line.x - i, line.y - size_y, color);
            }) : (0);
        }
    }
}

void draw_rectangle_on_sfimage(game_t *game)
{
    sfVector2f pos = game->board->mouse_pos;
    sfVector2f size = sfRectangleShape_getSize((sfRectangleShape*)game->board->brush);
    sfColor color = game->board->color;

    for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++) {
            (pos.x + i < sfImage_getSize(IMAGE).x
            && pos.x - i >= 0 && pos.y - j >= 0
            && pos.y + j < sfImage_getSize(IMAGE).y) ?
            ({
            sfImage_setPixel(IMAGE, pos.x + i, pos.y + j, color);
            sfImage_setPixel(IMAGE, pos.x - i, pos.y + j, color);
            sfImage_setPixel(IMAGE, pos.x + i, pos.y - j, color);
            sfImage_setPixel(IMAGE, pos.x - i, pos.y - j, color);
            }) : (0);
            draw_line_rectangle(game, i, j);
        }
    }
}
