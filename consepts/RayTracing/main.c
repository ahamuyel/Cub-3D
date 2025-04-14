#include "rayTracing.h"

void	my_put_mlx(int x, int y, int color, t_data *data)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * data->line_length + x * (data->bbp / 8);
	*(unsigned int *)(&data->addr[index]) = color;
}

void	clear_screan(t_data *data)
{
	int x, y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			my_put_mlx(x++, y, 0x0ffff0, data);
		y++;
	}
}

void	draw_player(t_data *data)
{
	int	j;
	int	i;

	j = 0;
	while (j < SIZE)
	{
		i = 0;
		while (i < SIZE)
			my_put_mlx(data->x + i++, data->y + j, 0xff00f0, data);
		j++;
	}
}

int	handle_key(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->y -= SPEED;
	else if (keycode == KEY_S)
		data->y += SPEED;
	else if (keycode == KEY_A)
		data->x -= SPEED;
	else if (keycode == KEY_D)
		data->x += SPEED;
	draw_player(data);
	return (0);
}

int	render_frame(t_data *data)
{
	clear_screan(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "RayTracing");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length,
			&data->endian);
	data->x = WIDTH / 2 - SIZE / 2;
	data->y = HEIGHT / 2 - SIZE / 2;
}

int	main(void)
{
	t_data	data;

	init_game(&data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
