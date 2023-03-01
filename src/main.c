/*
** EPITECH PROJECT, 2022
** my_paint
** File description:
** main grep -rin bool
*/

#include "my.h"

bool sfIsHovering(sfVector2f pos, sfRenderWindow *window, sfVector2f size)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);

    if (mouse_pos.x >= pos.x && mouse_pos.x <= pos.x + size.x
    && mouse_pos.y >= pos.y && mouse_pos.y <= pos.y + size.y)
        return (true);
    return (false);
}

sfVector2f *sfConvexShape_getPoints(sfConvexShape *shape)
{
    sfVector2f *points = malloc(sizeof(sfVector2f) *
    sfConvexShape_getPointCount(shape));

    for (size_t i = 0; i < sfConvexShape_getPointCount(shape); i++)
        points[i] = sfConvexShape_getPoint(shape, i);
    return (points);
}

void sfImage_drawRectangle(sfImage *image, sfVector2f pos, sfVector2f size,
sfColor color)
{
    sfVector2f pos2 = {0, 0};

    for (int i = 0; i < size.x; i++) {
        for (int j = 0; j < size.y; j++) {
            pos2.x = pos.x + i;
            pos2.y = pos.y + j;
            if (pos2.x < 0 || pos2.x >= sfImage_getSize(image).x
            || pos2.y < 0 || pos2.y >= sfImage_getSize(image).y)
                continue;
            sfImage_setPixel(image, pos2.x, pos2.y, color);
        }
    }
}

void sfDraw_ShapeOnImage(sfImage *image, sfConvexShape *shape, sfColor color,
float size)
{
    sfVector2f pos = {0, 0};
    sfVector2f size_shape = {0, 0};
    sfVector2f *points = sfConvexShape_getPoints(shape);
    int nb_points = sfConvexShape_getPointCount(shape);

    for (int i = 0; i < nb_points; i++) {
        pos.x = points[i].x;
        pos.y = points[i].y;
        size_shape.x = size;
        size_shape.y = size;
        sfImage_createMaskFromColor(image, color, 0);
        sfImage_drawRectangle(image, pos, size_shape, color);
    }
}

void draw_on_board(game_t *game, sfConvexShape *shape, sfColor color,
float size)
{
    sfVector2f mouse_pos = {sfMouse_getPositionRenderWindow(game->window).x -
    game->board->pos.x, sfMouse_getPositionRenderWindow(game->window).y -
    game->board->pos.y};
    if (shape == NULL) {
        shape = sfConvexShape_create();
        sfConvexShape_setPointCount(shape, 4);
        for (int i = 0; i < 4; i++)
            sfConvexShape_setPoint(shape, i, (sfVector2f){0, 0});
    }

    sfConvexShape_setFillColor(shape, color);
    sfConvexShape_setOutlineColor(shape, color);
    sfConvexShape_setOutlineThickness(shape, size);
    sfConvexShape_setPosition(shape, mouse_pos);
    if (sfIsHovering(game->board->pos, game->window, game->board->size)
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        for (size_t i = 0; i < sfConvexShape_getPointCount(shape); i++)
            sfConvexShape_setPoint(shape, i, (sfVector2f){mouse_pos.x, mouse_pos.y});
        sfDraw_ShapeOnImage(game->board->image, shape, color, size);
        sfTexture_updateFromImage(game->board->texture, game->board->image, 0, 0);
    }
}

void event_handler(game_t *game)
{
    if (game->event.type == sfEvtClosed ||
    (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEscape))
        sfRenderWindow_close(game->window);
}

void update_main_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        event_handler(game);
    draw_on_board(game, NULL, sfBlack, 5);
}

void main_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(47, 79, 79));
    sfRenderWindow_drawSprite(game->window, game->board->sprite, NULL);
    sfRenderWindow_display(game->window);
}

void scene_handler(game_t *game)
{
    switch (game->scene) {
        case MAIN:
            main_scene(game);
            break;
        case EXIT:
            sfRenderWindow_close(game->window);
            break;
    }
}

void main_loop(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        update_main_scene(game);
        scene_handler(game);
    }
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
