#ifndef RAYTRACING_H

# define RAYTRACING_H

# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 900
# define HEIGHT 900
# define BLOCK 64
# define SIZE 30

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100

# define KEY_R_UP 65362
# define KEY_R_DOWN 65364
# define KEY_R_LEFT 65361
# define KEY_R_RIGHT 65363

# define KEY_ESC 65307

# define KEY_Q 113
# define KEY_E 101

# define SPEED 20

# define PI 3.14159265358979323846

# define FOV (PI / 3)

# define MAP_W 10
# define MAP_H 10
# define KEY_TAB 65289

typedef struct s_player
{
	int			x;
	int			y;
	double		angle;
	int			dir_x;
	int			dir_y;
}				t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_2d;
	void		*img_3d;
	char		*addr;
	int			line_length;
	int			bbp;
	int			endian;

	int			x;
	int			y;
	float		angle;
	float		dir_x;
	float		dir_y;
	char		**map;
	int			ray_angle;
	int			debug_mode;
	t_player	player;
}				t_data;

// game
void			init_game(t_data *data);
int				close_window(t_data *data);
int				key_press(int keycode, t_data *data);
void			clear_screen(t_data *data);
void			clear_image(t_data *data);

// field
void			my_put_pixel(int x, int y, int color, t_data *data);
void			draw_square(int x, int y, int color, t_data *data);
char			**get_map(void);
void			draw_map(t_data *data);
double			cast_ray(double angle, t_data *data);
void			draw_rays(t_data *data);

// player
void			init_player(t_data *data);
void			render_3d_column(int x, double distance, t_data *data);
void			player(t_data *data);
int				key_press(int keycode, t_data *data);
void			draw_minimap_rays(t_data *data);
#endif