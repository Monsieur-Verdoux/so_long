/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:08:18 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/20 17:37:41 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	route_validation(t_map *map)
{
	char		**grid_c;
	size_t		i;
	size_t		x;
	int			check;
	int 		j = 0;

	grid_c = (char **)malloc(map->line_count * sizeof(char *));
	if (!grid_c)
		return (0);
	i = 0;
	while (i < map->line_count)
	{
		grid_c[i] = ft_strdup(map->grid[i]);
		ft_printf("Clone Line[%d]: %s", i, grid_c[i]);
		i++;
	}
	x = 0;
	i = 0;
	check = 1;
	while (check != 0)
	{
		check = 0;
		while (i < map->line_count)
		{
			x = 0;
			ft_printf("\nWe are checking line %d\n", i);
			while (x < map->line_length)
			{
				if (grid_c[i][x] == 'P' || grid_c[i][x] == 'X')
				{
					ft_printf("\nWe found P or X at position grid_c[%d][%d]\n", i , x);
					if (grid_c[i + 1][x] == '0' || grid_c[i + 1][x] == 'C' || grid_c[i + 1][x] == 'E')
						grid_c[i + 1][x] = 'X';
					if (grid_c[i - 1][x] == '0' || grid_c[i - 1][x] == 'C' || grid_c[i - 1][x] == 'E')
						grid_c[i - 1][x] = 'X';
					if (grid_c[i][x + 1] == '0' || grid_c[i][x + 1] == 'C' || grid_c[i][x + 1] == 'E')
						grid_c[i][x + 1] = 'X';
					if (grid_c[i][x - 1] == '0' || grid_c[i][x - 1] == 'C' || grid_c[i][x - 1] == 'E')
						grid_c[i][x - 1] = 'X';
					grid_c[i][x] = '*';
					check = 1;
					j = 0;
					while (j < map->line_count)
					{
						ft_printf("Line[%d]: %s\n", j, grid_c[j]);
						j++;
					}
				}
				x++;
			}
			i++;
		}
		i = 0;
	}
	i = 0;
	while (i < map->line_count)
	{
		if (ft_strchr(grid_c[i], 'C') || ft_strchr(grid_c[i], 'E'))
			return (0);
		i++;
	}
	j = 0;
	while (j < map->line_count)
					{
						ft_printf("oLine[%d]: %s\n", j, map->grid[j]);
						j++;
					}
	return (1);
}