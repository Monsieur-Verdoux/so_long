/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:33 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/28 16:08:38 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_arguments(int argc, const char **argv, t_map *map)
{
	if (argc <= 1)
	{
		ft_printf("Error: no map file to read\n");
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf("Error: please only input one map file\n");
		exit(EXIT_FAILURE);
	}
	map->filename = argv[1];
}

int	main(int argc, const char **argv)
{
	mlx_t		*mlx;
	t_map		map;
	t_img		image;

	map.img = &image;
	check_arguments (argc, argv, &map);
	if (!validate_map(&map))
	{
		free_map(&map, map.grid);
		exit(EXIT_FAILURE);
	}
	map.wnd_w = 1366;
	map.wnd_h = 768;
	mlx = mlx_init(1366, 768, "so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	map.mlx = mlx;
	sizing(&map);
	handle_images(mlx, &map, &image);
	map.moves = 0;
	map.col_col = 0;
	map.n = 0;
	draw_map(mlx, &map, &image);
	mlx_key_hook(mlx, movement_hook, &map);
	mlx_resize_hook(mlx, resize_hook, &map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map(&map, map.grid);
	exit(EXIT_SUCCESS);
}
// image = mlx_new_image(mlx, 128, 128);
	// ft_memset(image->pixels, 255, image->width * image->height * BPP);
	// mlx_image_to_window(mlx, image, 0, 0);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	// return (EXIT_SUCCESS);