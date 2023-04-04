/*
** @neo-jgrec, 2023
** paint
** File description:
** button_event3
*/

#include "my.h"

int side_panel(game_t *game)
{
    if (game->panel == EDIT_PANEL) {
        if (game->is_panel == false) {
            game->panel_window = sfRenderWindow_create(
            (sfVideoMode){175, 300, 32}, "Panel", sfClose, NULL);
            game->is_panel = true;
            game->panel = NONE;
        } else {
            sfRenderWindow_close(game->panel_window);
            game->is_panel = false;
            game->panel = NONE;
        }
    }
    return (0);
}
