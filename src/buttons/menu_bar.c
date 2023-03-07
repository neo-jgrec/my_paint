/*
** EPITECH PROJECT, 2023
** paint
** File description:
** menu_bar
*/

#include "my.h"

int is_panel(button_t *button, game_t *game)
{
    char *panel_name[] = {"FILE", "EDIT", "HELP", NULL};
    int nb_of_panel = 3;

    for (int i = 0; i < nb_of_panel; i++) {
        if (my_strcmp(button->name, panel_name[i]) == 0) {
            game->panel = i + 1;
            return (1);
        }
    }
    return (0);
}

bool are_buttons_hover(game_t *game)
{
    button_t *button;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    TAILQ_FOREACH(button, &game->buttons, next) {
        if (mouse_pos.x >= button->pos.x && mouse_pos.x <= button->pos.x +
        button->size.x && mouse_pos.y >= button->pos.y && mouse_pos.y <=
        button->pos.y + button->size.y) {
            button->state = HOVER;
            is_panel(button, game);
            return (true);
        }
        button->state = IDLE;
    }
    return (false);
}

bool is_button_hover(button_t *button, game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_pos.x >= button->pos.x && mouse_pos.x <= button->pos.x +
    button->size.x && mouse_pos.y >= button->pos.y && mouse_pos.y <=
    button->pos.y + button->size.y) {
        return (true);
    }
    return (false);
}

void button_action(game_t *game)
{
    button_t *button;

    TAILQ_FOREACH(button, &game->buttons, next) {
        switch (button->state) {
            case HOVER:
                sfRectangleShape_setFillColor(button->shape, sfBlue);
                break;
            case IDLE:
                sfRectangleShape_setFillColor(button->shape, sfCyan);
                break;
            default:
                break;
        }
    }
}
