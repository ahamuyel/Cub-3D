/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:46:39 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/05/14 16:32:13 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*map[] = {"11111111111111111111", "10000000000000000001",
		"10001000000001010001", "10111011101111011101", "10000010001000000001",
		"10111110111011111001", "10000000000000000001", "10111111111111111001",
		"10000000000000000001", "11111111111111111111", NULL};

void	ft_pixel_put(int x, int y, int color, t_data *data)
{
	char	*pixel;

	pixel = data->addr + (y * data->line_length) + (x * (data->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	ft_draw_block(int x, int y, int color, t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < BLOCK)
	{
		i = 0;
		while (i < BLOCK)
			ft_pixel_put(x + (i++), y + j, color, data);
		j++;
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
