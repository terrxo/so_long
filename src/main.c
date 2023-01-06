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
    for (int b = 0; b <= data.height; b++)
    {
        for (int i = 0; i <= data.width; i++)
            printf("x:%i  y:%i  Val:%c\n", i, b, get_block(&data, i, b));
    }
    init_mlxwindow(&data);
    mlx_loop(data.mlx);

    return 0;
}
