#ifndef GAME_H
# define GAME_H

# include "minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_game;

void    put_pixel(int x, int y, int color, t_game *game);
void    draw_square(int x, int y, int size, int color, t_game *game);
void    init_game(t_game *game);

#endif