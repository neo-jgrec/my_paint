/*
** EPITECH PROJECT, 2023
** paint
** File description:
** circle
*/

#include "my.h"

static void draw_line_circle(game_t *game, int i, int j, float radius)
{
    sfVector2f pos = game->board->mouse_pos;
    if (VECT2F_MANHATTAN(pos, game->board->last_pos) > 1) {
        sfVector2f dir = VECT2F_SUB(pos, game->board->last_pos);
        sfVector2f dir_norm = VECT2F_NORMALIZE(dir);
        sfVector2f line = game->board->last_pos;
        for (int k = 0; k < VECT2F_MANHATTAN(pos, game->board->last_pos); k++) {
        line = VECT2F_ADD(line, dir_norm);
        (i * i + j * j <= radius * radius
        && i * i + j * j >= (radius - BRUSH_SIZE) * (radius - BRUSH_SIZE)
        && line.x + i < sfSprite_getTextureRect(game->board->sprite).width
        && line.x - i >= 0 && line.y - j >= 0
        && line.y + j < sfSprite_getTextureRect(game->board->sprite).height) ?
        ({  sfImage_setPixel(IMAGE, line.x + i, line.y + j, BRUSH_COLOR);
            sfImage_setPixel(IMAGE, line.x - i, line.y + j, BRUSH_COLOR);
            sfImage_setPixel(IMAGE, line.x + i, line.y - j, BRUSH_COLOR);
            sfImage_setPixel(IMAGE, line.x - i, line.y - j, BRUSH_COLOR);
        }) : (0);
        }
    }
}

void draw_circle_on_sfimage(game_t *game)
{
    float radius = BRUSH_SIZE;
    sfColor color = game->board->color;
    sfVector2f pos = game->board->mouse_pos;
    for (int i = 0; i < radius; i++) {
        for (int j = 0; j < radius; j++) {
            (i * i + j * j <= radius * radius
            && i * i + j * j >= (radius - BRUSH_SIZE) * (radius - BRUSH_SIZE)
            && pos.x + i < sfSprite_getTextureRect(\
            game->board->sprite).width
            && pos.x - i >= 0 && pos.y - j >= 0
            && pos.y + j < sfSprite_getTextureRect(\
            game->board->sprite).height) ? ({
            sfImage_setPixel(IMAGE, pos.x + i, pos.y + j, color);
            sfImage_setPixel(IMAGE, pos.x - i, pos.y + j, color);
            sfImage_setPixel(IMAGE, pos.x + i, pos.y - j, color);
            sfImage_setPixel(IMAGE, pos.x - i, pos.y - j, color);
            }) : (0);
            draw_line_circle(game, i, j, radius);
        }
    }
}
