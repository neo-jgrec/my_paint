/*
** EPITECH PROJECT, 2023
** paint
** File description:
** color_scene
*/

#include "my.h"

void event_color_handler(game_t *game)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed &&
    (game->event.key.code == sfKeyEscape
    || game->event.key.code == sfKeyEnter))
        game->scene = MAIN;
    if (game->event.type == sfEvtMouseButtonPressed) {
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
        sfVector2f mouse_posf = (sfVector2f){mouse_pos.x, mouse_pos.y};
        sfVector2f sprite_pos = sfSprite_getPosition(game->color_picker_sprite);
        sfVector2u sprite_size = sfImage_getSize(game->color_picker_image);
        if (mouse_posf.x >= sprite_pos.x && mouse_posf.x <= sprite_pos.x + \
        sprite_size.x && mouse_posf.y >= sprite_pos.y
        && mouse_posf.y <= sprite_pos.y + sprite_size.y) {
            sfColor color = sfImage_getPixel(game->color_picker_image, \
            mouse_pos.x - sprite_pos.x, mouse_pos.y - sprite_pos.y);
            game->board->color = (color.a == 0) ? game->board->color : color;
        }
    }
    handle_resize(game);
}

void update_color_scene(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event))
        event_color_handler(game);
}

void draw_text(game_t *game, sfImage *image, sfSprite *sprite)
{
    sfText *text = sfText_create();
    sfText_setFont(text, game->font);
    sfText_setString(text, "Current color");
    sfText_setCharacterSize(text, 20);
    sfText_setPosition(text, (sfVector2f){
        sfRenderWindow_getSize(game->window).x / 2 - sfText_getLocalBounds(\
        text).width / 2,
        sfRenderWindow_getSize(game->window).y / 2 - sfText_getLocalBounds(\
        text).height * 2 - sfImage_getSize(image).y / 2});
    sfText_setColor(text, game->board->color);
    sfRenderWindow_drawText(game->window, text, NULL);
    sfText_setString(text, "Press Enter to validate");
    sfText_setPosition(text, (sfVector2f){
        sfRenderWindow_getSize(game->window).x / 2 - sfText_getLocalBounds(\
        text).width / 2,
        sfSprite_getPosition(sprite).y + sfImage_getSize(\
        image).y + sfText_getLocalBounds(text).height});
    sfText_setColor(text, sfBlack);
sfRenderWindow_drawText(game->window, text, NULL);
    sfText_destroy(text);
}

void color_scene(game_t *game)
{
    sfRenderWindow_clear(game->window, sfColor_fromRGB(69, 69, 69));

    sfTexture *texture = sfTexture_createFromImage(game->color_picker_image,
    NULL);
    sfSprite_setTexture(game->color_picker_sprite, texture, sfTrue);
    sfSprite_setPosition(game->color_picker_sprite, (sfVector2f){
        sfRenderWindow_getSize(game->window).x / 2 - sfImage_getSize(\
        game->color_picker_image).x / 2,
        sfRenderWindow_getSize(game->window).y / 2 - sfImage_getSize(\
        game->color_picker_image).y / 2});
    sfRenderWindow_drawSprite(game->window, game->color_picker_sprite, NULL);

    draw_text(game, game->color_picker_image, game->color_picker_sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_display(game->window);
}
