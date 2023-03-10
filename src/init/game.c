/*
** EPITECH PROJECT, 2023
** paint
** File description:
** game
*/

#include "my.h"

static void fill_sfimage_alpha_with_white(sfImage *image)
{
    sfColor color;

    for (size_t i = 0; i < sfImage_getSize(image).x; i++) {
        for (size_t j = 0; j < sfImage_getSize(image).y; j++) {
            color = sfImage_getPixel(image, i, j);
            (color.a == 0) ? (sfImage_setPixel(image, i, j, sfWhite)) : (0);
        }
    }
}

static void init_image(game_t *game, char *filepath, int alpha)
{
    if (filepath != NULL) {
        IMAGE = sfImage_createFromFile(filepath);
        IMAGE = (IMAGE == NULL) ? (sfImage_createFromColor(
        game->board->size.x, game->board->size.y, sfWhite)) : (IMAGE);
        (alpha == 0) ? (fill_sfimage_alpha_with_white(IMAGE)) : (0);
    } else {
        (alpha == 0) ? (IMAGE = sfImage_createFromColor(game->board->size.x,
        game->board->size.y, sfWhite)) : (IMAGE = sfImage_createFromColor(
        game->board->size.x, game->board->size.y, sfTransparent));
    }
}

static void init_board(game_t *game, char *filepath, int alpha)
{
    game->board = malloc(sizeof(board_t));
    game->board->size = (sfVector2f){400, 300};
    game->board->pos = (sfVector2f){266, 150};
    game->board->scale = (sfVector2f){1, 1};
    game->board->color = sfBlack;
    game->board->size_brush = 10;
    game->board->brush = create_circle_shape(game->board->size_brush, sfBlack);
    game->board->brush_type = CIRCLE;
    init_image(game, filepath, alpha);
    game->board->texture = sfTexture_createFromImage(IMAGE, NULL);
    game->board->sprite = sfSprite_create();
    sfSprite_setTexture(game->board->sprite, game->board->texture, sfTrue);
    sfSprite_setPosition(game->board->sprite, game->board->pos);
    sfSprite_setScale(game->board->sprite, game->board->scale);
}

static void init_input_box(game_t *game)
{
    game->input_box = malloc(sizeof(input_box_t));
    game->input_box->pos = (sfVector2f){sfRenderWindow_getSize(game->window).x
    / 2 - 100, sfRenderWindow_getSize(game->window).y / 2 - 50};
    game->input_box->size = (sfVector2f){200, 100};
    game->input_box->text = sfText_create();
    sfText_setFont(game->input_box->text, game->font);
    sfText_setCharacterSize(game->input_box->text, 20);
    sfText_setPosition(game->input_box->text, (sfVector2f){\
    game->input_box->pos.x + 10, game->input_box->pos.y + 10});
    sfText_setColor(game->input_box->text, sfBlack);
    game->input_box->str = my_calloc(100, sizeof(char));
}

void init_game(game_t *game, char *filepath, int alpha)
{
    game->font = sfFont_createFromFile("assets/JetBrainsMono-Medium.ttf");
    game->scene = MAIN;
    game->window = sfRenderWindow_create((sfVideoMode){800, 600, 32},
    "my_paint", sfResize | sfClose, NULL);
    game->view = sfView_create();
    sfView_setSize(game->view, (sfVector2f){800, 600});
    sfView_setCenter(game->view, (sfVector2f){400, 300});
    sfRenderWindow_setView(game->window, game->view);
    game->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setVerticalSyncEnabled(game->window, sfTrue);
    sfRenderWindow_setKeyRepeatEnabled(game->window, sfFalse);
    init_board(game, filepath, alpha);
    TAILQ_INIT(&game->buttons);
    add_navbar_button(game);
    game->panel = NONE;
    init_input_box(game);
}
