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

int	virus_spread(t_game *data, int x, int y)
{
	int left, right, down, up;
	ft_printf("%s\n\n", data->map_virus);
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
	if (virus_spread(data, data->x_pos, data->y_pos) != 0)
		return (0);
	ft_printf("Map:\n%s", data->map_virus);
	return (0);
}