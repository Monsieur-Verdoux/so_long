/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:06:05 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/21 19:41:27 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_map *map, t_img *img, char c)
{
	if (c == 'L')
	{
		if (map->grid[map->pl_y][map->pl_x - 1] != '1')
		{
			img->img_pl->instances[0].x -= map->tile_sq;
			map->pl_x--;
		}
		map->moves++;
		ft_printf("Number of movements: %d\n", map->moves);
	}
	if (c == 'R')
	{
		if (map->grid[map->pl_y][map->pl_x + 1] != '1')
		{
			img->img_pl->instances[0].x += map->tile_sq;
			map->pl_x++;
		}
		map->moves++;
		ft_printf("Number of movements: %d\n", map->moves);
	}
	if (c == 'U')
	{
		if (map->grid[map->pl_y - 1][map->pl_x] != '1')
		{
			img->img_pl->instances[0].y -= map->tile_sq;
			map->pl_y--;
		}
		map->moves++;
		ft_printf("Number of movements: %d\n", map->moves);
	}
	if (c == 'D')
	{
		if (map->grid[map->pl_y + 1][map->pl_x] != '1')
		{
			img->img_pl->instances[0].y += map->tile_sq;
			map->pl_y++;
		}
		map->moves++;
		ft_printf("Number of movements: %d\n", map->moves);
	}
	if (map->grid[map->pl_y][map->pl_x] == 'C')
	{
		//mlx_delete_image(map->mlx, img->img_c);
		mlx_set_instance_depth(&img->img_c->instances[map->n], -100);
		map->n++;
		ft_printf("Next instance of collectible: %d\n", map->n);
		map->grid[map->pl_y][map->pl_x] = 'c';
		map->col_col++;
		ft_printf("%d out of %d collectibles gathered\n", map->col_col, map->col_c);
		if (map->col_col == map->col_c)
			ft_printf("We may now exit\n");
	}
	if (map->grid[map->pl_y][map->pl_x] == 'E' && map->col_col == map->col_c)
	{
		ft_printf("Victory! Total moves:%d\n", map->moves);
		//free_map(map, map->grid);
		exit(EXIT_SUCCESS);
	}
}
