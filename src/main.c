#include "../includes/game.h"

void init_game(t_game *game)
{
    game->mlx = mlx_init();
    game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
    game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    game->addr = mlx_get_data_addr(game->img, &game->bits_per_pixel,
                                &game->line_length, &game->endian);
}

int main(void)
{
    t_game game;
    
    init_game(&game);
    mlx_loop(game.mlx);
    return (0);
}