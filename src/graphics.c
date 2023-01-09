/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:20 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/09 14:06:33 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	graphics_cache_assets(t_game *cache)
{
	int		i;
	int		j;
	void	*mlx;

	mlx = cache->mlx;
	cache->floor = mlx_xpm_file_to_image(mlx, "assets/Tile.xpm", &i, &j);
	cache->wall = mlx_xpm_file_to_image(mlx, "assets/Grass.xpm", &i, &j);
	cache->exit = mlx_xpm_file_to_image(mlx, "assets/Door_Tile.xpm", &i, &j);
	cache->item = mlx_xpm_file_to_image(mlx, "assets/Collectible_Tile.xpm", &i,
			&j);
	cache->player = mlx_xpm_file_to_image(mlx, "assets/Collectible_Tile.xpm",
			&i, &j);
	return (0);
}
