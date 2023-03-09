/*
** EPITECH PROJECT, 2023
** paint
** File description:
** draw_on_image
*/

#include "my.h"

void draw_shape_on_sfimage(game_t *game)
{
    switch (game->board->brush_type) {
        case CIRCLE:
            draw_circle_on_sfimage(game);
            break;
        case RECTANGLE:
            draw_rectangle_on_sfimage(game);
            break;
        default:
            break;
    }
}

void draw_on_board(game_t *game)
{
    game->board->mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
    sfMouse_getPositionRenderWindow(game->window), NULL);
    game->board->mouse_pos.x -= game->board->pos.x;
    game->board->mouse_pos.y -= game->board->pos.y;


    if (is_hovering(game->board->pos, game->window, game->board->size)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_shape_on_sfimage(game);
        sfTexture_updateFromImage(game->board->texture,
        IMAGE, 0, 0);
        sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
    }
    game->board->last_pos = game->board->mouse_pos;
}
