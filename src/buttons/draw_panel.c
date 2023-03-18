/*
** EPITECH PROJECT, 2023
** paint
** File description:
** draw_panel
*/

#include "my.h"

void display_panel_button(sfRenderWindow *window,
button_t *button, game_t *game)
{
    sfRenderWindow_drawRectangleShape(window, button->shape, NULL);
    sfText *text = sfText_create();
    sfText_setFont(text, game->font);
    sfText_setString(text, button->name);
    sfText_setCharacterSize(text, 15);
    sfText_setPosition(text, (sfVector2f) {button->pos.x + 10,
    button->pos.y + 5});
    sfText_setColor(text, sfBlack);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

void draw_panel(game_t *game)
{
    button_t *button = NULL;
    TAILQ_FOREACH(button, &game->buttons, next) {
        if (my_strcmp(button->name, "Change Brush") == 0
        || my_strcmp(button->name, "Change Color") == 0
        || my_strcmp(button->name, "Change Size") == 0)
            display_panel_button(game->panel_window, button, game);
    }
}
