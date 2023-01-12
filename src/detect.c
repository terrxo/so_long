/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:34 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/12 20:13:57 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_block(t_game *map, int x, int y)
{
	int	max_width;
	int	location;

	max_width = map->width + 1;
	location = (y * max_width + x + 1) - 1;
	return (map->map_raw_data[location]);
}

int	swap_player_block(t_game *data, int x, int y)
{
	int		max_width;
	int		location;
	int		player_pos;
	char	swap;

	max_width = data->width + 1;
	player_pos = (data->y_pos * max_width + data->x_pos + 1) - 1;
	location = (y * max_width + x + 1) - 1;
	swap = data->map_raw_data[player_pos];
	data->map_raw_data[player_pos] = '0';
	data->map_raw_data[location] = swap;
	data->x_pos = x;
	data->y_pos = y;
	return (0);
}
