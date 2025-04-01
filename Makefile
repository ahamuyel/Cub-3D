NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = src/main.c
OBJ = $(SRC:.c=.o)

# MiniLibX paths
MLX_DIR = includes/minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

INCLUDES = -Iincludes -I$(MLX_DIR)

all: $(MLX) $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@make -C $(MLX_DIR) clean

re: fclean all

.PHONY: all clean fclean re