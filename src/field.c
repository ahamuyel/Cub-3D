/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:46:39 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/05/20 09:42:19 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*map[] = {"11111111111111111111", "10000000010E00000001",
		"10001000000001010001", "10111011101111011101", "10000010001000000001",
		"10111110111011111001", "10000000010000000001", "10111110111011111001",
		"10111110111011111001", "10111110111011111001", "10000000010000000001",
		"10000000010000000001", "10001000000001010001", "10000000010000000001",
		"10111111111111111001", "10000000000000000001", "11111111111111111111",
		NULL};

void	ft_pixel_put(int x, int y, int color, t_data *data)
{
	char	*pixel;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	pixel = data->addr + (y * data->line_length) + (x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_player(int x, int y, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->player.size)
	{
		i = 0;
		while (i < data->player.size)
			ft_pixel_put(x + (i++), y + j, data->player.color, data);
		j++;
	}
}

void	ft_draw_block(int x, int y, int color, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < BLOCK)
	{
		j = 0;
		while (j < BLOCK)
			ft_pixel_put(x + (j++), y + i, color, data);
		i++;
	}
}

char	**ft_get_map(void)
{
	return (map);
}

void	ft_draw_map(t_data *data)
{
	int	x;
	int	y;
	int	color;

	color = 0x00000;
	data->field.grid = ft_get_map();
	y = 0;
	while (data->field.grid && data->field.grid[y])
	{
		x = 0;
		while (data->field.grid[y][x])
		{
			if (data->field.grid[y][x] == '1')
				color = 0xffffff;
			else if (data->field.grid[y][x] == '0')
				color = 0x000000;
			ft_draw_block((x++) * BLOCK, y * BLOCK, color, data);
		}
		y++;
	}
}

int	is_wall(int x, int y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / BLOCK);
	map_y = (int)(y / BLOCK);
	if (x < -1 || x >= WIDTH + data->player.size || y < -1 || y >= HEIGHT
		+ data->player.size)
		return (1);
	if (data->field.grid[map_y] && data->field.grid[map_y][map_x])
	{
		if (data->field.grid[map_y][map_x] == '1')
			return (1);
	}
	return (0);
}

void	clear_image(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
}

void	clear_screen(t_data *data)
{
	int x;
	int y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			ft_pixel_put(x++, y, 0x000000, data);
		y++;
	}
}