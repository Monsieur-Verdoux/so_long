/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:04:37 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/15 19:22:34 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	row;

	row = 0;
	while (row < map->i)
	{
		free(map->grid[row]);
		row++;
	}
	free(map->grid);
}

// int	check_lines (t_map *map)
// {
	
// }

int	populate_map(t_map *map)
{
	size_t		line_length;
	size_t		i;

	map->grid = (char **)malloc(map->line_count * sizeof(char *));
	map->i = 0;
	while (map->i < map->line_count)
	{
		map->grid[map->i] = get_next_line(map->fd);
		ft_printf("Line[%d]: %s\n", map->i, map->grid[map->i]);
		map->i++;
	}
	i = 0;
	map->line_length = ft_strlen(map->grid[i]);
	ft_printf("First line length: %d\n\n", map->line_length);
	while (i < map->i)
	{
		line_length = ft_strlen(map->grid[i]);
		ft_printf("Current line length: %d\n\n", line_length);
		if (line_length != map->line_length || map->grid[i][map->line_length - 1] != '\n')
		{
			ft_printf("Current character: %c\n\n", map->grid[i][map->line_length]);
			return (0);
		}
		i++;
	}
	return (1);
}

int	count_lines(int fd, t_map *map)
{
	char	buffer[1];
	int		bytes_read;

	map->line_count = 0;
	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read > 0 && buffer[0] == '\n')
		{
			map->line_count++;
			ft_printf("Current line count is: %d\n\n", map->line_count);
		}
	}
	return (map->line_count);
}

int	validate_map(t_map *map)
{
	size_t	char_count;
	size_t	line_count;

	if (!map->filename)
	{
		ft_printf("Name error\n");
		return (0);
	}
	map->name_length = ft_strlen(map->filename);
	if (ft_strncmp(&map->filename[map->name_length - 4], ".ber", 4))
	{
		ft_printf("Map name does not end in .ber\n");
		return (0);
	}
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Unable to open map file");
		return (0);
	}
	char_count = count_lines(map->fd, map);
	ft_printf("Line count is: %d\n", map->line_count);
	close(map->fd);
	map->fd = open(map->filename, O_RDONLY);
	if (!populate_map(map))
	{
		ft_printf("Invalid line map length\n\n");
		free_map(map);
		return (0);
	}
	free_map(map);
	return (1);
}
