/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:57:22 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/14 02:12:47 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_sprites(t_game *map)
{
	int	player;
	int	item;
	int	exit;
	int	i;

	player = 0;
	item = 0;
	exit = 0;
	i = -1;
	while (map->map_raw_data[++i])
	{
		if (map->map_raw_data[i] == 'P')
		{
			player++;
			map->p_index = i;
		}
		else if (map->map_raw_data[i] == 'E')
			exit++;
		else if (map->map_raw_data[i] == 'C')
			item++;
	}
	if (player != 1 || exit != 1 || item == 0)
		return (1);
	map->item_count = item;
	return (0);
}

int	check_walls(t_game *map)
{
	int	i;

	i = 0;
	while (i < map->width)
		if (get_block(map, i, 0) != '1' || get_block(map, i++, map->height
				- 1) != '1')
			return (1);
	i = 0;
	while (i < map->height)
	{
		if ((get_block(map, 0, i) != '1') || (get_block(map, map->width - 1,
					i++)) != '1')
			return (1);
	}
	return (0);
}

int	map_check_controller(t_game *map)
{
	if (check_walls(map) != 0 || check_sprites(map) != 0)
		return (1);
	map->y_pos = map->p_index / (map->width + 1);
	map->x_pos = map->p_index % (map->width + 1);
	if (get_block(map, map->x_pos, map->y_pos) != 'P')
		return (1);
	map->map_virus = ft_strdup(map->map_raw_data);
	if (virus_controller(map) != 0)
	{
		free(map->map_virus);
		return (1);
	}
	free(map->map_virus);
	return (0);
}

// printf("Index: %i, val: %c, Block_val: %c x: %i, y: %i\n", map->p_index,
// 		map->map_raw_data[map->p_index], get_block(map, map->x_pos,
// 			map->y_pos), map->x_pos, map->y_pos);