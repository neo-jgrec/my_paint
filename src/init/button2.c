/*
** EPITECH PROJECT, 2023
** paint
** File description:
** button2
*/

#include "my.h"

int unzoom(game_t *game)
{
    if (game->board->scale.x > 1 && game->board->scale.y > 1) {
        game->board->scale = (sfVector2f){game->board->scale.x - 0.1,
        game->board->scale.y - 0.1};
        sfSprite_setScale(game->board->sprite, game->board->scale);
    }
    game->panel = NONE;
    return (0);
}

int zoom(game_t *game)
{
    if (game->board->scale.x < 5 && game->board->scale.y < 5) {
        game->board->scale = (sfVector2f){game->board->scale.x + 0.1,
        game->board->scale.y + 0.1};
        sfSprite_setScale(game->board->sprite, game->board->scale);
    }
    game->panel = NONE;
    return (0);
}

void init_zoom_unzoom(game_t *game)
{
    char *button_name[] = {"-", "+", NULL};
    sfVector2f button_size[] = {{25, 25}, {25, 25}};
    sfVector2f button_pos[] = {{sfRenderWindow_getSize(game->window).x - 50,
    0}, {sfRenderWindow_getSize(game->window).x - 25, 0}};

    for (int i = 0; i < 2; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        (i == 0) ? button->action = (void *)unzoom : 0;
        (i == 1) ? button->action = (void *)zoom : 0;
        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
}
