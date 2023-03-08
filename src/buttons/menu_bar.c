/*
** EPITECH PROJECT, 2023
** paint
** File description:
** menu_bar
*/

#include "my.h"

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

void change_button_state(button_t *button, game_t *game)
{
    if (is_button_hover(button, game) == true) {
        if (game->event.type == sfEvtMouseButtonPressed &&
        game->event.mouseButton.button == sfMouseLeft) {
            button->state = CLICKED;
        } else {
            button->state = HOVER;
        }
    } else {
        button->state = IDLE;
    }
}

void button_action(game_t *game)
{
    button_t *button;

    TAILQ_FOREACH(button, &game->buttons, next) {
        change_button_state(button, game);
        switch (button->state) {
            case HOVER:
                sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
                (31, 31, 31));
                break;
            case IDLE:
                sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
                (72, 72, 72));
                break;
            case CLICKED:
                sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
                (31, 31, 31));
                break;
            default:
                break;
        }
        if (button->state == CLICKED) {
            if (my_strcmp(button->name, "File") == 0)
                game->panel = FILE_PANEL;
            if (my_strcmp(button->name, "Edit") == 0)
                game->panel = EDIT_PANEL;
            if (my_strcmp(button->name, "Help") == 0)
                game->panel = HELP_PANEL;
        }
        if (button->action != NULL && button->state == CLICKED)
            button->action(game);
    }
}
