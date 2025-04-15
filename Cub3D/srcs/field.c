#include "../includes/cub3D.h"

void	my_put_pixel(int x, int y, int color, t_data *data)
{
	int	index;

	if (x > WIDTH || y > HEIGHT || x < 0 || y < 0)
		return ;
	index = (y * data->line_length) + (x * (data->bbp / 8));
	*(unsigned int *)(&data->addr[index]) = color;
}

void	draw_square(int x, int y, int color, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
			my_put_pixel(x + (j++), y + i, color, data);
		i++;
	}
}

char	*map[] = {"11111111111111", "10000000000001", "10000000000001",
		"10000000000001", "10000000000001", "10000000000001", "10000000000001",
		"10000000000001", "10000000000001", "10000000000001", "10000000000001",
		"10000000000001", "10000000000001", "11111111111111", NULL};

char	**get_map(void)
{
	return (map);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_square(x * SIZE, y * SIZE, 0xffffff, data);
			else if (data->map[y][x] == '0')
				draw_square(x * SIZE, y * SIZE, 0x000000, data);
			x++;
		}
		y++;
	}
}
