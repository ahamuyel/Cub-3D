#ifndef RAYTRACING_H

# define RAYTRACING_H

# include "../../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 640
# define HEIGHT 640
# define BLOCK 64
# define SIZE 20

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define SPEED 20

# define KEY_Q 118
# define KEY_E 120

# define MAP_W 10
# define MAP_H 10

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		line_length;
	int		bbp;
	int		endian;

	int		x;
	int		y;
	float	angle;
	float	dir_x;
	float	dir_y;
	char	map[MAP_H][MAP_W + 1];
}			t_data;

// Player

void		move_player(t_data data);

#endif