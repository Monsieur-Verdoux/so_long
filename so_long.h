/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:41:10 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/21 18:52:35 by akovalev         ###   ########.fr       */
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

typedef struct s_img
{
	mlx_texture_t	*txt_free;
	mlx_texture_t	*txt_obs;
	mlx_texture_t	*txt_c;
	mlx_texture_t	*txt_e;
	mlx_texture_t	*txt_pl;
	mlx_image_t		*img_free;
	mlx_image_t		*img_obs;
	mlx_image_t		*img_c;
	mlx_image_t		*img_e;
	mlx_image_t		*img_pl;
}	t_img;

typedef struct s_map
{
	int			name_length;
	int			fd;
	int			bytes_read;
	const char	*filename;
	char		**grid;
	size_t		line_count;
	size_t		line_length;
	int			col_c;
	int			pl_c;
	int			ex_c;
	int			col_col;
	int			tile_w;
	int			tile_l;
	int			tile_sq;
	int			pl_x;
	int			pl_y;
	int			moves;
	int			x;
	int			y;
	t_img		*img;
}	t_map;

int		validate_map(t_map *map);
int		route_validation(t_map *map);
void	free_map(t_map *map, char **grid);
void	draw_map(mlx_t *mlx, t_map *map, t_img *img);
void	captain_hook(mlx_key_data_t keydata, void *param);
void	move_player(t_map *map, t_img *img, char c);

#endif