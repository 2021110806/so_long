/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:31:00 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/11 21:53:50 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_allowed_character(char inp)
{
	if (inp == '0' || inp == '1' || inp == 'C' || inp == 'E' || inp == 'P')
		return (1);
	return (0);
}

void	dfs(t_map *map, int x, int y, int collectable)
{
	if (map -> visited[y][x] == 1)
		return ;
	map -> visited[y][x] = 1;
	if (map -> map_file[y][x] == 'E' && collectable == 0)
		*(map -> is_valid) = 1;
	else
	{
		if (x + 1 < map -> x_size / 64 && map -> map_file[y][x + 1] != '1')
			dfs(map, x + 1, y, \
			collectable - (map -> map_file[y][x + 1] == 'C'));
		if (y + 1 < map -> y_size / 64 && map -> map_file[y + 1][x] != '1')
			dfs(map, x, y + 1, \
			collectable - (map -> map_file[y + 1][x] == 'C'));
		if (x - 1 > -1 && map -> map_file[y][x - 1] != '1')
			dfs(map, x - 1, y, \
			collectable - (map -> map_file[y][x - 1] == 'C'));
		if (y - 1 > -1 && map -> map_file[y - 1][x] != '1')
			dfs(map, x, y - 1, \
			collectable - (map -> map_file[y - 1][x] == 'C'));
	}
}

int	**make_array_of_map_size(t_map *map)
{
	int	i;
	int	j;
	int	**visited;

	i = 0;
	visited = malloc (sizeof (int *) * map -> y_size / 64);
	while (i < map -> y_size / 64)
	{
		visited[i] = malloc (sizeof (int) * map -> x_size / 64);
		j = 0;
		while (j < map -> x_size / 64)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

int	check_if_y_is_bordered(t_map *map)
{
	int	i;

	i = 0;
	while (i < map -> y_size / 64)
	{
		if (map -> map_file[i][0] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map -> y_size / 64)
	{
		if (map -> map_file[i][map -> x_size / 64 - 2] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_if_x_is_bordered(t_map *map)
{
	int	j;

	j = 0;
	while (map -> map_file[0][j] && !(map -> map_file[0][j] == '\n'))
	{
		if (map -> map_file[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map -> map_file[map -> y_size / 64 - 1][j] \
	&& !(map -> map_file[map -> y_size / 64 - 1][j] == '\n'))
	{
		if (map -> map_file[map -> y_size / 64 - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}
