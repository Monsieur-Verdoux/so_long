/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:04:37 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/15 18:08:47 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	for (int row = 0; row < map->i; row++)
	{
		free(map->grid[row]);
	}
	free(map->grid);
}

void	populate_map(t_map *map, size_t line_count)
{
	map->grid = (char **)malloc(line_count * sizeof(char *));
	map->i = 0;
	while (map->i < line_count)
	{
		map->grid[map->i] = get_next_line(map->fd);
		ft_printf("Line[%d]: %s\n", map->i, map->grid[map->i]);
		map->i++;
	}
}

int	count_characters(int fd)
{
	char	buffer[1];
	int		bytes_read;
	int		i;

	bytes_read = 1;
	i = 0;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 1);
		i++;
	}
	return (i);
}

int	count_lines(int fd, size_t char_count)
{
	char	*buffer;
	int		line_count;
	int		bytes_read;
	int		i;

	buffer = (char *)malloc(char_count + 1);
	i = 0;
	line_count = 0;
	bytes_read = read (fd, buffer, char_count);
	while (i < bytes_read)
	{
		if (buffer[i] == '\n')
		{
			line_count++;
		}
		i++;
	}
	free(buffer);
	return (line_count);
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
	char_count = count_characters(map->fd);
	ft_printf("Character count is: %d\n", char_count);
	close(map->fd);
	map->fd = open(map->filename, O_RDONLY);
	line_count = count_lines(map->fd, char_count);
	ft_printf("Line count is: %d\n", line_count);
	close(map->fd);
	map->fd = open(map->filename, O_RDONLY);
	populate_map(map, line_count);
	free_map(map);
	return (1);
}
