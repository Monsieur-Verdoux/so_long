/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 18:20:29 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/02 16:11:19 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map, char **grid)
{
	int	row;

	row = 0;
	while (row < map->line_count)
	{
		free(grid[row]);
		grid[row] = NULL;
		row++;
	}
	free(grid);
	grid = NULL;
}

void	malloc_error(t_map *map, char **grid, int check)
{
	ft_printf("Error\nMalloc error\n");
	if (check == 1)
		free_map(map, grid);
	exit(EXIT_FAILURE);
}

