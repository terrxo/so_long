/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 19:40:43 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/12 17:58:17 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->map_raw_data);
	free(data->mlx);
	exit(0);
}