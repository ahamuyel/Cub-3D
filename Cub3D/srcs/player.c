#include "../includes/cub3D.h"

void	init_player(t_data *data)
{
	data->player.x = 20 * SIZE + SIZE / 2;
	data->player.y = 20 * SIZE + SIZE / 2;
}

void	player(t_data *data)
{
	int	size;
	int	i;
	int	j;

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
}

int	key_press(int keycode, t_data *data)
{
	int step;
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
	clear_image(data);
    draw_map(data);
    player(data);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}