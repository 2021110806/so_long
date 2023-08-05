#include "so_long.h"

int	is_allowed_character(char inp)
{
	if (inp != '0' || inp != '1' || inp != 'C' || inp != 'E' || inp != 'P')
		return (1);
	return (0);
}

int	is_rectangular(t_map *map)
{
	int	i;
	int	j;
	int	is_first ;
	int	size;

	i = 0;
	is_first = 1;
	while (map -> map_file[i])
	{
		j = 0;
		if (!is_first)
		{
			while (map -> map_file[i][j])
				j++;
			if (j != size)
				return (0);
		}
		if (is_first)
		{
			while (map -> map_file[i][j])
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
	while (map -> map_file[0][j])
	{
		if (map -> map_file[0][j] != 1)
			return (0);
		j++;
	}
	j = 0;
	while (map -> map_file[map -> y_size - 1][j])
	{
		if (map -> map_file[map -> y_size - 1][j] != 1)
			return (0);
		j++;
	}
	while (map -> map_file[i])
	{
		if (map -> map_file[i][0] != 1)
			return (0);
		i++;
	}
	i = 0;
	while (map -> map_file[i])
	{
		if (map -> map_file[i][map -> x_size] != 1)
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

	while (map -> map_file[i])
	{
		while (map -> map_file[i][j])
		{
			if (map -> map_file[i][j] == 'E')
				end_point_num++;
			if (map -> map_file[i][j] == 'P')
				player_num++;
			j++;
		}
		i++;
	}
}

int	has_valid_path(t_map *map)
{
	
}
