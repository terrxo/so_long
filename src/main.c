#include "../so_long.h"

int init_mlxwindow(t_game *window)
{
    window->mlx = mlx_init();
    window->win = mlx_new_window(window->mlx, 640, 360, "So Loooooong");
    return 0;
}

int main(int ac, char **av)
{
    t_game data;

    if (ac != 2)
        return (ft_printf("Error: number of arguments incorrect."));
    map_controller(&data, av);
    init_mlxwindow(&data);
    mlx_loop(data.mlx);

    return 0;
}
