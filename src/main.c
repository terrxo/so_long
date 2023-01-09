/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:16 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/09 15:41:57 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_mlxwindow(t_game *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width * 64, window->height
			* 64 + 64, "So Loooooong");
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		return (ft_printf("Error: number of arguments incorrect."));
	data.item_count = 0;
	data.item_max = 0;
	map_controller(&data, av);
	init_mlxwindow(&data);
	graphics_cache_assets(&data);
	graphics_render_tile(&data);
	mlx_loop(data.mlx);
	return (0);
}

// Debug test for x, y coordinate value lookup
// for (int b = 0; b <= data.height; b++)
// {
//     for (int i = 0; i <= data.width; i++)
//         printf("x:%i  y:%i  Val:%c\n", i, b, get_block(&data, i, b));
// }