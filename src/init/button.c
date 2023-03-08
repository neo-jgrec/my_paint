/*
** EPITECH PROJECT, 2023
** paint
** File description:
** button
*/

#include "my.h"

static void init_file_button(game_t *game)
{
    char *button_name[] = {"New", "Open", "Save", "Exit", NULL};
    int nb_of_button = 4;
    sfVector2f button_size[] = {{50, 25}, {50, 25}, {50, 25}, {50, 25}};
    sfVector2f button_pos[] = {{0, 25}, {0, 50}, {0, 75}, {0, 100}};

    for (int i = 0; i < nb_of_button; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape,
        sfColor_fromRGB(59, 59, 59));
        (i == 0) ? button->action = (void *)new_file : 0;
        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
}

static void init_edit_button(game_t *game)
{
    char *button_name[] = {"Brush", "Eraser", "Color", "Brush Size", NULL};
    int nb_of_button = 4;
    sfVector2f button_size[] = {{50, 25}, {50, 25}, {50, 25}, {50, 25}};
    sfVector2f button_pos[] = {{50, 25}, {50, 50}, {50, 75}, {50, 100}};

    for (int i = 0; i < nb_of_button; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape,
        sfColor_fromRGB(59, 59, 59));

        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
}

static void init_help_button(game_t *game)
{
    char *button_name[] = {"About", "Help.", NULL};
    int nb_of_button = 2;
    sfVector2f button_size[] = {{50, 25}, {50, 25}};
    sfVector2f button_pos[] = {{100, 25}, {100, 50}};

    for (int i = 0; i < nb_of_button; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape,
        sfColor_fromRGB(59, 59, 59));
        (i == 1 && my_strcmp(button->name, "Help.") == 0) ?
        button->action = (void *)help : 0;
        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
}

void add_navbar_button(game_t *game)
{
    char *button_name[] = {"File", "Edit", "Help", NULL};
    int nb_of_button = 3;
    sfVector2f button_size[] = {{50, 25}, {50, 25}, {50, 25}};
    sfVector2f button_pos[] = {{0, 0}, {50, 0}, {100, 0}};
    for (int i = 0; i < nb_of_button; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        button->action = NULL;
        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
    init_file_button(game);
    init_edit_button(game);
    init_help_button(game);
}
