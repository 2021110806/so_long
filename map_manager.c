
#include "so_long.h"

void	set_x_and_y_size(t_map *map, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	map -> x_size = 0;
	map -> y_size = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd))
		map -> y_size++;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line[i])
	{
		i++;
		map -> x_size++;
	}
}

void	read_map(char **argv, t_map *map)
{
	int		fd;
	char	*line;
	int		i;

	set_x_and_y_size(map, argv);
	fd = open(argv[1], O_RDONLY);
	map -> map_file = malloc(sizeof(char *) * map -> y_size);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map -> map_file[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map -> x_size *= 64;
	map -> y_size *= 64;
	map -> win_ptr = mlx_new_window(map -> mlx_ptr, map -> x_size, \
	map -> y_size, "so_long");
	return ;
}


void	match_map_file_to_window(t_map *map, int x, int y)
{
	if (map -> map_file[y / 64][x / 64] == '1')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->water, x, y);
	else if (map -> map_file[y / 64][x / 64] == '0')
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
	else if (map -> map_file[y / 64][x / 64] == 'E')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->house, x, y);
	}
	else if (map -> map_file[y / 64][x / 64] == 'P')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->chicken, x, y);
		map -> x_user = x / 64;
		map -> y_user = y / 64;
	}
	else if (map -> map_file[y / 64][x / 64] == 'C')
	{
		mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->grass, x, y);
		mlx_put_image_to_window(map -> mlx_ptr, map->win_ptr, map->egg, x, y);
	}
}

int	draw_initial_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y * 64 < map -> y_size)
	{
		x = 0;
		while (x * 64 < map -> x_size)
		{
			match_map_file_to_window(map, x * 64, y * 64);
			x++;
		}
		y++;
	}
	return (1);
}

int	collected_all_items(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map -> y_size / 64)
	{
		j = 0;
		while (j < map -> x_size / 64)
		{
			if (map -> map_file[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
