#ifndef SO_LONG_H
#define SO_LONG_H

#include "./ft_printf/ft_printf.h"
#include "./ft_printf/libft/libft.h"
#include "./get_next_line/get_next_line.h"
#include "./mlx/mlx.h"
#include <fcntl.h>

typedef struct s_game
{
    void *mlx;
    void *win;
    int fd;
    char *map_raw_data;
} t_game;

int map_controller(t_game *map, char **av);

#endif