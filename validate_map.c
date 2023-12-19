/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:04:37 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/19 18:57:18 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->line_count)
	{
		free(map->grid[row]);
		row++;
	}
	free(map->grid);
}

int	check_lines(t_map *map)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = map->grid[i];
	while (i < map->line_count)
	{
		ptr = map->grid[i];
		ft_printf("Current line[%d]: %s\n", i, map->grid[i]);
		while (*ptr)
		{
			if ((i == 0 || i == map->line_count - 1) \
				&& (*ptr != '1' && *ptr != '\n'))
				return (0);
			if ((i != 0 && i != map->line_count - 1) && (map->grid[i][0] != '1' \
			|| map->grid[i][map->line_length - 2] != '1'))
				return (0);
			ptr++;
		}
		i++;
	}
	if (map->col_c <= 0 || map->pl_c != 1 || map->ex_c != 1)
		return (0);
	return (1);
}

int	populate_map(t_map *map)
{
	size_t		line_length;
	size_t		i;

	map->grid = (char **)malloc(map->line_count * sizeof(char *));
	if (!map->grid)
		return (0);
	i = 0;
	while (i < map->line_count)
	{
		map->grid[i] = get_next_line(map->fd);
		ft_printf("Line[%d]: %s\n", i, map->grid[i]);
		i++;
	}
	i = 0;
	map->line_length = ft_strlen(map->grid[i]);
	while (i < map->line_count - 1)
	{
		line_length = ft_strlen(map->grid[i]);
		if (line_length != map->line_length)
			return (0);
		i++;
	}
	line_length = ft_strlen(map->grid[i]);
	if (line_length != map->line_length - 1)
		return (0);
	return (1);
}

int	count_lines(int fd, t_map *map)
{
	char	buffer[1];
	int		bytes_read;

	map->ex_c = 0;
	map->col_c = 0;
	map->pl_c = 0;
	map->line_count = 0;
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 1);
		if (buffer[0] == 'C')
			map->col_c++;
		if (buffer[0] == 'P')
			map->pl_c++;
		if (buffer[0] == 'E')
			map->ex_c++;
		if (bytes_read > 0 && buffer[0] == '\n')
			map->line_count++;
	}
	if (buffer[0] != '\n')
		map->line_count++;
	return (map->line_count);
}

int	basic_checks(t_map *map)
{
	if (!map->filename)
	{
		ft_printf("Error: Name error\n");
		return (0);
	}
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Error");
		return (0);
	}
	map->name_length = ft_strlen(map->filename);
	if (ft_strncmp(&map->filename[map->name_length - 4], ".ber", 4))
	{
		ft_printf("Error: Map name does not end in .ber\n");
		return (0);
	}
	return (1);
}

int	validate_map(t_map *map)
{
	size_t	char_count;
	size_t	line_count;

	if (!basic_checks (map))
		return (0);
	char_count = count_lines(map->fd, map);
	ft_printf("Line count is: %d\n", map->line_count);
	close(map->fd);
	map->fd = open(map->filename, O_RDONLY);
	if (!populate_map(map))
	{
		ft_printf("Error: Invalid map\n\n");
		free_map(map);
		return (0);
	}
	if (!check_lines(map))
	{
		ft_printf("Error: Invalid map\n\n");
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}
