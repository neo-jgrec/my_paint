/*
** EPITECH PROJECT, 2023
** paint
** File description:
** menu_bar
*/

#include "my.h"

void version_text_position(game_t *game)
{
    sfText_setPosition(game->about->text, (sfVector2f) {
        sfRenderWindow_getSize(\
        game->window).x - sfText_getGlobalBounds(\
        game->about->text).width - 10,
        (0 - sfText_getGlobalBounds(game->about->text).height / 2) + 10
    });
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

void change_button_state(button_t *button, game_t *game)
{
    if (is_button_hover(button, game) == true) {
        if (game->event.type == sfEvtMouseButtonPressed
        && game->event.mouseButton.button == sfMouseLeft) {
            button->state = CLICKED;
        } else {
            button->state = HOVER;
        }
    } else {
        button->state = IDLE;
    }
}

static void clicked_action(button_t *button, game_t *game)
{
    if (button->state == CLICKED) {
        if (my_strcmp(button->name, "File") == 0)
            game->panel = FILE_PANEL;
        if (my_strcmp(button->name, "Edit") == 0)
            game->panel = EDIT_PANEL;
        if (my_strcmp(button->name, "Help") == 0)
            game->panel = HELP_PANEL;
    }
    if (my_strcmp(button->name, "-") == 0) {
        button->pos = (sfVector2f) {\
        sfRenderWindow_getSize(game->window).x - 50, 0};
        sfRectangleShape_setPosition(button->shape, button->pos);
    }
    if (my_strcmp(button->name, "+") == 0) {
        button->pos = (sfVector2f) {\
        sfRenderWindow_getSize(game->window).x - 25, 0};
        sfRectangleShape_setPosition(button->shape, button->pos);
    }
    if (button->action != NULL && button->state == CLICKED)
        button->action(game);
}

void button_action(game_t *game)
{
    button_t *button;

    TAILQ_FOREACH(button, &game->buttons, next) {
        if (my_strcmp(button->name, "Change Brush") == 0
        || my_strcmp(button->name, "Change Color") == 0
        || my_strcmp(button->name, "Change Size") == 0)
            continue;
        change_button_state(button, game);
        if (button->state == HOVER)
            sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
            (31, 31, 31));
        if (button->state == IDLE)
            sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
            (72, 72, 72));
        if (button->state == CLICKED)
            sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
            (31, 31, 31));
        clicked_action(button, game);
    }
}
