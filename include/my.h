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
    #include <dirent.h>

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
    #define VECT2F_DIV(a, b) (sfVector2f) {\
    a.x / b, a.y / b\
    }
    #define VECT2F_MULT(a, b) (sfVector2f) {\
    a.x * b, a.y * b\
    }

    #define IMAGE game->board->image
    #define BRUSH_SIZE game->board->size_brush
    #define BRUSH_COLOR game->board->color

    #define VERSION "My_Paint 1.0.0"

    typedef enum {
        IDLE,
        HOVER,
        CLICKED,
    } button_state_t;

    typedef enum {
        MAIN,
        HELP_SCENE,
        INPUT_SCENE,
        COLOR_SCENE,
        EXIT
    } scene_t;

    typedef enum {
        NONE,
        FILE_PANEL,
        EDIT_PANEL,
        HELP_PANEL
    } wich_panel_t;

    typedef enum {
        CIRCLE,
        RECTANGLE,
        CONVEX_SHAPE
    } brush_type_t;

    typedef enum {
        NO_ACTION,
        SAVE,
        LOAD
    } file_action_t;

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
        button_state_t state;
        button_textures_t textures;
        void (*action)(void *);
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

    typedef struct about_s {
        bool is_about;
        sfText *text;
    } about_t;

    typedef struct input_box_s {
        char *title;
        sfText *text;
        sfVector2f pos;
        sfVector2f size;
        file_action_t action;
        char *str;
    } input_box_t;

    typedef struct game_s {
        scene_t scene;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        TAILQ_HEAD(buttons, button_s) buttons;
        board_t *board;
        sfView *view;
        sfFont *font;
        wich_panel_t panel;
        about_t *about;
        input_box_t *input_box;
        sfImage *color_picker_image;
        sfSprite *color_picker_sprite;
    } game_t;

    void init_game(game_t *game, char *filepath, int alpha);
    bool sfconvexshape_contains(sfConvexShape *shape, sfVector2f point);
    sfVector2f *convex_shape_get_points(sfConvexShape *shape);
    sfCircleShape *create_circle_shape(float radius, sfColor color);
    sfRectangleShape *create_rectangle_shape(sfVector2f size, sfColor color);
    bool is_hovering(sfVector2f pos, sfRenderWindow *window, sfVector2f size);
    void draw_on_board(game_t *game);
    void scene_handler(game_t *game);
    void main_scene(game_t *game);
    void update_main_scene(game_t *game);
    void draw_shape_on_sfimage(game_t *game);
    void draw_rectangle_on_sfimage(game_t *game);
    void draw_circle_on_sfimage(game_t *game);
    void main_loop(game_t *game);
    void add_navbar_button(game_t *game);
    void display_all_buttons(game_t *game);
    void button_action(game_t *game);

    void new_file(game_t *game);
    void help(game_t *game);
    void about(game_t *game);
    void button_exit(game_t *game);
    void save_file(game_t *game);
    void open_file(game_t *game);
    void eraser_button(game_t *game);
    void switch_brush(game_t *game);
    void color_picker(game_t *game);

    void help_scene(game_t *game);
    void update_help_scene(game_t *game);
    void version_text_position(game_t *game);

    void input_scene(game_t *game);
    void update_input_scene(game_t *game);
    void fixed_compo(game_t *game);
    char fetch_char(sfKeyCode key);
    void manage_str(game_t *game, char c);

    char fetch_char(sfKeyCode key);
    void manage_str(game_t *game, char c);

    void update_color_scene(game_t *game);
    void handle_resize(game_t *game);
    void color_scene(game_t *game);

#endif /* !MY_H_ */
