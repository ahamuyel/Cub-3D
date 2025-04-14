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
			my_put_mlx(x++, y, 0x0fffff, data);
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
			my_put_mlx(data->x + i++, data->y + j, 0xf00000, data);
		j++;
	}
}



void	draw_block(t_data *data, int x, int y, int color)
{
	int	j;
	int	i;

	j = 0;
	while (j < BLOCK)
	{
		i = 0;
		while (i < BLOCK)
			my_put_mlx(x * BLOCK + i++, y * BLOCK + j, color, data);
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

void	draw_map(t_data *data)
{
	int	color;

	int x, y = 0;
	while (y < MAP_H)
	{
		x = 0;
		while (x < MAP_W)
		{
			if (data->map[y][x] == '1')
				color = 0xffffff;
			else 
				color = 0x000000;
			draw_block(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	render_frame(t_data *data)
{
	clear_screan(data);
	draw_map(data);
	draw_player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	init_game(t_data *data)
{
	char	tmp_map[MAP_H][MAP_W] = {"1111111111", "1000000001", "1011001101",
			"1010000101", "1000110001", "1000110001", "1010000101",
			"1011001101", "1000000001", "1111111111"};

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "RayTracing");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bbp, &data->line_length,
			&data->endian);
	data->x = WIDTH / 2 - SIZE / 2;
	data->y = HEIGHT / 2 - SIZE / 2;
	int x, y = 0;
	while (y < MAP_H)
	{
		x = 0;
		while (x < MAP_W)
		{
			data->map[y][x] = tmp_map[y][x];
			x++;
		}
		data->map[y][x] = '\0';
		y++;
	}
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
