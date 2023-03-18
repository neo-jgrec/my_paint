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
    sfVector2f button_size[] = {{60, 25}, {60, 25}, {60, 25}, {60, 25}};
    sfVector2f button_pos[] = {{0, 25}, {0, 50}, {0, 75}, {0, 100}};

    for (int i = 0; i < 4; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        (i == 0) ? button->action = (void *)new_file : 0;
        (i == 1) ? button->action = (void *)open_file : 0;
        (i == 2) ? button->action = (void *)save_file : 0;
        (i == 3) ? button->action = (void *)button_exit : 0;
        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
}

static void init_edit_button(game_t *game)
{
    char *button_name[] = {"Switch Brush", "Eraser", "Color", "Brush Size",
    "Side Panel", NULL};
    sfVector2f button_size[] = {{125, 25}, {125, 25}, {125, 25}, {125, 25},
    {125, 25}};
    sfVector2f button_pos[] = {{75, 25}, {75, 50}, {75, 75}, {75, 100},
    {75, 125}};
    for (int i = 0; i < 5; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i]; button->pos = button_pos[i];
        button->size = button_size[i]; button->state = IDLE;
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        (i == 0) ? button->action = (void *)switch_brush : 0;
        (i == 1) ? button->action = (void *)eraser_button : 0;
        (i == 2) ? button->action = (void *)color_picker : 0;
        (i == 3) ? button->action = (void *)brush_size : 0;
        (i == 4) ? button->action = (void *)side_panel : 0;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
}

static void init_about(game_t *game)
{
    game->about = malloc(sizeof(about_t));
    game->about->is_about = false;
    game->about->text = sfText_create();
    sfText_setString(game->about->text, VERSION);
    sfText_setFont(game->about->text, game->font);
    sfText_setCharacterSize(game->about->text, 20);
    sfText_setPosition(game->about->text, (sfVector2f) {
        sfRenderWindow_getSize(\
        game->window).x - sfText_getGlobalBounds(game->about->text).width - 10,
        (0 - sfText_getGlobalBounds(game->about->text).height / 2) + 10
    });
    sfText_setColor(game->about->text, sfWhite);
}

static void init_help_button(game_t *game)
{
    char *button_name[] = {"About", "Help.", NULL};
    sfVector2f button_size[] = {{75, 25}, {75, 25}};
    sfVector2f button_pos[] = {{150, 25}, {150, 50}};

    for (int i = 0; i < 2; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i];
        button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        (i == 1 && my_strcmp(button->name, "Help.") == 0) ?
        button->action = (void *)help : 0;
        (i == 0 && my_strcmp(button->name, "About") == 0) ?
        button->action = (void *)about : 0;
        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
    init_about(game);
}

void add_navbar_button(game_t *game)
{
    char *button_name[] = {"File", "Edit", "Help", NULL};
    sfVector2f button_size[] = {{75, 25}, {75, 25}, {75, 25}};
    sfVector2f button_pos[] = {{0, 0}, {75, 0}, {150, 0}};

    for (int i = 0; i < 3; i++) {
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
    init_zoom_unzoom(game);
}
