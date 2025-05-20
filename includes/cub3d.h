/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahamuyel <ahamuyel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:42:55 by ahamuyel          #+#    #+#             */
/*   Updated: 2025/05/20 09:23:49 by ahamuyel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 600
# define HEIGHT 600

# define W 119
# define S 115
# define A 97
# define D 100

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define ESC 65307

# define Q 113
# define E 101

# define BLOCK 30

# define PI 3.14159265358979323846

typedef struct s_player
{
	float		x;
	float		y;

	bool		key_up;
	bool		key_down;
	bool		key_left;
	bool		key_right;

	int			color;
	int			size;
	int			speed;
	int			angle;
}				t_player;

typedef struct s_field
{
	char		**grid;
	int			height;
	int			width;
	int			color;
	int			size;
}				t_field;

typedef struct s_data
{
	void		*mlx;
	void		*win;

	void		*img;

	int			bpp;
	int			line_length;
	char		*addr;
	int			endian;
	t_player	player;
	t_field		field;
}				t_data;

// Windows functions
void			init_window(t_data *data);
int				close_window(t_data *data);
int				key_press(int keycode, t_data *data);
int				key_release(int keycode, t_data *data);
int				is_wall(int x, int y, t_data *data);
void			clear_screen(t_data *data);

// Game functions
void			game(t_data *data);
int				render(t_data *data);

// Field functions
void			ft_draw_block(int x, int y, int color, t_data *data);
void			ft_draw_map(t_data *data);
char			**ft_get_map(void);
void			clear_image(t_data *data);

// Player functions
void			init_player(t_data *data);
void			ft_find_player_position(t_data *data);
void			move_player(t_data *data);
void			draw_player(int x, int y, t_data *data);
#endif