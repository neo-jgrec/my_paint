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


    #define UNUSED __attribute__((unused))


    typedef enum {
        IDLE,
        HOVER,
        CLICKED
    } button_state_t;

    typedef enum {
        MAIN,
        EXIT
    } scene_t;


    typedef struct button_s {
        char *name;
        sfVector2f pos;
        sfVector2f size;
        sfRectangleShape *shape;
        sfTexture *texture;
        button_state_t state;
        bool (*callback)(void *self, void *opt);
    } button_t;

    typedef struct button_list_s {
        button_t *button;
        TAILQ_ENTRY(button_list_s) next;
    } button_list_t;

    typedef enum wich_panel {
        FILE_PANEL,
        EDIT_PANEL,
        HELP
    } wich_panel_t;

    typedef struct board_s {
        sfImage *image;
        sfTexture *texture;
        sfSprite *sprite;
        sfVector2f pos;
        sfVector2f size;
        sfVector2f scale;
        sfVector2f mouse_pos;
    } board_t;

    typedef struct game_s {
        scene_t scene;
        sfRenderWindow *window;
        sfEvent event;
        sfClock *clock;
        button_list_t *buttons;
        board_t *board;
    } game_t;

    void init_game(game_t *game, char *filepath);

#endif /* !MY_H_ */
