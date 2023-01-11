/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 15:43:32 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/10 14:23:57 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_win(t_game *data, int val)
{
	if (data->item_count == 0)
		return (1);
	return (0);
}

int	controls_up(t_game *data)
{
	int	val;

	val = get_block(data, data->x_pos, data->y_pos - 1);
	if (val == '0' || val == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor, data->x_pos
				* 64, data->y_pos * 64);
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->x_pos
				* 64, (data->y_pos - 1) * 64);
		swap_player_block(data, data->x_pos, data->y_pos - 1);
		ft_printf("Steps taken: %i\n", ++data->player_step_count);
	}
	if (val == 'E' && is_win(data, val))
		return (42);
	if (val == 'C')
		data->item_count--;
	return (0);
}

int	controls_down(t_game *data)
{
	int	val;

	val = get_block(data, data->x_pos, data->y_pos + 1);
	if (val == '0' || val == 'C')
	{
		ft_printf("Steps taken: %i\n", ++data->player_step_count);
		mlx_put_image_to_window(data->mlx, data->win, data->floor, data->x_pos
				* 64, data->y_pos * 64);
		mlx_put_image_to_window(data->mlx, data->win, data->player, data->x_pos
				* 64, (data->y_pos + 1) * 64);
		swap_player_block(data, data->x_pos, data->y_pos + 1);
	}
	if (val == 'E' && is_win(data, val))
		return (42);
	if (val == 'C')
		data->item_count--;
	return (0);
}

int	controls_left(t_game *data)
{
	int	val;

	val = get_block(data, data->x_pos - 1, data->y_pos);
	if (val == '0' || val == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor, data->x_pos
				* 64, data->y_pos * 64);
		mlx_put_image_to_window(data->mlx, data->win, data->player, (data->x_pos
					- 1) * 64, data->y_pos * 64);
		swap_player_block(data, data->x_pos - 1, data->y_pos);
		ft_printf("Steps taken: %i\n", ++data->player_step_count);
	}
	if (val == 'E' && is_win(data, val))
		return (42);
	if (val == 'C')
		data->item_count--;
	return (0);
}

int	controls_right(t_game *data)
{
	int	val;

	val = get_block(data, data->x_pos + 1, data->y_pos);
	if (val == '0' || val == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->floor, data->x_pos
				* 64, data->y_pos * 64);
		mlx_put_image_to_window(data->mlx, data->win, data->player, (data->x_pos
					+ 1) * 64, data->y_pos * 64);
		swap_player_block(data, data->x_pos + 1, data->y_pos);
		ft_printf("Steps taken: %i\n", ++data->player_step_count);
	}
	if (val == 'E' && is_win(data, val))
		return (42);
	if (val == 'C')
		data->item_count--;
	return (0);
}

int	controls_controller(int key, t_game *data)
{
	int	is_error;

	is_error = 0;
	if (key == 53)
		exit_game(data);
	else if (key == 13)
		is_error = controls_up(data);
	else if (key == 1)
		is_error = controls_down(data);
	else if (key == 0)
		is_error = controls_left(data);
	else if (key == 2)
		is_error = controls_right(data);
	if (is_error == 42)
		exit_game(data);
	return (0);
}
