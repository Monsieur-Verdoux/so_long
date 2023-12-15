/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akovalev <akovalev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:40:33 by akovalev          #+#    #+#             */
/*   Updated: 2023/12/15 15:57:24 by akovalev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, const char **argv)
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_map		map;

	if (argc <= 1)
	{
		ft_printf("Error: no map file to read\n");
		return (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf("Error: please only input one map file\n");
		return (EXIT_FAILURE);
	}
	map.filename = argv[1];
	if (!validate_map(&map))
		return (EXIT_FAILURE);
	mlx = mlx_init(256, 256, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	image = mlx_new_image(mlx, 128, 128);
	ft_memset(image->pixels, 255, image->width * image->height * BPP);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
