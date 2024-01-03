/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:04:37 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/03 13:41:26 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_lines(t_map *map)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = map->grid[i];
	while (i < map->line_count)
	{
		ptr = map->grid[i];
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
	int		line_length;
	int		i;

	map->grid = (char **)malloc(map->line_count * sizeof(char *));
	if (!map->grid)
		malloc_error(map, map->grid, 0);
	i = 0;
	while (i < map->line_count)
	{
		map->grid[i] = get_next_line(map->fd);
		i++;
	}
	i = 0;
	map->line_length = ft_strlen(map->grid[i]);
	while (i < map->line_count)
	{
		line_length = ft_strlen(map->grid[i]);
		if (line_length != map->line_length)
			return (0);
		i++;
	}
	close(map->fd);
	return (1);
}

int	count_lines(int fd, t_map *map)
{
	char	buffer[1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, 1);
		if (bytes_read < 0)
			return (0);
		if (buffer[0] == 'C')
			map->col_c++;
		if (buffer[0] == 'P')
			map->pl_c++;
		if (buffer[0] == 'E')
			map->ex_c++;
		if (bytes_read > 0 && buffer[0] == '\n')
			map->line_count++;
		if (buffer[0] != '\n' && buffer[0] != '0' && buffer[0] != '1' \
			&& buffer[0] != 'C' && buffer[0] != 'P' && buffer[0] != 'E')
		{
			ft_printf("Error\nInvalid characters: %c\n", buffer[0]);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

int	basic_checks(t_map *map)
{
	if (!map->filename)
	{
		ft_printf("Error\nName error\n");
		return (0);
	}
	map->name_length = ft_strlen(map->filename);
	if (ft_strncmp(&map->filename[map->name_length - 4], ".ber", 4))
	{
		ft_printf("Error\nMap name does not end in .ber\n");
		return (0);
	}
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Error\n");
		close(map->fd);
		return (0);
	}
	if (!count_lines(map->fd, map))
	{
		ft_printf("Error\nRead error\n");
		return (0);
	}
	close(map->fd);
	return (1);
}

int	validate_map(t_map *map)
{
	if (!basic_checks (map))
		exit(EXIT_FAILURE);
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
	{
		perror("Error\n");
		close(map->fd);
		exit(EXIT_FAILURE);
	}
	if (!populate_map(map))
	{
		ft_printf("Error\nInvalid shape\n");
		return (0);
	}
	if (!check_lines(map))
	{
		ft_printf("Error\nLines are invalid\n");
		return (0);
	}
	if (!route_validation(map))
	{
		ft_printf("Error\nNo possible route\n");
		return (0);
	}
	return (1);
}
