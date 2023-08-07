#ifndef SO_LONG_H
# define SO_LONG_H
#include <stdlib.h>
#include <mlx.h>
#include <stdio.h>
#include <unistd.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"
typedef struct s_map
{
	char	**map_file;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*water;
	void	*grass;
	void	*chicken;
	void	*egg;
	void	*house;
	int		x_size;
	int		y_size;
	int		x_user;
	int		y_user;
} t_map;

int draw_initial_map(t_map *map);
void	read_map(char **argv, t_map *map);
int	is_allowed_character(char inp);
int	has_only_allowed_characters(t_map *map);
int	is_rectangular(t_map *map);
int	is_bordered(t_map *map);
int	has_only_one_player_and_end_point(t_map *map);
void	dfs(t_map *map, int x, int y, int *is_valid, int **visited);
int	has_valid_path(t_map *map);
#endif