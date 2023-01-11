/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:37 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/11 16:15:46 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_read(t_game *map, char *file)
{
	char	*map_raw;
	char	*read_line;

	if ((map->fd = open(file, O_RDONLY)) < 0)
		return (1);
	map_raw = malloc(sizeof(char) * 1001);
	while (1)
	{
		// read_line = get_next_line(map->fd);
		// if (!read_line)
		//     break ;
		// map_raw = ft_strjoin(map_raw, read_line);
		if (read(map->fd, map_raw, 1000) == 0)
			break ;
	}
	map->map_raw_data = map_raw;
	close(map->fd);
	return (0);
}

int	map_get_size(t_game *map)
{
	char	*map_raw;
	int		i;
	int		x;
	int		x_high;
	int		y;

	map_raw = map->map_raw_data;
	i = 0;
	x = 0;
	x_high = 0;
	y = 0;
	while (map_raw[i])
	{
		if (map_raw[i] == '\n')
		{
			if (x > x_high)
				x_high = x;
			y++;
			x = 0;
		}
		else if (map_raw[i] == '1' || map_raw[i] == '0' || map_raw[i] == 'P'
				|| map_raw[i] == 'C' || map_raw[i] == 'E')
			x++;
		else
			return (1);
		i++;
	}
	map->height = y;
	map->width = x_high;
	return (0);
}

int	map_parse(t_game *map)
{
	map_get_size(map);
	return (0);
}

int	map_controller(t_game *map, char **av)
{
	if (map_read(map, av[1]) != 0)
		return (1);
	if (map_parse(map) != 0)
		return (1);
}
