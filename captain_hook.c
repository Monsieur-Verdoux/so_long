/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captain_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:13:52 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/21 18:48:18 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void captain_hook(mlx_key_data_t keydata, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		ft_printf("ESC pressed\n");
		free_map(map, map->grid);
		exit(EXIT_SUCCESS);
	}
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS))
		move_player(map, map->img, 'U');
	if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
		move_player(map, map->img, 'L');
	if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
		move_player(map, map->img, 'D');
	if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
		move_player(map, map->img, 'R');
}
// void	captain_hook(void *param)
// {
// 	t_map	*map;

// 	map = (t_map *)param;
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_ESCAPE))
// 	{
// 		free_map(map, map->grid);
// 		exit(EXIT_SUCCESS);
// 	}
// 	//	mlx_close_window(map);
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_UP))
// 		map->pl_y++;
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_DOWN))
// 		map->pl_y--;
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_LEFT))
// 		if (map->grid[map->pl_y][map->pl_x - 1] != '1')
// 		{
// 			map->img->img_pl->instances[0].x -= map->tile_sq;
// 			map->pl_x--;
// 			// if(map->grid[map->pl_y][map->pl_x] == 'C')
// 			// 	collect_chest(map, img, map->mlx);
// 			// if(map->grid[map->pl_y][map->pl_x] == 'e')
// 			//	ft_printf("You win!\n");	
// 		}
// 	if (mlx_is_key_down(map->mlx, MLX_KEY_RIGHT))
// 		map->pl_x++;
// 	// if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && (keydata.action == MLX_PRESS))
// 	// 	move_player(map, map->img, 'U');
// 	// if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && keydata.action == MLX_PRESS)
// 	// 	move_player(map, map->img, 'L');
// 	// if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && keydata.action == MLX_PRESS)
// 	// 	move_player(map, map->img, 'D');
// 	// if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && keydata.action == MLX_PRESS)
// 	// 	move_player(map, map->img, 'R');
// }
