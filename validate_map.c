/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:04:37 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/18 19:11:33 by akovalev         ###   ########.fr       */
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

int	check_lines (t_map *map)
{
	int	i;
	int	coll_count;
	int	exit;
	int	player;
	char *ptr;

	ptr = map->grid[i];

	i = 0;
	exit = 0;
	coll_count = 0;
	player = 0;
	while (i < map->i)
	{
		ptr = map->grid[i];
		ft_printf("Current line[%d]: %s\n", i, map->grid[i]);
		while (*ptr)
		{
			ft_printf("\nCurrent character: %c\n", *ptr);
			ft_printf("\nFirst character: %c\n", map->grid[i][0]);
			ft_printf("\nLast character: %c\n", map->grid[i][map->line_length - 2]);
			if ((i == 0 || i == map->line_count - 1) && (*ptr != '1' && *ptr != '\n'))
				return (0);
			if ((i != 0 && i != map->line_count - 1) && (map->grid[i][0] != '1' || map->grid[i][map->line_length - 2] != '1'))
				return (0);
			if (*ptr == 'C')
				coll_count++;
			if (*ptr == 'P')
				player++;
			if (*ptr == 'E')
				exit++;
			ptr++;
		}
		i++;
	}
	ft_printf("\nCurrent collectible count: %d\n", coll_count);
	ft_printf("\nCurrent player count: %d\n", player);
	ft_printf("\nCurrent exit count: %d\n", exit);
	if (coll_count <= 0 || player != 1 || exit != 1)
		return (0);
	return (1);
}

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
	ft_printf("\nFirst line length: %d\n\n", map->line_length);
	while (i < map->i - 1)
	{
		line_length = ft_strlen(map->grid[i]);
		ft_printf("Current line length: %d\n\n", line_length);
		if (line_length != map->line_length)
		{
			return (0);
		}
		i++;
	}
	if (i == map->i - 1)
	{
		line_length = ft_strlen(map->grid[i]);
		if (line_length != map->line_length - 1)
			return (0);
		return (1);
	}
	return (0);
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
	if (buffer[0] != '\n')
		map->line_count++;
	return (map->line_count);
}

int	validate_map(t_map *map)
{
	size_t	char_count;
	size_t	line_count;

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
	ft_printf("Current i is: %d\n\n", map->i);
	ft_printf("Current lc is: %d\n\n", map->line_count);
	free_map(map);
	return (1);
}
