/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:33 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:34 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char **argv)
{
	mlx_t		*mlx;
	t_map		map;
	t_img		image;

	map.img = &image;
	if (argc <= 1)
	{
		ft_printf("Error: no map file to read\n");
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf("Error: please only input one map file\n");
		return (EXIT_FAILURE);
	}
	map.filename = argv[1];
	if (!validate_map(&map))
	{
		free_map(&map, map.grid);
		return (EXIT_FAILURE);
	}
	mlx = mlx_init(1366, 768, "so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	ft_printf("We are about to draw the map\n");
	draw_map(mlx, &map, &image);
	mlx_key_hook(mlx, captain_hook, &map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map(&map, map.grid);
	exit(EXIT_SUCCESS);

	// image = mlx_new_image(mlx, 128, 128);
	// ft_memset(image->pixels, 255, image->width * image->height * BPP);
	// mlx_image_to_window(mlx, image, 0, 0);
	// mlx_loop(mlx);
	// mlx_terminate(mlx);
	// return (EXIT_SUCCESS);
}
