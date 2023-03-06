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
    game_t *game = malloc(sizeof(game_t));
    int alpha = 0;
    char *filepath = NULL;

    for (int i = 0; i < ac; i++) {
        if (my_strcmp(av[i], "-a") == 0)
            alpha = 1;
        if (my_strcmp(av[i], "-f") == 0) {
            filepath = av[i + 1];
            (opendir(filepath)) ? ({
                my_printf("Error: Invalid file path.\n");
                return (84);
            }) : (0);
        }
    }
    init_game(game, filepath, alpha);
    main_loop(game);
    return (0);
}
