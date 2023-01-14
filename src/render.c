/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:23 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/14 02:11:11 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	graphics_choose_specific_tile(t_game *data, char block, int i, int b)
{
	if (block == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall, i * 64, b
			* 64);
	else if (block == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->floor, i * 64, b
			* 64);
	else if (block == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->item, i * 64, b
			* 64);
	else if (block == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->exit, i * 64, b
			* 64);
	else if (block == 'P')
		mlx_put_image_to_window(data->mlx, data->win, data->player, i * 64, b
			* 64);
}

int	graphics_render_tile(t_game *data)
{
	int		b;
	int		i;
	char	block;

	b = 0;
	while (b <= data->height)
	{
		i = 0;
		while (i <= data->width)
		{
			block = get_block(data, i, b);
			graphics_choose_specific_tile(data, block, i, b);
			i++;
		}
		b++;
	}
	return (0);
}
