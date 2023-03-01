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
    game->board->size = (sfVector2f){400, 300};
    game->board->pos = (sfVector2f){266, 150};
    game->board->scale = (sfVector2f){1, 1};
    game->board->color = sfBlack;
    game->board->size_brush = 10;
    game->board->brush = create_circle_shape(game->board->size_brush,
    game->board->color);
    game->board->brush_type = CIRCLE;
    if (filepath != NULL)
        IMAGE = sfImage_createFromFile(filepath);
    else
        IMAGE = sfImage_createFromColor(
        game->board->size.x, game->board->size.y, sfWhite);
    game->board->texture = sfTexture_createFromImage(IMAGE,
    NULL);
    game->board->sprite = sfSprite_create();
    sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
    sfSprite_setPosition(game->board->sprite, game->board->pos);
    sfSprite_setScale(game->board->sprite, game->board->scale);
}

static void add_navbar_button(game_t *game)
{
    char *button_name[] = {"FILE", "EDIT", "HELP", NULL};
    sfVector2f button_pos[] = {{0, 0}, {100, 0}, {200, 0}, {0, 0}};
    sfVector2f button_size[] = {{100, 50}, {100, 50}, {100, 50}, {0, 0}};
    button_t *button = malloc(sizeof(button_t));

    for (int i = 0; button_name[i]; i++) {
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        button->callback = NULL;
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape, sfBlack);
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
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
    sfRenderWindow_hasFocus(game->window);
    sfRenderWindow_setVerticalSyncEnabled(game->window, sfTrue);
    sfRenderWindow_setFramerateLimit(game->window, 1000);
    init_board(game, filepath);
    TAILQ_INIT(&game->buttons);
    add_navbar_button(game);
}
