/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:20:29 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/27 15:30:34 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, char **grid)
{
	int	row;

	row = 0;
	while (row < map->line_count)
	{
		printf("Current row being freed: %s\n", grid[row]);
		free(grid[row]);
		grid[row] = NULL;
		row++;
	}
	free(grid);
	grid = NULL;
}
