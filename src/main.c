/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** main grep -rin bool
*/

#include "my.h"

bool is_hovering(sfVector2f pos, sfRenderWindow *window, sfVector2f size)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.x
    && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.y)
        return (true);
    return (false);
}

void main_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window))
        scene_handler(game);
}

int main(int ac, char **av)
{
    game_t *game;

    if (ac > 2)
        return (84);
    game = malloc(sizeof(game_t));
    init_game(game, (ac == 2) ? av[1] : NULL);
    main_loop(game);
    return (0);
}
