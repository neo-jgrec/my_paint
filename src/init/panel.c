/*
** @neo-jgrec, 2023
** paint
** File description:
** panel
*/

#include "my.h"

void add_panel_button(game_t *game)
{
    game->panel_window = sfRenderWindow_create((sfVideoMode){175, 300, 32},
    "Panel", sfClose, NULL); game->is_panel = true;
    char *button_name[] = {"Change Brush", "Change Color", "Change Size",
    NULL};
    sfVector2f button_size[] = {{125, 25}, {125, 25}, {125, 25}, {0, 0}};
    sfVector2f button_pos[] = {{25, 50}, {25, 150}, {25, 250}, {0, 0}};
    for (int i = 0; i < 3; i++) {
        button_t *button = malloc(sizeof(button_t));
        button->name = button_name[i]; button->pos = button_pos[i];
        button->size = button_size[i];
        button->shape = sfRectangleShape_create();
        sfRectangleShape_setPosition(button->shape, button->pos);
        sfRectangleShape_setSize(button->shape, button->size);
        (i == 0) ? button->action = (void *)switch_brush : 0;
        (i == 1) ? button->action = (void *)color_picker : 0;
        (i == 2) ? button->action = (void *)brush_size : 0;
        button->state = IDLE;
        TAILQ_INSERT_TAIL(&game->buttons, button, next);
    }
}
