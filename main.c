/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:40:48 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/08 16:22:09 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key_code, t_map *map)
{
	moving_player(map -> x_user, map -> y_user, key_code, map);
	return (0);
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


// void a(void)
// {
// 	system("leaks so_long");
// }
int	main(int argc, char **argv)
{
	t_map					*map;
	int						i;
	// atexit(a);
	argc = 1;
	i = -2147384648;
	map = malloc(sizeof (t_map));
	set_map_image(map);
	read_map(argv, map);
	map -> click_num = 0;
	if (!is_bordered(map) || !has_only_one_player_and_end_point(map) || \
		!is_rectangular(map) || !has_valid_path(map))
	{
		write(2, "Error\n", 6);
		exit (1);
	}
	draw_initial_map(map);
	mlx_key_hook(map -> win_ptr, key_hook, map);
	mlx_loop(map -> mlx_ptr);
	exit (0);
}
