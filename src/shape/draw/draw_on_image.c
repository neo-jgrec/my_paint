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
    game->board->mouse_pos = VEC2F_CAST(\
    sfMouse_getPositionRenderWindow(game->window));
    game->board->mouse_pos = VECT2F_SUB(game->board->mouse_pos,
    game->board->pos);
    game->board->mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
    VEC2I_CAST(game->board->mouse_pos), game->view);

    if (is_hovering(game->board->pos, game->window, game->board->size)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        draw_shape_on_sfimage(game);
        sfTexture_updateFromImage(game->board->texture,
        IMAGE, 0, 0);
        sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
    }
    game->board->last_pos = game->board->mouse_pos;
}
