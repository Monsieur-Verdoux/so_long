/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:41:10 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/18 19:12:47 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"
# include "libft/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

# define BPP sizeof(int32_t)

typedef struct s_map
{
	int			name_length;
	int			fd;
	int			bytes_read;
	const char	*filename;
	char		**grid;
	int			i;
	int			line_count;
	size_t		line_length;
	int			coll_c;
	int			player_c;
	int			exit_c;
}	t_map;

int	validate_map(t_map *map);

#endif