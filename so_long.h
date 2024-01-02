/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:41:10 by akovalev          #+#    #+#             */
/*   Updated: 2024/01/02 16:12:15 by akovalev         ###   ########.fr       */
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

typedef struct s_img
{
	mlx_texture_t	*txt_free;
	mlx_texture_t	*txt_obs;
	mlx_texture_t	*txt_c;
	mlx_texture_t	*txt_e;
	mlx_texture_t	*txt_e_o;
	mlx_texture_t	*txt_pl;
	mlx_image_t		*img_free;
	mlx_image_t		*img_obs;
	mlx_image_t		*img_c;
	mlx_image_t		*img_e;
	mlx_image_t		*img_e_o;
	mlx_image_t		*img_pl;
}	t_img;

typedef struct s_map
{
	int			name_length;
	int			fd;
	int			bytes_read;
	const char	*filename;
	char		**grid;
	int			line_count;
	int			line_length;
	int			col_c;
	int			pl_c;
	int			ex_c;
	int			col_col;
	int			tile_w;
	int			tile_l;
	int			tile_sq;
	int			pl_x;
	int			pl_y;
	int			ex_x;
	int			ex_y;
	int			moves;
	int			check;
	int			x;
	int			y;
	int			n;
	int			wnd_w;
	int			wnd_h;
	mlx_t		*mlx;
	t_img		*img;
}	t_map;

int		validate_map(t_map *map);
int		route_validation(t_map *map);
void	free_map(t_map *map, char **grid);
void	draw_map(mlx_t *mlx, t_map *map, t_img *img);
void	movement_hook(mlx_key_data_t keydata, void *param);
void	resize_hook(int32_t width, int32_t height, void *param);
void	move_player(t_map *map, t_img *img, char c);
void	handle_images(mlx_t *mlx, t_map *map, t_img *img);
void	sizing(t_map *map);
void	malloc_error(t_map *map, char **grid, int check);

#endif