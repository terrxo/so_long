/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndivjak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:04:27 by ndivjak           #+#    #+#             */
/*   Updated: 2023/01/14 02:33:38 by ndivjak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./ft_printf/libft/libft.h"
# include "./mlx/mlx.h"
# include <fcntl.h>

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		fd;
	char	*map_raw_data;
	char	*map_virus;
	int		height;
	int		width;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*item;
	int		x_pos;
	int		y_pos;
	int		p_index;
	int		item_count;
	int		player_step_count;
	int		norminette_bullshit;
}			t_game;

int			map_controller(t_game *map, char **av);
int			get_block(t_game *map, int x, int y);
int			graphics_cache_assets(t_game *cache);
int			graphics_render_tile(t_game *data);
int			controls_controller(int key, t_game *data);
int			swap_player_block(t_game *data, int x, int y);
int			exit_game(t_game *data);
int			map_check_controller(t_game *map);
int			virus_controller(t_game *data);
int			is_win(t_game *data, int val);

#endif