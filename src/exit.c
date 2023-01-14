/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:40:43 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/14 02:33:23 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_win(t_game *data, int val)
{
	if (data->item_count == 0 && val == 'E')
		return (1);
	return (0);
}

int	exit_game(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->map_raw_data);
	free(data->mlx);
	exit(0);
}
