/*
** EPITECH PROJECT, 2023
** paint
** File description:
** game
*/

#include "my.h"

static void init_board(game_t *game, char *filepath)
{
    game->board = malloc(sizeof(board_t));
    game->board->pos = (sfVector2f){0, 0};
    game->board->size = (sfVector2f){800, 600};
    game->board->scale = (sfVector2f){1, 1};
    game->board->mouse_pos = (sfVector2f){0, 0};
    if (filepath != NULL)
        game->board->image = sfImage_createFromFile(filepath);
    if (game->board->image == NULL)
        game->board->image = sfImage_create(game->board->size.x,
        game->board->size.y);
    game->board->texture = sfTexture_createFromImage(game->board->image, NULL);
    game->board->sprite = sfSprite_create();
    sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
    sfSprite_setPosition(game->board->sprite, game->board->pos);
    sfSprite_setScale(game->board->sprite, game->board->scale);
}

void init_game(game_t *game, char *filepath)
{
    game->scene = MAIN;
    game->window = sfRenderWindow_create((sfVideoMode){800, 600, 32},
    "my_paint", sfResize | sfClose, NULL);
    game->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setKeyRepeatEnabled(game->window, sfFalse);
    init_board(game, filepath);
}
