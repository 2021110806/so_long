#include "so_long.h"

int	is_allowed_character(char inp)
{
	if (inp != '0' || inp != '1' || inp != 'C' || inp != 'E' || inp != 'P')
		return (1);
	return (0);
}

int	has_only_allowed_characters(t_map *map)
{
	int	i;
	int j;

	i = 0;
	while (i < map -> y_size)
	{
		j = 0;
		while (j <map -> x_size)
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
		if (is_first)
		{
			while (map -> map_file[i][j] && map -> map_file[i][j] != '\n')
				j++;
			size = j;
			is_first = 0;
		}
		i++;
	}
	return (1);
}

int	is_bordered(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map -> map_file[0][j] && !(map -> map_file[0][j] == '\n'))
	{
		if (map -> map_file[0][j] != '1')
			return (0);
		j++;
	}
	j = 0;
	while (map -> map_file[map -> y_size / 64 - 1][j] && !(map -> map_file[map -> y_size / 64 - 1][j] == '\n'))
	{
		if (map -> map_file[map -> y_size / 64 - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < map -> y_size / 64)
	{
		if (map -> map_file[i][0] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map -> y_size / 64)
	{
		if (map -> map_file[i][map -> x_size / 64 - 1] != '1')
			return (0);
		i++;
	}
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

void	dfs(t_map *map, int x, int y, int *is_valid , int **visited)
{
	if (visited[y][x] == 1)
		return ;
	visited[y][x] = 1;
	if (map -> map_file[y][x] == 'E')
	{
		*is_valid = 1;
	}
	else
	{
		if (x + 1 < map -> x_size / 64 && map -> map_file[y][x + 1] != '1')
			dfs(map, x + 1, y, is_valid, visited);
		if (y + 1 < map -> y_size / 64 && map -> map_file[y + 1][x] != '1')
			dfs(map, x, y + 1, is_valid, visited);
		if (x - 1 > -1 && map -> map_file[y][x - 1] != '1')
			dfs(map, x - 1, y, is_valid, visited);
		if (y - 1 > -1 && map -> map_file[y - 1][x] != '1')
			dfs(map, x, y - 1, is_valid, visited);
	}
}

int	has_valid_path(t_map *map)
{
	int	is_valid;
	int	**visited;
	int	i;
	int	j;

	i = 0;
	is_valid = 0;
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
	i = 0;
	while (i < map -> y_size / 64)
	{
		j = 0;
		while (j < map -> x_size / 64)
		{
			if (map -> map_file[i][j] == 'P')
			{
				dfs(map, j, i, &is_valid, visited);
				break;
			}
			j++;
		}
		i++;
	}

	return (is_valid);
}
