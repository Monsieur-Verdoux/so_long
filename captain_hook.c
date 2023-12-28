/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captain_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:55:37 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/28 15:55:42 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	movement_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("ESC pressed\n");
		free_map(map, map->grid);
		exit(EXIT_SUCCESS);
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
		&& (keydata.action == MLX_PRESS))
		move_player(map, map->img, 'U');
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
		&& keydata.action == MLX_PRESS)
		move_player(map, map->img, 'L');
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
		&& keydata.action == MLX_PRESS)
		move_player(map, map->img, 'D');
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
		&& keydata.action == MLX_PRESS)
		move_player(map, map->img, 'R');
}

void	resize_handle_images(mlx_t *mlx, t_map *map, t_img *img)
{
	mlx_delete_image(map->mlx, map->img->img_c);
	mlx_delete_image(map->mlx, map->img->img_e);
	mlx_delete_image(map->mlx, map->img->img_e_o);
	mlx_delete_image(map->mlx, map->img->img_free);
	mlx_delete_image(map->mlx, map->img->img_obs);
	mlx_delete_image(map->mlx, map->img->img_pl);
	img->img_free = mlx_texture_to_image(mlx, img->txt_free);
	img->img_obs = mlx_texture_to_image(mlx, img->txt_obs);
	img->img_c = mlx_texture_to_image(mlx, img->txt_c);
	img->img_e = mlx_texture_to_image(mlx, img->txt_e);
	img->img_e_o = mlx_texture_to_image(mlx, img->txt_e_o);
	img->img_pl = mlx_texture_to_image(mlx, img->txt_pl);
	mlx_resize_image(img->img_free, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_obs, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_c, map->tile_sq / 1.5, map->tile_sq / 1.5);
	mlx_resize_image(img->img_e, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_e_o, map->tile_sq, map->tile_sq);
	mlx_resize_image(img->img_pl, map->tile_sq, map->tile_sq);
}

void	resize_hook(int32_t width, int32_t height, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	map->wnd_h = height;
	map->wnd_w = width;
	resize_handle_images(map->mlx, map, map->img);
	draw_map(map->mlx, map, map->img);
}
