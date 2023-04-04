/*
** @neo-jgrec, 2023
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
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    game->board->mouse_pos = (sfVector2f){mouse_pos.x, mouse_pos.y};
    game->board->mouse_pos.x -= sfSprite_getGlobalBounds(\
    game->board->sprite).left;
    game->board->mouse_pos.y -= sfSprite_getGlobalBounds(\
    game->board->sprite).top;
    game->board->pos = sfSprite_getPosition(game->board->sprite);

    if (is_hovering(game->board->pos, game->window, game->board->size)
    && sfMouse_isButtonPressed(sfMouseLeft) && (game->board->scale.x == 1 &&
    game->board->scale.y <= 1.5)) {
        draw_shape_on_sfimage(game);
        sfTexture_updateFromImage(game->board->texture,
        IMAGE, 0, 0);
        sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
    }
    game->board->last_pos = game->board->mouse_pos;
}
