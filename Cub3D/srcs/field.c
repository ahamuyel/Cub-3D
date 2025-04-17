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
char	*map[] = {
	"111111111111111111111111111111",
	"100000000000000000000000000001",
	"100000000011111111111100000001",
	"100000000010000000000100000001",
	"100000000010000000000100000001",
	"100000000011111000000100000001",
	"100000000000001000000100000001",
	"100001111100001000000100000001",
	"100001000100001111110100000001",
	"100001000100000000010100000001",
	"100001000111111111010100000001",
	"100001000000000001010100000001",
	"100001011111111101010100000001",
	"100001000000000000010100000001",
	"100001000111111111110100000001",
	"100001000100000000000100000001",
	"100001000100000000000100000001",
	"100001000111110000000100000001",
	"100001000000010000000100000001",
	"100001111100011111110100000001",
	"100000010000000001000100000001",
	"100000010000000001000100000001",
	"100000010000000001000100000001",
	"100000011111111111000100000001",
	"100000000000000000000000000001",
	"100000000000000000000000000001",
	"100000000000000000000000000001",
	"111111111111111111111111111111",
	NULL
};


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

void	render_3d_column(int x, double distance, t_data *data)
{
	double	wall_height;
	int		start;
	int		end;
	int		y;

	// Corrige "efeito olho de peixe"
	double corrected_distance = distance * cos(data->player.angle - data->ray_angle);

	wall_height = (SIZE * HEIGHT) / corrected_distance;
	start = (HEIGHT / 2) - (wall_height / 2);
	end = (HEIGHT / 2) + (wall_height / 2);

	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT;

	y = start;
	while (y < end)
	{
		my_put_pixel(x, y, 0xAAAAAA, data); // cor cinza da parede
		y++;
	}
}
