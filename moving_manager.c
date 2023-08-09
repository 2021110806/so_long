/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:30:42 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/09 14:33:58 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up_or_down(t_map *map, int new_y)
{
	if (map -> map_file[new_y / 64][map -> x_user] == '0')
	{
		map -> map_file[map -> y_user][map -> x_user] = '0';
		map -> map_file[new_y / 64][map -> x_user] = 'P';
		map -> click_num++;
	}
	else if (map -> map_file[new_y / 64][map -> x_user] == 'E'\
	&& collected_all_items(map))
	{
		mlx_destroy_window(map -> mlx_ptr, map -> win_ptr);
		exit(0);
	}
	else if (map -> map_file[new_y / 64][map -> x_user] == 'C')
	{
		map -> map_file[map -> y_user][map -> x_user] = '0';
		map -> map_file[new_y / 64][map -> x_user] = 'P';
		map -> click_num++;
	}
}

void	go_left_or_right(t_map *map, int new_x)
{
	if (map -> map_file[map -> y_user][new_x / 64] == '0')
	{
		map -> map_file[map -> y_user][map -> x_user] = '0';
		map -> map_file[map -> y_user][new_x / 64] = 'P';
		map -> click_num++;
	}
	else if (map -> map_file[map -> y_user][new_x / 64] == 'E'\
	&& collected_all_items(map))
	{
		mlx_destroy_window(map -> mlx_ptr, map -> win_ptr);
		exit(0);
	}
	else if (map -> map_file[map -> y_user][new_x / 64] == 'C')
	{
		map -> map_file[map -> y_user][map -> x_user] = '0';
		map -> map_file[map -> y_user][new_x / 64] = 'P';
		map -> click_num++;
	}
}

int	moving_player(int x, int y, int key_code, t_map *map)
{
	if (key_code == 1 && map -> map_file[y + 1][x] != '1')
		go_up_or_down(map, (y + 1) * 64);
	else if (key_code == 0 && map -> map_file[y][x] != '1')
		go_left_or_right(map, (x - 1) * 64);
	else if (key_code == 13 && map -> map_file[y - 1][x] != '1')
		go_up_or_down(map, (y - 1) * 64);
	else if (key_code == 2 && map -> map_file[y][x + 1] != '1')
		go_left_or_right(map, (x + 1) * 64);
	else if (key_code == 53)
		exit(0);
	draw_initial_map(map);
	ft_putnbr_fd(map->click_num, 1);
	write(1, "\n", 1);
	return (0);
}
