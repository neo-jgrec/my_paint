/*
** EPITECH PROJECT, 2023
** paint
** File description:
** display
*/

#include "my.h"

void display_button(game_t *game, button_t *button)
{
    sfText *tmp_text = sfText_create();
    sfRenderWindow_drawRectangleShape(game->window, button->shape, NULL);
    sfText_setString(tmp_text, button->name);
    sfText_setFont(tmp_text, game->font);
    sfText_setCharacterSize(tmp_text, 15);
    sfText_setColor(tmp_text, sfWhite);
    sfText_setPosition(tmp_text, (sfVector2f) {button->pos.x + 10,
    button->pos.y + 5});
    sfRenderWindow_drawText(game->window, tmp_text, NULL);
    sfText_destroy(tmp_text);
}

void display_all_buttons(game_t *game)
{
    button_t *button;
    TAILQ_FOREACH(button, &game->buttons, next) {
        if ((my_strcmp(button->name, "File") == 0 || my_strcmp(button->name,
        "Edit") == 0 || my_strcmp(button->name, "Help") == 0))
            display_button(game, button);
        if (game->panel == FILE_PANEL &&
            (my_strcmp(button->name, "New") == 0 || my_strcmp(button->name,
            "Open") == 0 || my_strcmp(button->name, "Save") == 0 ||
            my_strcmp(button->name, "Exit") == 0))
                display_button(game, button);
        if (game->panel == EDIT_PANEL &&
            (my_strcmp(button->name, "Switch Brush") == 0
            || my_strcmp(button->name, "Color") == 0
            || my_strcmp(button->name, "Brush Size") == 0 ||
            my_strcmp(button->name, "Eraser") == 0))
                display_button(game, button);
        if (game->panel == HELP_PANEL && (my_strcmp(button->name, "About") == 0
        || my_strcmp(button->name, "Help.") == 0))
                display_button(game, button);
    }
}
