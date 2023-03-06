/*
** EPITECH PROJECT, 2023
** paint
** File description:
** button
*/

#include "my.h"

void add_navbar_button(game_t *game)
{
    char *button_name[] = {"FILE", "EDIT", "HELP", NULL};
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
        sfRectangleShape_setFillColor(button->shape, sfCyan);
        sfRectangleShape_setOutlineColor(button->shape, sfBlack);
        sfRectangleShape_setOutlineThickness(button->shape, 1);

        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
    char *sub_menu_file[] = {"NEW", "OPEN", "SAVE", "EXIT", NULL};
    int nb_sub_button_file = 4;
    char *sub_menu_edit[] = {"BRUSH", "ERASER", "COLOR", "BRUSH SIZE", NULL};
    int nb_sub_button_edit = 4;
    char *sub_menu_help[] = {"LOGIN", "HELP", NULL};
    int nb_sub_button_help = 2;

    for (int i = 0; i < nb_sub_button_file; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = sub_menu_file[i];
        button->pos = (sfVector2f) {0, 25 + (i * 25)};
        button->size = (sfVector2f) {50, 25};
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape, sfCyan);
        sfRectangleShape_setOutlineColor(button->shape, sfBlack);
        sfRectangleShape_setOutlineThickness(button->shape, 1);

        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
    for (int i = 0; i < nb_sub_button_edit; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = sub_menu_edit[i];
        button->pos = (sfVector2f) {50, 25 + (i * 25)};
        button->size = (sfVector2f) {50, 25};
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape, sfCyan);
        sfRectangleShape_setOutlineColor(button->shape, sfBlack);
        sfRectangleShape_setOutlineThickness(button->shape, 1);

        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
    for (int i = 0; i < nb_sub_button_help; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = sub_menu_help[i];
        button->pos = (sfVector2f) {100, 25 + (i * 25)};
        button->size = (sfVector2f) {50, 25};
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        sfRectangleShape_setFillColor(button->shape, sfCyan);
        sfRectangleShape_setOutlineColor(button->shape, sfBlack);
        sfRectangleShape_setOutlineThickness(button->shape, 1);

        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }

}
