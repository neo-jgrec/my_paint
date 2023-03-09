/*
** EPITECH PROJECT, 2023
** paint
** File description:
** button_event
*/

#include "my.h"

void new_file(game_t *game)
{
    game->board->image = sfImage_createFromColor(400, 300, sfWhite);
    game->board->texture = sfTexture_createFromImage(game->board->image, NULL);
    sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
}

void help(game_t *game)
{
    game->overlay = HELP;
}
