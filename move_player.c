/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:06:05 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/21 18:48:40 by akovalev         ###   ########.fr       */
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
}
