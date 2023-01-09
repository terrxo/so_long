/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:34 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/09 14:05:16 by ndivjak          ###   ########.fr       */
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
