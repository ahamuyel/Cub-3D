/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:15:14 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/04/11 10:39:24 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 1200
# define HEIGHT 800
# define BLOCK 64

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define LEFT 65361
# define RIGHT 65363

# define KEY_ESC 65307

# define PI 3.14159265358979323846

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;

	int			size;
	int			speed;
	int			color;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	bool		left_rotate;
	bool		right_rotate;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;

	char		**map;
	int			map_width;
	int			map_height;

	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player	player;
}				t_data;

// Drawing functions
void			put_pixel(int x, int y, int color, t_data *data);
void			clear_screen(t_data *data);
void			draw_square(int x, int y, int size, int color, t_data *data);

// Game functions
void			init_game(t_data *data);
// void			move_player(t_player *player);
int				game_loop(t_data *data);
int				close_window(t_data *data);

// Player functions
void			init_player(t_player *player);
int				key_press(int keycode, t_player *player, t_data *data);
int				key_release(int key_code, t_player *player);
void			move_player(t_player *player);

// Map functions

char			**get_map(void);
void			draw_map(t_data *data);

#endif