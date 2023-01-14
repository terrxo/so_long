/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:37 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/14 02:30:50 by ndivjak          ###   ########.fr       */
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
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
		return (1);
	i = get_file_length(map->fd);
	close(map->fd);
	map->fd = open(file, O_RDONLY);
	if (map->fd < 0)
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
	int	i;
	int	x;
	int	y;

	i = -1;
	x = 0;
	map->norminette_bullshit = 0;
	y = 0;
	while (map->map_raw_data[++i])
	{
		if (map->map_raw_data[i] == '\n')
		{
			if (x > map->norminette_bullshit)
				map->norminette_bullshit = x;
			y++;
			x = 0;
		}
		else if (ft_strchr("10PCE", map->map_raw_data[i]))
			x++;
		else
			return (1);
	}
	map->height = y;
	map->width = map->norminette_bullshit;
	return (0);
}

int	map_controller(t_game *map, char **av)
{
	if (map_read(map, av[1]) != 0)
		return (1);
	if (map_get_size(map) != 0)
		return (1);
	if (map_check_controller(map) != 0)
	{
		free(map->map_raw_data);
		return (1);
	}
	return (0);
}
