#include "../so_long.h"

int	spread_virus(t_game *map, char *virus)
{
}

int	check_virus(t_game *map, char *virus)
{
}

int	check_sprites(t_game *map)
{
	int	player;
	int	item;
	int	exit;
	int	i;

	player = 0;
	item = 0;
	exit = 0;
	i = 0;
	while (map->map_raw_data[i])
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
		i++;
	}
	if (player != 1 || exit != 1 || item == 0)
		return (1);
	return (0);
}

int	check_walls(t_game *map)
{
	int		i;
	char	c;

	i = 0;
	while (i < map->width)
		if (get_block(map, i, 0) != '1' || get_block(map, i++, map->height
				- 1) != '1')
			return (1);
	i = 0;
	while (i < map->height)
	{
		if ((c = get_block(map, 0, i) != '1') || (c = get_block(map, map->width
					- 1, i++)) != '1')
			return (1);
	}
	return (0);
}

int	map_check_controller(t_game *map)
{
	char	*virus;

	if (check_walls(map) != 0 || check_sprites(map) != 0)
		return (1);
	map->y_pos = map->p_index / (map->width + 1);
	map->x_pos = map->p_index % (map->width + 1);
	printf("Index: %i, val: %c, Block_val: %c x: %i, y: %i\n", map->p_index,
			map->map_raw_data[map->p_index], get_block(map, map->x_pos,
				map->y_pos), map->x_pos, map->y_pos);
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
