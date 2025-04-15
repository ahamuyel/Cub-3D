#include "../includes/cub3D.h"

int main()
{
    t_data data;

    init_game(&data);
    mlx_hook(data.win, 17, 0, close_window, &data);
    mlx_key_hook(data.win, key_press, &data);
    mlx_loop(data.mlx);
    return (0);
}