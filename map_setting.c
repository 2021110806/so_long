/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:34:36 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/08 17:34:38 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	line = get_next_line(fd);
	while (line)
	{
		i++;
		map -> y_size++;
		free(line);
		line = get_next_line(fd);
	}
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line[i])
	{
		i++;
		map -> x_size++;
	}
	free(line);
}

void	set_map_image(t_map *map)
{
	int	size;

	size = 64;
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
}

void	free_int_arr(int **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
