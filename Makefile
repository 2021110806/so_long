CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
GNL = ./get_next_line/get_next_line.a
GNL_DIR = get_next_line
MLX_DIR = ./mlx_opengl
MLX = ./mlx_opengl/libmlx.a
MLX_CUSTOM_DIR = ./minilibx_opengl_custom-master
SRCS = main.c map_manager.c map_checker.c map_checker_utils.c moving_manager.c map_setting.c
OBJS = $(SRCS:.c=.o)

.PHONY : clean fclean re all

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	make -C $(MLX_DIR) clean
	make -C $(MLX_CUSTOM_DIR) clean
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) -lmlx -L$(MLX_DIR) -framework OpenGL -framework AppKit $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(GNL):
	make -C $(GNL_DIR) all

$(MLX):
	make -C $(MLX_DIR) all
	make -C $(MLX_CUSTOM_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@