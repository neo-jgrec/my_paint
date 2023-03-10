/*
** EPITECH PROJECT, 2023
** paint
** File description:
** input_box
*/

#include "my.h"

void handle_resize(game_t *game)
{
    if (game->event.type == sfEvtResized) {
        sfVector2u size = {game->event.size.width, game->event.size.height};
        sfView *view = sfView_createFromRect((sfFloatRect){0, 0,
        (float)size.x, (float)size.y});
        sfRenderWindow_setView(game->window, view);
        sfView_destroy(view);
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
            (game->input_box->action == LOAD) ? (\
            game->board->image = sfImage_createFromFile(\
            game->input_box->str)) : (0);
            game->input_box->action = NO_ACTION;
            game->scene = MAIN;
        }
    }
    handle_resize(game);
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
