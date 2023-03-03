/*
** EPITECH PROJECT, 2022
** B-MUL-100-REN-1-1-myradar-jean-yanis.jeffroy
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Config.h>
    #include <SFML/Graphics/Transform.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <time.h>
    #include <fcntl.h>
    #include <math.h>
    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/queue.h>

    #include "mars.h"


    #define PI 3.14159265358979323846

    #define GET_MOUSE_POS(game) sfMouse_getPositionRenderWindow(game->window)

    #define VEC2I_CAST(vec) (sfVector2i){\
    vec.x, vec.y\
    }

    #define VEC2F_CAST(vec) (sfVector2f){\
    vec.x, vec.y\
    }
    #define VECT2F_MANHATTAN(a, b) (fabs(a.x - b.x) + fabs(a.y - b.y))
    #define VECT2F_NORMALIZE(dir) (sfVector2f){\
    dir.x / sqrt(dir.x * dir.x + dir.y * dir.y),\
    dir.y / sqrt(dir.x * dir.x + dir.y * dir.y)\
    }
    #define VECT2F_ADD(a, b) (sfVector2f) {\
    a.x + b.x, a.y + b.y\
    }
    #define VECT2F_SUB(a, b) (sfVector2f) {\
    a.x - b.x, a.y - b.y\
    }

    #define IMAGE game->board->image
    #define BRUSH_SIZE game->board->size_brush
    #define BRUSH_COLOR game->board->color


    typedef enum {
        IDLE,
        HOVER,
        CLICKED
    } button_state_t;

    typedef enum {
        MAIN,
        EXIT
    } scene_t;

    typedef enum {
        FILE_PANEL,
        EDIT_PANEL,
        HELP
    } wich_panel_t;

    typedef enum {
        CIRCLE,
        SPRITE,
        RECTANGLE,
        CONVEX_SHAPE
    } brush_type_t;

    typedef struct button_textures_s {
        sfTexture *hover;
        sfTexture *clicked;
        sfTexture *idle;
    } button_textures_t;

    typedef struct button_s {
        char *name;
        sfVector2f pos;
        sfVector2f size;
        sfRectangleShape *shape;
        sfTexture *texture;
        button_state_t *state;
        button_textures_t *textures;
        bool (*callback)(void *self, void *opt);
        TAILQ_ENTRY(button_s) next;
    } button_t;

    typedef struct board_s {
        sfImage *image;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f size;
        sfVector2f scale;
        sfVector2f mouse_pos;
        sfVector2f last_pos;
        brush_type_t brush_type;
        sfColor color;
        void *brush;
        float size_brush;
    } board_t;

    typedef struct game_s {
        scene_t scene;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        TAILQ_HEAD(, button_s) buttons;
        board_t *board;
    } game_t;

    void init_game(game_t *game, char *filepath);

    bool sfconvexshape_contains(sfConvexShape *shape, sfVector2f point);
    sfVector2f *convex_shape_get_points(sfConvexShape *shape);
    sfCircleShape *create_circle_shape(float radius, sfColor color);
    sfRectangleShape *create_rectangle_shape(sfVector2f size, sfColor color);
    sfSprite *create_sprite_texture(char *filepath);

    bool is_hovering(sfVector2f pos, sfRenderWindow *window, sfVector2f size);

    void draw_on_board(game_t *game);

    void scene_handler(game_t *game);

    void main_scene(game_t *game);
    void update_main_scene(game_t *game);

    void draw_circle_on_sfimage(game_t *game);

    void main_loop(game_t *game);
    void draw_shape_on_sfimage(game_t *game);

#endif /* !MY_H_ */
