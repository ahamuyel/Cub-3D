#include "../includes/cub3D.h"

void init_game(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "data");
}

int key_press(int keycode, t_data *data)
{
    if (keycode == KEY_ESC)
        close_window(data);
    return (0);
}

int close_window(t_data *data)
{
    (void)data;
    exit (0);
    return (0);
}