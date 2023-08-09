/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:30:22 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/09 13:31:57 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	has_only_allowed_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> y_size / 64)
	{
		j = 0;
		while (j < map -> x_size / 64 - 1)
		{
			if (!is_allowed_character(map -> map_file[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_rectangular(t_map *map)
{
	int	i;
	int	j;
	int	is_first ;
	int	size;

	i = 0;
	j = 0;
	is_first = 1;
	while (map -> map_file[i][j] && map -> map_file[i][j] != '\n')
		j++;
	size = j;
	while (i < map -> y_size / 64)
	{
		j = 0;
		if (!is_first)
		{
			while (map -> map_file[i][j] && map -> map_file[i][j] != '\n')
				j++;
			if (j != size)
				return (0);
		}
		i++;
	}
	return (1);
}

int	is_bordered(t_map *map)
{
	if (!check_if_y_is_bordered(map))
		return (0);
	if (!check_if_x_is_bordered(map))
		return (0);
	return (1);
}

int	has_only_one_player_and_end_point(t_map *map)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	map -> end_point_num = 0;
	map -> player_num = 0;
	map -> collectable_num = 0;
	while (++i < map -> y_size / 64)
	{
		j = 0;
		while (j < map -> x_size / 64)
		{
			if (map -> map_file[i][j] == 'E')
				map -> end_point_num++;
			if (map -> map_file[i][j] == 'P')
				map -> player_num++;
			if (map -> map_file[i][j++] == 'C')
				map -> collectable_num++;
		}
	}
	if (map->player_num == 1 && map->end_point_num == 1 \
	&& map->collectable_num > 0)
		return (1);
	return (0);
}

int	has_valid_path(t_map *map)
{
	int	**visited;
	int	is_valid_num;
	int	i;
	int	j;

	i = 0;
	map -> is_valid = &is_valid_num;
	*(map -> is_valid) = 0;
	visited = make_array_of_map_size(map);
	while (i < map -> y_size / 64)
	{
		j = 0;
		while (j < map -> x_size / 64)
		{
			if (map -> map_file[i][j] == 'P')
			{
				dfs(map, j, i, visited);
				break ;
			}
			j++;
		}
		i++;
	}
	free_int_arr(visited, map -> y_size / 64);
	return (*(map -> is_valid));
}
