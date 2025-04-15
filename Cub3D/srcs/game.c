#include "../includes/cub3D.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "data");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length,
			&data->endian);
	data->map = get_map();
	draw_map(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	return (0);
}

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}