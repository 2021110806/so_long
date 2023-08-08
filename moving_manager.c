/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:30:42 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/08 14:48:23 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	go_up_or_down(t_map *map, int x, int y, int new_y)
{
	if (map -> map_file[new_y / 64][map -> x_user] == '0')
	{
		map -> map_file[map -> y_user][map -> x_user] = '0';
		map -> map_file[new_y / 64][map -> x_user] = 'P';
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->chicken, x, \
		new_y);
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
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, \
		new_y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->chicken, x, \
		new_y);
	}
}

void	go_left_or_right(t_map *map, int x, int y, int new_x)
{
	if (map -> map_file[map -> y_user][new_x / 64] == '0')
	{
		map -> map_file[map -> y_user][map -> x_user] = '0';
		map -> map_file[map -> y_user][new_x / 64] = 'P';
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->chicken, \
		new_x, y);
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
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, \
		new_x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->chicken, \
		new_x, y);
	}
}

int	moving_player(int x, int y, int key_code, t_map *map)
{
	if (key_code == 1 && map -> map_file[y + 1][x] != '1')
	{
		go_up_or_down(map, x * 64, y * 64, (y + 1) * 64);
		map -> y_user++;
	}
	else if (key_code == 0 && map -> map_file[y][x] != '1')
	{
		go_left_or_right(map, x * 64, y * 64, (x - 1) * 64);
		map -> x_user--;
	}
	else if (key_code == 13 && map -> map_file[y - 1][x] != '1')
	{	
		go_up_or_down(map, x * 64, y * 64, (y - 1) * 64);
		map -> y_user--;
	}
	else if (key_code == 2 && map -> map_file[y][x + 1] != '1')
	{	
		go_left_or_right(map, x * 64, y * 64, (x + 1) * 64);
		map -> x_user++;
	}
	else if (key_code == 53)
		exit(0);
	return (0);
}
