NAME = cub3D

CC = cc 
CFLAGS = -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/game.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

INCLUDES = -Iincludes -I$(MLX_DIR)

all: $(NAME)

$(MLX):
	@echo "Compiling MiniLibX"
	@cd $(MLX_DIR) && make

$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	@cd $(MLX_DIR) && make clean

re: fclean all