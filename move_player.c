/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:06:05 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/27 16:53:43 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	process_direction(t_map *map, t_img *img, char c)
{
	if ((c == 'L') && (map->grid[map->pl_y][map->pl_x - 1] != '1'))
	{
		img->img_pl->instances[0].x -= map->tile_sq;
		map->pl_x--;
	}
	if ((c == 'R') && (map->grid[map->pl_y][map->pl_x + 1] != '1'))
	{
		img->img_pl->instances[0].x += map->tile_sq;
		map->pl_x++;
	}
	if ((c == 'U') && (map->grid[map->pl_y - 1][map->pl_x] != '1'))
	{
		img->img_pl->instances[0].y -= map->tile_sq;
		map->pl_y--;
	}
	if ((c == 'D') && (map->grid[map->pl_y + 1][map->pl_x] != '1'))
	{
		img->img_pl->instances[0].y += map->tile_sq;
		map->pl_y++;
	}
}

void	move_player(t_map *map, t_img *img, char c)
{
	process_direction(map, img, c);
	map->moves++;
	ft_printf("Number of movements: %d\n", map->moves);
	if (map->grid[map->pl_y][map->pl_x] == 'C')
	{
		mlx_image_to_window(map->mlx, img->img_free, \
			map->pl_x * map->tile_sq, map->pl_y * map->tile_sq);
		mlx_delete_image(map->mlx, img->img_pl);
		img->img_pl = mlx_texture_to_image(map->mlx, img->txt_pl);
		mlx_resize_image(img->img_pl, map->tile_sq, map->tile_sq);
		mlx_image_to_window(map->mlx, img->img_pl, \
			map->pl_x * map->tile_sq, map->pl_y * map->tile_sq);
		map->grid[map->pl_y][map->pl_x] = '0';
		map->col_col++;
		ft_printf("%d out of %d collectibles gathered\n", \
			map->col_col, map->col_c);
		if (map->col_col == map->col_c)
			ft_printf("We may now exit\n");
	}
	if (map->grid[map->pl_y][map->pl_x] == 'E' && map->col_col == map->col_c)
	{
		ft_printf("Victory! Total movements: %d\n", map->moves);
		free_map(map, map->grid);
		exit(EXIT_SUCCESS);
	}
}
