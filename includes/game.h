#ifndef GAME_H
# define GAME_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define WIDTH 1280
# define HEIGHT 720

typedef struct s_game {
    void    *mlx;
    void    *win;
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
} t_game;

void    init_game(t_game *game);

#endif