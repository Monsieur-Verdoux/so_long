/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:29:56 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/28 17:08:51 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sizing(t_map *map)
{
	map->tile_l = map->wnd_w / (map->line_length - 1);
	map->tile_w = map->wnd_h / map->line_count;
	if (map->tile_l <= map->tile_w)
		map->tile_sq = map->tile_l;
	else
		map->tile_sq = map->tile_w;
}

void	handle_images(mlx_t *mlx, t_map *map, t_img *img)
{
	ft_printf("We are about to transfer textures to images\n");
	img->txt_free = mlx_load_png("./assets/free.png");
	img->txt_obs = mlx_load_png("./assets/wall.png");
	img->txt_c = mlx_load_png("./assets/BloatedBedbugIdleSide.png");
	img->txt_e = mlx_load_png("./assets/exit.png");
	img->txt_e_o = mlx_load_png("./assets/exit1.png");
	img->txt_pl = mlx_load_png("./assets/CarnivorousWormIdleSide.png");
	ft_printf("We finished loading the images\n");
	ft_printf("We are about to transfer textures to images\n");
	img->img_free = mlx_texture_to_image(mlx, img->txt_free);
	img->img_obs = mlx_texture_to_image(mlx, img->txt_obs);
	img->img_c = mlx_texture_to_image(mlx, img->txt_c);
	img->img_e = mlx_texture_to_image(mlx, img->txt_e);
	img->img_e_o = mlx_texture_to_image(mlx, img->txt_e_o);
	img->img_pl = mlx_texture_to_image(mlx, img->txt_pl);
	ft_printf("We finished transfering to images\n");
	ft_printf("We are about to resize the images\n");
	mlx_resize_image(img->img_free, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_obs, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_c, map->tile_sq / 1.5, map->tile_sq / 1.5);
	mlx_resize_image(img->img_e, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_e_o, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_pl, map->tile_sq, map->tile_sq);
}

void	draw_point(mlx_t *mlx, t_map *map, t_img *img)
{
	if (map->grid[map->y][map->x] == '0')
		mlx_image_to_window(mlx, img->img_free, \
			map->x * map->tile_sq, map->y * map->tile_sq);
	else if (map->grid[map->y][map->x] == '1')
		mlx_image_to_window(mlx, img->img_obs, \
			map->x * map->tile_sq, map->y * map->tile_sq);
	else if (map->grid[map->y][map->x] == 'C')
	{
		mlx_image_to_window(mlx, img->img_free, \
			map->x * map->tile_sq, map->y * map->tile_sq);
		mlx_image_to_window(mlx, img->img_c, \
			map->x * map->tile_sq + map->tile_w / 8, \
				map->y * map->tile_sq + map->tile_l / 8);
	}
	else if (map->grid[map->y][map->x] == 'E')
	{
		mlx_image_to_window(mlx, img->img_e, \
			map->x * map->tile_sq, map->y * map->tile_sq);
		map->ex_x = map->x;
		map->ex_y = map->y;
		map->grid[map->y][map->x] = 'e';
	}
	else if (map->grid[map->y][map->x] == 'P')
	{
		map->pl_x = map->x;
		map->pl_y = map->y;
		mlx_image_to_window(mlx, img->img_free, \
			map->pl_x * map->tile_sq, map->pl_y * map->tile_sq);
		map->grid[map->y][map->x] = 'p';
	}
	else if (map->grid[map->y][map->x] == 'p')
	{
		mlx_image_to_window(mlx, img->img_free, \
			map->x * map->tile_sq, map->y * map->tile_sq);
	}
	else if (map->grid[map->y][map->x] == 'e')
	{
		mlx_image_to_window(mlx, img->img_e, \
			map->x * map->tile_sq, map->y * map->tile_sq);
		if (map->col_col == map->col_c)
			mlx_image_to_window(mlx, img->img_e_o, \
				map->x * map->tile_sq, map->y * map->tile_sq);
	}
}

void	draw_lines(mlx_t *mlx, t_map *map, t_img *img)
{
	while (map->y < map->line_count)
	{
		while (map->x < map->line_length)
		{
			draw_point(mlx, map, img);
			map->x++;
		}
		map->y++;
		map->x = 0;
	}
}

void	draw_map(mlx_t *mlx, t_map *map, t_img *img)
{
	map->x = 0;
	map->y = 0;
	ft_printf("We are about to determine the map size\n");
	sizing(map);
	ft_printf("We are about to draw the map\n");
	draw_lines(mlx, map, img);
	mlx_image_to_window(mlx, img->img_pl, \
		map->pl_x * map->tile_sq, map->pl_y * map->tile_sq);
	ft_printf("We should have drawn the map\n");
}
