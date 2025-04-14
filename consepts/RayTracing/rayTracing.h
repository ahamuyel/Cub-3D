#ifndef RAYTRACING_H

# define RAYTRACING_H

# include "../../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1200
# define HEIGHT 800
# define BLOCK 64
# define SIZE 64

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define SPEED 60

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
}			t_data;

// Player

void		move_player(t_data data);

#endif