/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:30:53 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/04/11 13:29:33 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pixel(int x, int y, int color, t_data *data)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * data->line_length + x * (data->bits_per_pixel / 8);
	*(unsigned int *)(&data->addr[index]) = color;
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
			put_pixel(x++, y, 0x000000, data);
		y++;
	}
}

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	data->map = get_map();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	clear_screen(data);
}

bool touch(float px, float py, t_data *data)
{
	int x = px / BLOCK;
	int y = py / BLOCK;
	if (data->map[y][x] == '1')
		return (true);
	return (false);
}

void draw_line(t_player *player, t_data *data, float start_x, int i)
{
	(void)i;
	float cos_angle = cos(start_x);
	float sin_angle = sin(start_x);
	float ray_x = player->x;
	float ray_y = player->y;
	while (!(touch(ray_x, ray_y, data)))
	{
		put_pixel(ray_x, ray_y, 0xfffff0, data);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
}

int	game_loop(t_data *data)
{
	t_player *player = &data->player;
	move_player(player);
	clear_screen(data);
	move_player(&data->player);
	draw_square(data->player.x, data->player.y, data->player.size,
		data->player.color, data);
	draw_map(data);
	
	// draw one line
	// while (!touch(ray_x, ray_y, data))
	// {
	// 	put_pixel(ray_x, ray_y, 0xff00ff, data);
	// 	ray_x += cos_angle;
	// 	ray_y += sin_angle;
		
	// }

	float fraction = PI / 3 / WIDTH;
	float start_x = player->x - PI / 6;
	int i = 0;
	while (i < WIDTH)
	{
		draw_line(player, data, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
