#include "../so_long.h"

int	check_and_infect_block(t_game *data, int x, int y)
{
	char	c;
	int		player_pos;

	c = get_block(data, x, y);
	if (c == '1' || c == '2')
		return (1);
	player_pos = (y * (data->width + 1) + x + 1) - 1;
	data->map_virus[player_pos] = '2';
	return (0);
}

int	virus_spread(t_game *data, int x, int y)
{
	ft_printf("%s\n\n", data->map_virus);
	if (check_and_infect_block(data, x, y) == 1)
		return (0);
	virus_spread(data, x + 1, y);
	virus_spread(data, x, y + 1);
	virus_spread(data, x - 1, y);
	virus_spread(data, x, y - 1);
	return (0);
}

int	virus_controller(t_game *data)
{
	if (virus_spread(data, data->x_pos, data->y_pos) != 0)
		return (0);
	ft_printf("Map:\n%s", data->map_virus);
	return (0);
}