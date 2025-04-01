#include "../includes/game.h"

// Put pixel to image (fixed version)
void put_pixel(int x, int y, int color, t_game *game)
{
    if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
        return;
    int index = y * game->line_length + x * (game->bits_per_pixel / 8);
    *(unsigned int*)(&game->addr[index]) = color;
}

// Draw square outline (fixed version)
void draw_square(int x, int y, int size, int color, t_game *game)
{
    int i = 0;
    // Top line
    while (i < size)
        put_pixel(x + (i++), y, color, game);
    i = 0;
    // Left line
    while (i < size)
        put_pixel(x, y + (i++), color, game);
    i = 0;
    // Right line
    while (i < size)
        put_pixel(x + size, y + (i++), color, game);
    i = 0;
    // Bottom line
    while (i < size)
        put_pixel(x + (i++), y + size, color, game);
}

// Initialize game (fixed version)
void init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
                                 &game->line_length, &game->endian);
    // Clear screen
    for (int i = 0; i < WIDTH * HEIGHT * 4; i++)
        game->addr[i] = 0;
    mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int main(void)
{
    t_game game;
    
    init_game(&game);
    // Draw red square at center
    draw_square(WIDTH/2 - 50, HEIGHT/2 - 50, 100, 0xff0000, &game);
    mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);
    mlx_loop(game.mlx);
    return (0);
}