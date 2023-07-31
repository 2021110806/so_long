
#include "so_long.h"
#include <stdio.h>

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
	draw_initial_map(map);
	mlx_loop(map -> mlx_ptr);

	return (0);
}