/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:27 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/09 14:05:47 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./mlx/mlx.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		fd;
	char	*map_raw_data;
	int		height;
	int		width;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*item;
	int		x_pos;
	int		y_pos;
	int		item_count;
	int		item_max;
}			t_game;

int			map_controller(t_game *map, char **av);
int			get_block(t_game *map, int x, int y);
int			graphics_cache_assets(t_game *cache);
int			graphics_render_tile(t_game *data);

#endif