#include "../includes/cub3D.h"

void	init_player(t_data *data)
{
	data->player.x = 12 * SIZE + SIZE / 2;
	data->player.y = 16 * SIZE + SIZE / 2;
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
	steps = 1000;
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

int	is_wall(double x, double y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / SIZE);
	map_y = (int)(y / SIZE);
	if (data->map[map_y] && data->map[map_y][map_x])
		return (data->map[map_y][map_x] == '1');
	return (1);
}

double	cast_ray(double angle, t_data *data)
{
	double ray_x = data->player.x;
	double ray_y = data->player.y;
	double step = 1;
	double distance = 0;

	while (!is_wall(ray_x, ray_y, data))
	{
		ray_x += cos(angle) * step;
		ray_y += sin(angle) * step;
		distance += step;
	}

	data->ray_angle = angle; // guardar o ângulo atual do raio
	return (distance);
}


void	draw_rays(t_data *data)
{
	int		num_rays = WIDTH;
	double	start_angle = data->player.angle - (FOV / 2);
	double	angle_step = FOV / num_rays;
	int		x = 0;

	while (x < num_rays)
	{
		double ray_angle = start_angle + x * angle_step;
		double distance = cast_ray(ray_angle, data);
		render_3d_column(x, distance, data);
		x++;
	}
}


// Digital ray marching

void	player(t_data *data)
{
	int	size;
	int	i;
	int	j;

	// double	ray_length;
	// double	ray_x;
	// double	ray_y;
	size = 20;
	i = -size / 4;
	while (i < size / 4)
	{
		j = -size / 4;
		while (j < size / 4)
		{
			my_put_pixel(data->player.x + j, data->player.y + i, 0x0ffff0,
				data);
			j++;
		}
		i++;
	}
	// desenha o raio indicando a direção
	// ray_length = 150;
	// ray_x = data->player.x + cos(data->player.angle) * ray_length;
	// ray_y = data->player.y + sin(data->player.angle) * ray_length;
	// draw_line(data->player.x, data->player.y, ray_x, ray_y, data);
	// draw_rays(data);
}

int	key_press(int keycode, t_data *data)
{
	int		step;
	double	angle;
	double	new_x;
	double	new_y;

	angle = data->player.angle;
	new_x = data->player.x;
	new_y = data->player.y;
	step = 20;
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W || keycode == KEY_R_UP)
	{
		new_x += cos(angle) * step;
		new_y += sin(angle) * step;
	}
	else if (keycode == KEY_S || keycode == KEY_R_DOWN)
	{
		new_y -= step * sin(angle);
		new_x -= step * cos(angle);
	}
	else if (keycode == KEY_A)
	{
		new_x -= step * cos(angle);
		new_y += step * sin(angle);
	}
	else if (keycode == KEY_D)
	{
		new_x += step * cos(angle);
		new_y -= step * sin(angle);
	}
	else if (keycode == KEY_Q || keycode == KEY_R_LEFT)
		data->player.angle -= 0.1;
	else if (keycode == KEY_E || keycode == KEY_R_RIGHT)
		data->player.angle += 0.1;
	if (!is_wall(new_x, new_y, data))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
	clear_image(data);
	// draw_map(data);
	// player(data);
	draw_rays(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
