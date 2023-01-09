/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:40:43 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/09 19:44:28 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_game *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	free(data->map_raw_data);
	return (0);
}