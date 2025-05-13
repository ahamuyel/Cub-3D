/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:42:52 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/05/13 15:43:07 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_window(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return ;
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "CUB3D");
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 2, 1L >> 0, key_press, data);
	mlx_loop(data->mlx);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
		close_window(data);
	return (0);
}

int	close_window(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}
