#ifndef RAYTRACING_H

# define RAYTRACING_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1200
# define HEIGHT 800
# define BLOCK 64
# define SIZE 20

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define KEY_ESC 65307

# define KEY_Q 118
# define KEY_E 120

# define SPEED 20

# define PI 3.14159265358979323846

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

// game
void		init_game(t_data *data);
int			close_window(t_data *data);
int			key_press(int keycode, t_data *data);

#endif