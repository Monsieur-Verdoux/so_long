/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:29:56 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/21 18:55:00 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizing (t_map *map)
{
	map->tile_l = 1366 / map->line_length;
	map->tile_w = 768 / map->line_count;
	if (map->tile_l <= map->tile_w)
		map->tile_sq = map->tile_l;
	else
		map->tile_sq = map->tile_w;
}

void	draw_map(mlx_t *mlx, t_map *map, t_img *img)
{
	map->x = 0;
	map->y = 0;
	ft_printf("We are about to determine the map size\n");
	sizing(map);

	img->txt_free = mlx_load_png("./assets/free.png");
	img->txt_obs = mlx_load_png("./assets/wall.png");
	img->txt_c = mlx_load_png("./assets/BloatedBedbugIdleSide.png");
	img->txt_e = mlx_load_png("./assets/exit.png");
	img->txt_pl = mlx_load_png("./assets/CarnivorousWormIdleSide.png");
	ft_printf("We are about to transfer textures to images\n");
	img->img_free = mlx_texture_to_image(mlx, img->txt_free);
	img->img_obs = mlx_texture_to_image(mlx, img->txt_obs);
	img->img_c = mlx_texture_to_image(mlx, img->txt_c);
	img->img_e = mlx_texture_to_image(mlx, img->txt_e);
	img->img_pl = mlx_texture_to_image(mlx, img->txt_pl);
	ft_printf("We are about to resize the images\n");

	mlx_resize_image(img->img_free, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_obs, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_c, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_e, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_pl, map->tile_sq, map->tile_sq);
	ft_printf("We are about to draw the map\n");
	while (map->y < map->line_count)
	{
		while (map->x < map->line_length)
		{
			if (map->grid[map->y][map->x] == '0')
				mlx_image_to_window(mlx, img->img_free, map->x * map->tile_sq, map->y * map->tile_sq);
			else if (map->grid[map->y][map->x] == '1')
				mlx_image_to_window(mlx, img->img_obs, map->x * map->tile_sq, map->y * map->tile_sq);
			else if (map->grid[map->y][map->x] == 'C')
			{
				mlx_image_to_window(mlx, img->img_free, map->x * map->tile_sq, map->y * map->tile_sq);
				mlx_image_to_window(mlx, img->img_c, map->x * map->tile_sq, map->y * map->tile_sq);
			}
			else if (map->grid[map->y][map->x] == 'E')
				mlx_image_to_window(mlx, img->img_e, map->x * map->tile_sq, map->y * map->tile_sq);
			else if (map->grid[map->y][map->x] == 'P')
			{
				map->pl_x = map->x;
				map->pl_y = map->y;
				mlx_image_to_window(mlx, img->img_free, map->x * map->tile_sq, map->y * map->tile_sq);
				mlx_image_to_window(mlx, img->img_pl, map->pl_x * map->tile_sq, map->pl_y * map->tile_sq);
			}
			map->x++;
		}
		map->y++;
		map->x = 0;
	}
	map->moves = 0;
	ft_printf("We should have drawn the map\n");
}