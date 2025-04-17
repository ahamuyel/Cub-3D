#include "../includes/cub3D.h"

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "cub3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length,
			&data->endian);
	data->map = get_map();
	init_player(data);
	data->debug_mode = 0; // começar no modo 3D
	clear_image(data);
	if (data->debug_mode)
	{
		draw_map(data);
		player(data);
		draw_minimap_rays(data);
	}
	else
		draw_rays(data);

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	clear_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length,
			&data->endian);
}

void	clear_screen(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_put_pixel(x++, y, 0x000000, data);
		y++;
	}
}

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}