/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:33 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/29 15:18:53 by akovalev         ###   ########.fr       */
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

void	initialize_map_values(t_map *map)
{
	map->ex_c = 0;
	map->col_c = 0;
	map->pl_c = 0;
	map->line_count = 0;
	map->wnd_w = 1366;
	map->wnd_h = 768;
	map->moves = 0;
	map->col_col = 0;
	map->n = 0;
	map->check = 1;
}

int	main(int argc, const char **argv)
{
	mlx_t		*mlx;
	t_map		map;
	t_img		image;

	map.img = &image;
	check_arguments (argc, argv, &map);
	initialize_map_values(&map);
	if (!validate_map(&map))
	{
		free_map(&map, map.grid);
		exit(EXIT_FAILURE);
	}
	mlx = mlx_init(1366, 768, "so_long", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	map.mlx = mlx;
	handle_images(mlx, &map, &image);
	draw_map(mlx, &map, &image);
	mlx_key_hook(mlx, movement_hook, &map);
	mlx_resize_hook(mlx, resize_hook, &map);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free_map(&map, map.grid);
	exit(EXIT_SUCCESS);
}
