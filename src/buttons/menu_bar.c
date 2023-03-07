/*
** EPITECH PROJECT, 2023
** paint
** File description:
** menu_bar
*/

#include "my.h"

bool is_button_hover(game_t *game)
{
    button_t *button;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    TAILQ_FOREACH(button, &game->buttons, next) {
        if (mouse_pos.x >= button->pos.x && mouse_pos.x <= button->pos.x +
        button->size.x && mouse_pos.y >= button->pos.y && mouse_pos.y <=
        button->pos.y + button->size.y) {
            button->state = HOVER;
            return (true);
        } else {
            button->state = IDLE;
        }
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

void display_buttons(game_t *game)
{
    button_t *button;
    sfText *tmp_text;

    TAILQ_FOREACH(button, &game->buttons, next) {
        if ((my_strcmp(button->name, "FILE") == 0 || my_strcmp(button->name,
        "EDIT") == 0 || my_strcmp(button->name, "HELP") == 0)) {
            sfRenderWindow_drawRectangleShape(game->window, button->shape,
            NULL);
            tmp_text = sfText_create();
            sfText_setString(tmp_text, button->name);
            sfText_setFont(tmp_text, game->font);
            sfText_setCharacterSize(tmp_text, 15);
            sfText_setColor(tmp_text, sfBlack);
            sfText_setPosition(tmp_text, (sfVector2f) {button->pos.x + 10,
            button->pos.y + 5});
            sfRenderWindow_drawText(game->window, tmp_text, NULL);
            sfText_destroy(tmp_text);
        }
        if (my_strcmp(button->name, "FILE") == 0 && button->state == HOVER) {
            button_t *sub_button;

            TAILQ_FOREACH(sub_button, &game->buttons, next) {
                if (my_strcmp(sub_button->name, "FILE") == 0 ||
                my_strcmp(sub_button->name, "EDIT") == 0 ||
                my_strcmp(sub_button->name, "HELP") == 0) {
                    continue;
                }
                sfRenderWindow_drawRectangleShape(game->window,
                sub_button->shape, NULL);
                tmp_text = sfText_create();
                sfText_setString(tmp_text, sub_button->name);
                sfText_setFont(tmp_text, game->font);
                sfText_setCharacterSize(tmp_text, 15);
                sfText_setColor(tmp_text, sfBlack);
                sfText_setPosition(tmp_text, (sfVector2f) {sub_button->pos.x +
                10, sub_button->pos.y + 5});
                sfRenderWindow_drawText(game->window, tmp_text, NULL);
                sfText_destroy(tmp_text);
            }
        }
        button->state = IDLE;
    }
}
