CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = ./libft/libft.a
LIBFT_DIR = libft
GNL = ./get_next_line/get_next_line.a
GNL_DIR = get_next_line
SRCS = main.c map_manager.c moving_manager.c
OBJS = $(SRCS:.c=.o)

.PHONY : clean fclean re all

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) fclean
	make -C $(GNL_DIR) fclean
	rm -f $(OBJS)

fclean:
	$(MAKE) clean
	rm -f $(NAME)
re:
	$(MAKE) fclean
	$(MAKE) all

$(NAME): $(OBJS) $(LIBFT) $(GNL) $(MLX)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) all

$(GNL):
	make -C $(GNL_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@