/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:43:32 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/09 16:36:56 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	controls_player_move(t_game *data, int key)
{
	int	val;

	ft_printf("Checking player pos");
	if (key == 1)
	{
		val = get_block(data, data->x_pos, data->y_pos - 1);
		if (val == '0')
		{
			printf("Shit is floor");
			mlx_put_image_to_window(data->mlx, data->win, data->floor,
					data->x_pos * 64, data->y_pos * 64);
			mlx_put_image_to_window(data->mlx, data->win, data->player,
					data->x_pos * 64, data->y_pos - 1 * 64);
		}
	}
	return (0);
}

int	controls_controller(int key, t_game *data)
{
	int is_error;
	//Exit game
	ft_printf("Key: %i\n", key);
	if (key == 53)
		;
	else if (key == 13)
		is_error = controls_player_move(data, key);
	return (0);
}