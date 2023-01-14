/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   virus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:53:03 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/14 02:32:25 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_and_infect_block(t_game *data, int x, int y)
{
	char	c;
	int		player_pos;

	player_pos = (y * (data->width + 1) + x + 1) - 1;
	c = data->map_virus[player_pos];
	if (c == '1' || c == 'P')
		return (1);
	data->map_virus[player_pos] = 'P';
	return (0);
}

int	virus_check(t_game *map)
{
	int	valid;
	int	i;

	valid = 0;
	i = 0;
	while (map->map_virus[i])
	{
		if (map->map_virus[i] == 'E')
			valid++;
		else if (map->map_virus[i] == 'C')
			valid++;
		i++;
	}
	if (valid != 0)
		return (1);
	return (0);
}

int	virus_spread(t_game *data, int x, int y)
{
	int	left;
	int	right;
	int	down;
	int	up;

	left = check_and_infect_block(data, x - 1, y);
	right = check_and_infect_block(data, x + 1, y);
	up = check_and_infect_block(data, x, y - 1);
	down = check_and_infect_block(data, x, y + 1);
	if (right == 0)
		virus_spread(data, x + 1, y);
	if (left == 0)
		virus_spread(data, x - 1, y);
	if (down == 0)
		virus_spread(data, x, y + 1);
	if (up == 0)
		virus_spread(data, x, y - 1);
	return (0);
}

int	virus_controller(t_game *data)
{
	if (virus_spread(data, data->x_pos, data->y_pos) != 0
		|| virus_check(data) != 0)
		return (1);
	return (0);
}
