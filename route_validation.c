/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:18 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/02 16:10:08 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_point(char **grid_c, size_t i, size_t x)
{
	if (grid_c[i + 1][x] == '0' || \
	grid_c[i + 1][x] == 'C' || grid_c[i + 1][x] == 'E')
		grid_c[i + 1][x] = 'X';
	if (grid_c[i - 1][x] == '0' || \
	grid_c[i - 1][x] == 'C' || grid_c[i - 1][x] == 'E')
		grid_c[i - 1][x] = 'X';
	if (grid_c[i][x + 1] == '0' || \
	grid_c[i][x + 1] == 'C' || grid_c[i][x + 1] == 'E')
		grid_c[i][x + 1] = 'X';
	if (grid_c[i][x - 1] == '0' || \
	grid_c[i][x - 1] == 'C' || grid_c[i][x - 1] == 'E')
		grid_c[i][x - 1] = 'X';
	grid_c[i][x] = '*';
}

void	parse_line(char **grid_c, t_map *map)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (map->check != 0)
	{
		map->check = 0;
		while (i < map->line_count)
		{
			x = 0;
			while (x < map->line_length)
			{
				if (grid_c[i][x] == 'P' || grid_c[i][x] == 'X')
				{
					parse_point(grid_c, i, x);
					map->check = 1;
				}
				x++;
			}
			i++;
		}
		i = 0;
	}
}

int	route_validation(t_map *map)
{
	char		**grid_c;
	int			i;

	grid_c = (char **)malloc(map->line_count * sizeof(char *));
	if (!grid_c)
		malloc_error(map, map->grid, 1);
	i = 0;
	while (i < map->line_count)
	{
		grid_c[i] = ft_strdup(map->grid[i]);
		i++;
	}
	parse_line(grid_c, map);
	i = 0;
	while (i < map->line_count)
	{
		if (ft_strchr(grid_c[i], 'C') || ft_strchr(grid_c[i], 'E'))
		{
			free_map(map, grid_c);
			return (0);
		}
		i++;
	}
	free_map(map, grid_c);
	return (1);
}
