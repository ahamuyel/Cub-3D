/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:45:46 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/05/20 09:28:29 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_data *data)
{
	data->player.size = 10;
	data->player.speed = 2;
	data->player.color = 0xff0faa;
	data->player.key_up = false;
	data->player.key_down = false;
	data->player.key_left = false;
	data->player.key_right = false;
}

void	find_player_orientation(int x, int y, t_data *data)
{
	if (data->field.grid[y][x] == 'N')
		data->player.angle = (3 * PI) / 2;
	else if (data->field.grid[y][x] == 'S')
		data->player.angle = PI / 2;
	else if (data->field.grid[y][x] == 'W')
		data->player.angle = PI;
	else if (data->field.grid[y][x] == 'E')
		data->player.angle = 0;
}

void	ft_find_player_position(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (data->field.grid[y])
	{
		x = 0;
		while (data->field.grid[y][x])
		{
			if (data->field.grid[y][x] == 'N' || data->field.grid[y][x] == 'S'
				|| data->field.grid[y][x] == 'E'
				|| data->field.grid[y][x] == 'W')
			{
				find_player_orientation(x, y, data);
				init_player(data);
				data->player.x = x * BLOCK + (BLOCK / 2);
				data->player.y = y * BLOCK + (BLOCK / 2);
				// printf("Init player x: %f\n", data->player.x);
				return ;
			}
			x++;
		}
		y++;
	}
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	else if (keycode == UP || keycode == W)
		data->player.key_up = true;
	else if (keycode == DOWN || keycode == S)
		data->player.key_down = true;
	else if (keycode == A)
		data->player.key_left = true;
	else if (keycode == D)
		data->player.key_right = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == UP || keycode == W)
		data->player.key_up = false;
	else if (keycode == DOWN || keycode == S)
		data->player.key_down = false;
	else if (keycode == A)
		data->player.key_left = false;
	else if (keycode == D)
		data->player.key_right = false;
	return (0);
}

void	move_player(t_data *data)
{
	float	x;
	float	y;

	x = data->player.x;
	y = data->player.y;
	if (data->player.key_up)
		y -= data->player.speed;
	if (data->player.key_down)
		y += data->player.speed;
	if (data->player.key_left)
		x -= data->player.speed;
	if (data->player.key_right)
		x += data->player.speed;
	if (!is_wall(x, y, data))
	{
		data->player.y = y;
		data->player.x = x;
	}
}
