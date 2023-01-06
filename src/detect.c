#include "../so_long.h"

int get_block(t_game *map, int x, int y)
{
    int max_width = map->width + 1;
    int location;
    location = (y * max_width + x + 1) - 1;
    return (map->map_raw_data[location]);
}
