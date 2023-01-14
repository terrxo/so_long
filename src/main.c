/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:16 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/14 02:00:28 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_mlxwindow(t_game *window)
{
	window->mlx = mlx_init();
	window->win = mlx_new_window(window->mlx, window->width * 64, window->height
			* 64, "So Loooooong");
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;

	data.player_step_count = 0;
	if (ac != 2)
		return (ft_printf("Error: number of arguments incorrect."));
	if (map_controller(&data, av) != 0)
		return (ft_printf("Error: structure of map is not valid"));
	init_mlxwindow(&data);
	graphics_cache_assets(&data);
	graphics_render_tile(&data);
	mlx_key_hook(data.win, controls_controller, &data);
	mlx_hook(data.win, 17, 0, data.exit, 0);
	mlx_loop(data.mlx);
	exit_game(&data);
	return (0);
}

// Debug test for x, y coordinate value lookup
// for (int b = 0; b <= data.height; b++)
// {
//     for (int i = 0; i <= data.width; i++)
//         printf("x:%i  y:%i  Val:%c\n", i, b, get_block(&data, i, b));
// }