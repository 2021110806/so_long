#include "so_long.h"

int	has_only_allowed_characters(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> y_size)
	{
		j = 0;
		while (j < map -> x_size)
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
	int	end_point_num;
	int	player_num;
	int	i;
	int	j;

	end_point_num = 0;
	player_num = 0;
	i = 0;
	j = 0;
	while (i < map -> y_size / 64)
	{
		j = 0;
		while (j < map -> x_size / 64)
		{
			if (map -> map_file[i][j] == 'E')
				end_point_num++;
			if (map -> map_file[i][j] == 'P')
				player_num++;
			j++;
		}
		i++;
	}
	if (player_num == 1 && end_point_num == 1)
		return (1);
	return (0);
}

int	has_valid_path(t_map *map)
{
	int	is_valid;
	int	**visited;
	int	i;
	int	j;

	i = 0;
	is_valid = 0;
	i = 0;
	visited = make_array_of_map_size(map);
	while (i < map -> y_size / 64)
	{
		j = 0;
		while (j < map -> x_size / 64)
		{
			if (map -> map_file[i][j] == 'P')
			{
				dfs(map, j, i, &is_valid, visited);
				break ;
			}
			j++;
		}
		i++;
	}

	return (is_valid);
}
