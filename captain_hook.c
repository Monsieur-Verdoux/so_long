/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captain_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:13:52 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/27 17:08:05 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	captain_hook(mlx_key_data_t keydata, void *param)
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
