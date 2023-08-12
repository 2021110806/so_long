/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjeon2 <qwer10897@naver.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 22:40:48 by minjeon2          #+#    #+#             */
/*   Updated: 2023/08/12 15:17:01 by minjeon2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	key_hook(int key_code, t_map *map)
{
	moving_player(map -> x_user, map -> y_user, key_code, map);
	return (0);
}

int	is_end_with_ber(char *inp)
{
	int	len;

	len = ft_strlen(inp);
	len--;
	if (inp[len] == 'r' && inp[len - 1] == 'e' \
	&& inp[len - 2] == 'b' && inp[len - 3] == '.')
		return (1);
	return (0);
}

int	is_map_size_too_big(t_map *map)
{
	int	win_x;
	int	win_y;

	mlx_get_screen_size(map -> mlx_ptr, &win_x, &win_y);
	if (map -> x_size > win_x || map -> y_size > win_y)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2 || !is_end_with_ber(argv[1]))
		error();
	map = malloc(sizeof (t_map));
	set_map_image(map);
	read_map(argv, map);
	map -> click_num = 0;
	if (!is_bordered(map) || !has_only_one_player_and_end_point(map) || \
		!is_rectangular(map) || !has_valid_path(map) || \
		!has_only_allowed_characters(map) || is_map_size_too_big(map))
		error();
	draw_initial_map(map);
	mlx_key_hook(map -> win_ptr, key_hook, map);
	mlx_loop(map -> mlx_ptr);
	exit (0);
}
