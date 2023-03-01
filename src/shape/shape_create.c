/*
** EPITECH PROJECT, 2023
** paint
** File description:
** convex_shape_create
*/

#include "my.h"

sfCircleShape *create_circle_shape(float radius, sfColor color)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setFillColor(circle, color);
    sfCircleShape_setOutlineColor(circle, color);
    sfCircleShape_setOutlineThickness(circle, 1);
    return (circle);
}

sfRectangleShape *create_rectangle_shape(sfVector2f size, sfColor color)
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    sfRectangleShape_setSize(rectangle, size);
    sfRectangleShape_setFillColor(rectangle, color);
    sfRectangleShape_setOutlineColor(rectangle, color);
    sfRectangleShape_setOutlineThickness(rectangle, 1);
    return (rectangle);
}

sfSprite *create_sprite_texture(char *filepath)
{
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
