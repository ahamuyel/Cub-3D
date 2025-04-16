#include "../includes/cub3D.h"

void	init_player(t_data *data)
{
	data->player.x = 20 * SIZE + SIZE / 2;
	data->player.y = 20 * SIZE + SIZE / 2;
	data->player.angle = 0;
}

void	draw_line(double x1, double y1, double x2, double y2, t_data *data)
{
	double	dx;
	double	dy;
	int		steps;
	double	i;
	double	t;
	int		x;
	int		y;

	dx = x2 - x1;
	dy = y2 - y1;
	steps = 100;
	i = 0;
	while (i < steps)
	{
		t = i / steps;
		x = x1 + dx * t;
		y = y1 + dy * t;
		my_put_pixel(x, y, 0xf0000f, data);
		i++;
	}
}

void	player(t_data *data)
{
	int		size;
	int		i;
	int		j;
	double	ray_length;
	double	ray_x;
	double	ray_y;

	size = 20;
	i = -size / 2;
	while (i < size / 2)
	{
		j = -size / 2;
		while (j < size / 2)
		{
			my_put_pixel(data->player.x + j, data->player.y + i, 0x0ffff0,
				data);
			j++;
		}
		i++;
	}
	// desenha o raio indicando a direção
	ray_length = 150;
	ray_x = data->player.x + cos(data->player.angle) * ray_length;
	ray_y = data->player.y + sin(data->player.angle) * ray_length;
	draw_line(data->player.x, data->player.y, ray_x, ray_y, data);
}

int	key_press(int keycode, t_data *data)
{
	int	step;

	step = 20;
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		data->player.y -= step;
	else if (keycode == KEY_S)
		data->player.y += step;
	else if (keycode == KEY_A)
		data->player.x -= step;
	else if (keycode == KEY_D)
		data->player.x += step;
	else if (keycode == KEY_Q)
		data->player.angle -= 0.1;
	else if (keycode == KEY_E)
		data->player.angle += 0.1;
	clear_image(data);
	draw_map(data);
	player(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
