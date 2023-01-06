#include "../so_long.h"

int map_read(t_game *map, char *file)
{
    char *map_raw;
    char *read_line;

    if ((map->fd = open(file, O_RDONLY)) < 0)
        return 1;
    while (1)
    {
        read_line = get_next_line(map->fd);
        if (!read_line)
            break;
        map_raw = ft_strjoin(map_raw, read_line);
    }
    map->map_raw_data = map_raw;
    printf("Map data:\n%s", map->map_raw_data);
    return 0;
}

int map_parse(t_game *map, char *map_raw)
{
    return 0;
}

int map_controller(t_game *map, char **av)
{
    if (map_read(map, av[1]) != 0)
        return 1;
}
