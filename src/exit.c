/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:40:43 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/12 17:29:41 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_game *data)
{
	// mlx_destroy_image(data->mlx, data->floor);
	// mlx_destroy_image(data->mlx, data->wall);
	// mlx_destroy_image(data->mlx, data->exit);
	// mlx_destroy_image(data->mlx, data->item);
	// mlx_destroy_image(data->mlx, data->player);
	mlx_destroy_window(data->mlx, data->win);
	free(data->map_raw_data);
	free(data->mlx);
	exit(0);
}