/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:48:50 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/08 16:24:37 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <mlx.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"

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
	int		*is_valid;
	int		x_size;
	int		y_size;
	int		x_user;
	int		y_user;
	int		click_num;
	int		end_point_num;
	int		player_num;
	int		collectable_num;
}	t_map;

int		draw_initial_map(t_map *map);
void	read_map(char **argv, t_map *map);
int		is_allowed_character(char inp);
int		has_only_allowed_characters(t_map *map);
int		is_rectangular(t_map *map);
int		is_bordered(t_map *map);
int		has_only_one_player_and_end_point(t_map *map);
void	dfs(t_map *map, int x, int y, int **visited);
int		has_valid_path(t_map *map);
int		collected_all_items(t_map *map);
int		**make_array_of_map_size(t_map *map);
int		check_if_x_is_bordered(t_map *map);
int		check_if_y_is_bordered(t_map *map);
void	go_up_or_down(t_map *map, int x, int y, int new_y);
void	go_left_or_right(t_map *map, int x, int y, int new_x);
int		moving_player(int x, int y, int key_code, t_map *map);
#endif
