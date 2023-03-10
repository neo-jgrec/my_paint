/*
** EPITECH PROJECT, 2023
** paint
** File description:
** input_box
*/

#include "my.h"

char fetch_char(sfKeyCode key)
{
    for (int i = 0; i < 26; i++)
        if (key == sfKeyA + i)
            return 'a' + i;
    if (key == sfKeySpace)
        return ' ';
    if (key == sfKeyBack)
        return '\b';
    if (key == sfKeyNum8)
        return '_';
    if (key == sfKeyPeriod)
        return '.';
    if (key == 48)
        return '.';
    return 0;
}

void manage_str(game_t *game, char c)
{
    if (c != 0) {
        if (c == '\b') {
            (game->input_box->str[0] != 0) ? (game->input_box->str[strlen(
            game->input_box->str) - 1] = 0) : (0);
        } else {
            (strlen(game->input_box->str) < 20) ? ({
                char *tmp = malloc(sizeof(char) * 2);
                tmp[0] = c;
                tmp[1] = 0;
                game->input_box->str = strcat(game->input_box->str, tmp);
                free(tmp);
            }) : (0);
        }
    }
}

void event_input_handler(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyEscape)
        game->scene = MAIN;
    if (game->event.type == sfEvtKeyPressed) {
        char c = fetch_char(game->event.key.code);
        manage_str(game, c);
        if (sfKeyboard_isKeyPressed(sfKeyReturn)) {
            (game->input_box->action == SAVE) ? (sfImage_saveToFile(
            game->board->image, game->input_box->str)) : (0);
            (game->input_box->action == LOAD) ? (sfImage_loadFromFile(
            game->board->image, game->input_box->str)) : (0);
            game->input_box->action = NO_ACTION;
            game->scene = MAIN;
        }
    }
    if (game->event.type == sfEvtResized) {
        sfVector2u size = {game->event.size.width, game->event.size.height};
        sfView *view = sfView_createFromRect((sfFloatRect){0, 0,
        (float)size.x, (float)size.y});
        sfRenderWindow_setView(game->window, view);
        sfView_destroy(view);
    }
}

void update_input_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        event_input_handler(game);
}

void input_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(69, 69, 69));
    fixed_compo(game);
    sfText_setString(game->input_box->text, game->input_box->str);
    sfText_setPosition(game->input_box->text, (sfVector2f) {
        sfRenderWindow_getSize(game->window).x / 2 - sfText_getGlobalBounds\
        (game->input_box->text).width / 2, 210});
    sfRenderWindow_drawText(game->window, game->input_box->text, NULL);

    sfText_setString(game->input_box->text, "Press enter to save");
    sfText_setPosition(game->input_box->text, (sfVector2f) {
        sfRenderWindow_getSize(game->window).x / 2 - sfText_getGlobalBounds\
        (game->input_box->text).width / 2, 300});
    sfRenderWindow_drawText(game->window, game->input_box->text, NULL);
    sfText_setString(game->input_box->text, "Press escape to go back");
    sfText_setPosition(game->input_box->text, (sfVector2f) {
        sfRenderWindow_getSize(game->window).x / 2 - sfText_getGlobalBounds\
        (game->input_box->text).width / 2, 350});
    sfRenderWindow_drawText(game->window, game->input_box->text, NULL);

    sfRenderWindow_display(game->window);
}
