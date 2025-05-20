/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:42:52 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/05/20 09:24:44 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "GAME");
	if (!data->win)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return ;
	}
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &data->bpp, &data->line_length,
			&data->endian);
	data->field.grid = ft_get_map();
	mlx_hook(data->win, 17, 0, close_window, &data);
	mlx_hook(data->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx, render, data);
}

void	game(t_data *data)
{
	init_window(data);
	ft_find_player_position(data);
	mlx_loop(data->mlx);
}

int	render(t_data *data)
{
	clear_image(data);
	move_player(data);
	ft_draw_map(data);
	draw_player(data->player.x, data->player.y, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}
