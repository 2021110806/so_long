
#include "so_long.h"
#include <stdio.h>

int key_hook(int key_code, t_map *map)
{
	if (key_code == 1) //s
	{
		if (map -> map_file[map -> y_user + 1][map -> x_user] == '1')
			return 1;
		if (map -> map_file[map -> y_user + 1][map -> x_user] == '0')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user + 1][map -> x_user] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken,  map -> x_user * 64, (map -> y_user + 1)* 64);
			map -> y_user ++;
			return 1;
		}
		if (map -> map_file[map -> y_user + 1][map -> x_user] == 'E')
		{
			mlx_destroy_window(map -> mlx_ptr, map -> win_ptr);
			exit(0);
		}
		if (map -> map_file[map -> y_user + 1][map -> x_user] == 'C')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user + 1][map -> x_user] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, (map -> y_user + 1)* 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken,  map -> x_user * 64, (map -> y_user + 1)* 64);
			map -> y_user ++;
			return 1;
		}
	}
	else if (key_code == 0) //a
	{
		if (map -> map_file[map -> y_user][map -> x_user - 1] == '1')
			return 1;
		if (map -> map_file[map -> y_user][map -> x_user - 1] == '0')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user][map -> x_user - 1] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken,  (map -> x_user - 1) * 64, map -> y_user * 64);
			map -> x_user --;
			return 1;
		}
		if (map -> map_file[map -> y_user][map -> x_user - 1] == 'E')
		{
			mlx_destroy_window(map -> mlx_ptr, map -> win_ptr);
			exit(0);
		}
		if (map -> map_file[map -> y_user][map -> x_user - 1] == 'C')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user][map -> x_user - 1] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  (map -> x_user - 1) * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken,   (map -> x_user - 1) * 64, map -> y_user * 64);
			map -> x_user --;
			return 1;
		}
	}
	else if (key_code == 13) //w
	{
		if (map -> map_file[map -> y_user - 1][map -> x_user] == '1')
			return 1;
		if (map -> map_file[map -> y_user - 1][map -> x_user] == '0')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user - 1][map -> x_user] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken,  map -> x_user * 64, (map -> y_user - 1)* 64);
			map -> y_user --;
			return 1;
		}
		if (map -> map_file[map -> y_user - 1][map -> x_user] == 'E')
		{
			mlx_destroy_window(map -> mlx_ptr, map -> win_ptr);
			exit(0);
		}
		if (map -> map_file[map -> y_user - 1][map -> x_user] == 'C')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user - 1][map -> x_user] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, (map -> y_user - 1)* 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken,  map -> x_user * 64, (map -> y_user - 1)* 64);
			map -> y_user --;
			return 1;
		}
	}
	else if (key_code ==2) //d
	{
		if (map -> map_file[map -> y_user ][map -> x_user + 1] == '1')
			return 1;
		if (map -> map_file[map -> y_user][map -> x_user + 1] == '0')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user][map -> x_user + 1] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken,  (map -> x_user + 1) * 64, map -> y_user * 64);
			map -> x_user ++;
			return 1;
		}
		if (map -> map_file[map -> y_user][map -> x_user + 1] == 'E')
		{
			mlx_destroy_window(map -> mlx_ptr, map -> win_ptr);
			exit(0);
		}
		if (map -> map_file[map -> y_user][map -> x_user + 1] == 'C')
		{
			map -> map_file[map -> y_user][map -> x_user] = '0';
			map -> map_file[map -> y_user][map -> x_user + 1] = 'P';
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  map -> x_user * 64, map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> grass,  (map -> x_user + 1) * 64,  map -> y_user * 64);
			mlx_put_image_to_window(map -> mlx_ptr, map -> win_ptr, map -> chicken, (map -> x_user + 1) * 64,  map -> y_user * 64);
			map -> x_user ++;
			return 1;
		}
	}
	else
		return 1;
	return (1);
}

int main(int argc, char **argv)
{
	int *image_width;
	int	*image_height;
	int sixty_four = 64;
	t_map	*map = malloc (sizeof(t_map));
	image_width = &sixty_four;
	image_height = &sixty_four;
	argc = 1;
	map -> mlx_ptr = mlx_init();
	map -> chicken = mlx_xpm_file_to_image(map -> mlx_ptr, "./images/chicken.xpm", image_width, image_height);
	map -> grass = mlx_xpm_file_to_image(map -> mlx_ptr, "./images/grass.xpm", image_width, image_height);
	map -> water =mlx_xpm_file_to_image(map -> mlx_ptr, "./images/water.xpm", image_width, image_height);
	map -> egg = mlx_xpm_file_to_image(map -> mlx_ptr, "./images/egg.xpm", image_width, image_height);
	map -> house = mlx_xpm_file_to_image(map -> mlx_ptr, "./images/house.xpm", image_width, image_height);
	read_map(argv, map);
	if (!is_bordered(map))
		printf("not bordered\n");
	if (!has_only_one_player_and_end_point(map))
		printf("player is not one\n");
	if (!is_rectangular(map))
		printf("not rectangular\n");
	if(!has_valid_path(map))
		printf("not valid path\n");
	draw_initial_map(map);
	mlx_key_hook(map -> win_ptr, key_hook, map);
	mlx_loop(map -> mlx_ptr);
	return (0);
}