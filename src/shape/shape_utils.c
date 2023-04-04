/*
** @neo-jgrec, 2023
** paint
** File description:
** convex_shape_utils
*/

#include "my.h"

sfVector2f *convex_shape_get_points(sfConvexShape *shape)
{
    unsigned int pointCount = sfConvexShape_getPointCount(shape);
    sfVector2f *points = malloc(sizeof(sfVector2f) * pointCount);

    for (unsigned int i = 0; i < pointCount; ++i)
        points[i] = sfConvexShape_getPoint(shape, i);
    return points;
}

bool sfconvexshape_contains(sfConvexShape *shape, sfVector2f point)
{
    sfVector2f *points = convex_shape_get_points(shape);
    bool result = false;

    for (size_t i = 0, j = sfConvexShape_getPointCount(shape) - 1;
    i < sfConvexShape_getPointCount(shape); j = i++) {
        if (((points[i].y > point.y) != (points[j].y > point.y)) &&
        (point.x < (points[j].x - points[i].x) * (point.y - points[i].y) /
        (points[j].y - points[i].y) + points[i].x))
            result = !result;
    }
    return (result);
}
