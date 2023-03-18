/*
** EPITECH PROJECT, 2023
** paint
** File description:
** scene
*/

#include "my.h"

static bool is_button_hover_window(button_t *button, sfRenderWindow *window)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (mouse_pos.x >= button->pos.x && mouse_pos.x <= button->pos.x +
    button->size.x && mouse_pos.y >= button->pos.y && mouse_pos.y <=
    button->pos.y + button->size.y) {
        return (true);
    }
    return (false);
}

void button_action2(button_t *button, game_t *game)
{
    if (is_button_hover_window(button, game->panel_window)) {
        if (game->event.type == sfEvtMouseButtonPressed
        && game->event.mouseButton.button == sfMouseLeft)
            button->state = CLICKED;
        else
            button->state = HOVER;
    } else
        button->state = IDLE;
    if (button->state == CLICKED)
        button->action(game);
    if (button->state == HOVER)
        sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
        (31, 31, 31));
    if (button->state == IDLE)
        sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
        (72, 72, 72));
    if (button->state == CLICKED) {
        sfRectangleShape_setFillColor(button->shape, sfColor_fromRGB
        (31, 31, 31)); game->panel = EDIT_PANEL; button->action(game);
    }
}

void panel_window(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->panel_window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->panel_window);
        button_t *button;
        TAILQ_FOREACH(button, &game->buttons, next)
            button_action2(button, game);
    }
    sfRenderWindow_clear(game->panel_window, sfColor_fromRGB(69, 69, 69));
    draw_panel(game);
    sfRenderWindow_display(game->panel_window);
}

void scene_handler(game_t *game)
{
    (game->scene == MAIN) ? ({
        update_main_scene(game);
        main_scene(game);}) : ({});
    (game->scene == HELP_SCENE) ? ({
        update_help_scene(game);
        help_scene(game);}) : ({});
    (game->scene == INPUT_SCENE) ? ({
        update_input_scene(game);
        input_scene(game);}) : ({});
    (game->scene == COLOR_SCENE) ? ({
        update_color_scene(game);
        color_scene(game);}) : ({});
    (game->scene == EXIT) ? ({
        sfRenderWindow_close(game->window);
        sfRenderWindow_close(game->panel_window);}) : ({});
    if (game->is_panel == true) panel_window(game);
}
