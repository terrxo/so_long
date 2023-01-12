/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:37 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/12 16:18:16 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_file_length(int fd)
{
	int		i;
	char	*buf;
	int		count;

	i = 1;
	count = 0;
	buf = malloc(sizeof(char) * (100));
	if (!buf)
		return (-1);
	while (i > 0)
	{
		i = read(fd, buf, 100);
		count += i;
	}
	free(buf);
	return (count);
}

int	map_read(t_game *map, char *file)
{
	char	*map_raw;
	int		i;

	i = 0;
	if ((map->fd = open(file, O_RDONLY)) < 0)
		return (1);
	i = get_file_length(map->fd);
	close(map->fd);
	if ((map->fd = open(file, O_RDONLY)) < 0)
		return (1);
	map_raw = ft_calloc(i + 1, 1);
	read(map->fd, map_raw, i);
	map_raw[i] = '\0';
	close(map->fd);
	map->map_raw_data = map_raw;
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
	return (0);
}
