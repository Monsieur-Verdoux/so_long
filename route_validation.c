/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:18 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/20 19:06:07 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_point(char **grid_c, t_map *map, size_t i, size_t x)
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
	size_t		i;
	size_t		x;
	int			check;

	x = 0;
	i = 0;
	while (check != 0)
	{
		check = 0;
		while (i < map->line_count)
		{
			x = 0;
			while (x < map->line_length)
			{
				if (grid_c[i][x] == 'P' || grid_c[i][x] == 'X')
				{
					parse_point(grid_c, map, i, x);
					check = 1;
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
	size_t		i;

	grid_c = (char **)malloc(map->line_count * sizeof(char *));
	if (!grid_c)
		return (0);
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

	// i = 0;
	// while (i < map->line_count)
	// {
	// 	ft_printf("OrLine[%d]: %s\n", i, map->grid[i]);
	// 	i++;
	// }
	// i = 0;
	// while (i < map->line_count)
	// {
	// 	ft_printf("CLine[%d]: %s\n", i, grid_c[i]);
	// 	i++;
	// }
