/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:40:48 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/07 23:39:07 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

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

int key_hook(int key_code, t_map *map)
{
	if (key_code == 1 && \
	map -> map_file[map -> y_user + 1][map -> x_user] != '1') //s
	{
		go_up_or_down(map, map -> x_user * 64, map -> y_user * 64, (map -> y_user + 1) * 64);
		map -> y_user++;
		return 1;
	}
	if (key_code == 0 \
	&& map -> map_file[map -> y_user][map -> x_user - 1] != '1') //a
	{
		go_left_or_right(map, map -> x_user * 64, map -> y_user * 64, (map -> x_user - 1) * 64);
		map -> x_user--;
		return 1;
	}
	if (key_code == 13 \
	&& map -> map_file[map -> y_user - 1][map -> x_user] != '1')
	{	
		go_up_or_down(map, map -> x_user * 64, map -> y_user * 64, (map -> y_user - 1) * 64);
		map -> y_user--;
		return 1;
	}
	if (key_code == 2 \
	&& map -> map_file[map -> y_user][map -> x_user + 1] != '1')
	{	
		go_left_or_right(map, map -> x_user * 64, map -> y_user * 64, (map -> x_user + 1) * 64);
		map -> x_user++;
		return 1;
	}
	return 1;
}

int main(int argc, char **argv)
{
	t_map	*map;
	int		size;

	argc = 1;
	size = 64;
	map = malloc(sizeof (t_map));
	map -> mlx_ptr = mlx_init();
	map -> chicken = mlx_xpm_file_to_image(map -> mlx_ptr, \
	"./images/chicken.xpm", &size, &size);
	map -> grass = mlx_xpm_file_to_image(map -> mlx_ptr, \
	"./images/grass.xpm", &size, &size);
	map -> water = mlx_xpm_file_to_image(map -> mlx_ptr, \
	"./images/water.xpm", &size, &size);
	map -> egg = mlx_xpm_file_to_image(map -> mlx_ptr, \
	"./images/egg.xpm", &size, &size);
	map -> house = mlx_xpm_file_to_image(map -> mlx_ptr, \
	"./images/house.xpm", &size, &size);
	read_map(argv, map);
	if (!is_bordered(map) || !has_only_one_player_and_end_point(map) || \
		!is_rectangular(map) || !has_valid_path(map))
	{
		write(2, "ERROR\n", 6);
		return (1);
	}
	draw_initial_map(map);
	mlx_key_hook(map -> win_ptr, key_hook, map);
	mlx_loop(map -> mlx_ptr);
	return (0);
}
