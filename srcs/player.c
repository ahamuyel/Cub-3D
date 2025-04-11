/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:11:56 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/04/11 13:10:17 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_player *player)
{
	player->x = WIDTH / 2;
	player->y = HEIGHT / 2;
	
	player->size = 10;
	player->speed = 3;
	player->color = 0x00FFFF;
	
	player->key_up = false;
	player->key_down = false;
	player->key_left = false;
	player->key_right = false;
	
	player->right_rotate = false;
	player->left_rotate = false;
}

int	key_press(int keycode, t_player *player, t_data *data)
{
	if (keycode == KEY_ESC)
		close_window(data);
	else if (keycode == KEY_W)
		player->key_up = true;
	else if (keycode == KEY_S)
		player->key_down = true;
	else if (keycode == KEY_A)
		player->key_left = true;
	else if (keycode == KEY_D)
		player->key_right = true;
	else if (keycode == LEFT)
		player->left_rotate = true;
	else if (keycode == RIGHT)
		player->right_rotate = true;
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == KEY_W)
		player->key_up = false;
	else if (keycode == KEY_S)
		player->key_down = false;
	else if (keycode == KEY_A)
		player->key_left = false;
	else if (keycode == KEY_D)
		player->key_right = false;
	else if (keycode == LEFT)
		player->left_rotate = false;
	else if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}

void	move_player(t_player *player)
{
	float	angle_speed;
	float	cos_angle;
	float	sin_angle;
	// int speed = 4;

	angle_speed = 0.1;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;

	if (player->key_up)
	{
		player->x += cos_angle * player->speed;
		player->y += sin_angle * player->speed;
	}
	if (player->key_down)
	{
		player->x -= cos_angle * player->speed;
		player->y -= sin_angle * player->speed;
	}
	if (player->key_left)
	{
		player->x += cos_angle * player->speed;
		player->y -= sin_angle * player->speed;
	}
	if (player->key_right)
	{
		player->x -=cos_angle * player->speed;
		player->y +=sin_angle * player->speed;
	}

	if (player->x < 0)
		player->x = 0;
	if (player->x > WIDTH - player->size)
		player->x = WIDTH - player->size;
	if (player->y < 0)
		player->y = 0;
	if (player->y > HEIGHT - player->size)
		player->y = HEIGHT - player->size;
}

void draw_square(int x, int y, int size, int color, t_data *data)
{
    int i;
    
    // Linha superior (top)
    i = 0;
    while (i < size)
    {
        put_pixel(x + i, y, color, data);
        i++;
    }
    
    // Linha inferior (bottom)
    i = 0;
    while (i < size)
    {
        put_pixel(x + i, y + size - 1, color, data);
        i++;
    }
    
    // Linha esquerda (left)
    i = 0;
    while (i < size)
    {
        put_pixel(x, y + i, color, data);
        i++;
    }
    
    // Linha direita (right)
    i = 0;
    while (i < size)
    {
        put_pixel(x + size - 1, y + i, color, data);
        i++;
    }
}

// void	draw_square(int x, int y, int size, int color, t_data *data)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 			put_pixel(x + i, y + (j++), color, data);
// 		i++;
// 	}
// }
