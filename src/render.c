#include "../so_long.h"

int graphics_render_tile(t_game *data)
{
    for (int b = 0; b <= data->height; b++)
    {
        for (int i = 0; i <= data->width; i++)
        {
            char block = get_block(data, i, b);
            if (block == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall, i * 64, b * 64);
            else if (block == '0')
                mlx_put_image_to_window(data->mlx, data->floor, data->floor, i * 64, b * 64);
            else if (block == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->item, i * 64, b * 64);
            else if (block == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit, i * 64, b * 64);
            else if (block == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player, i * 64, b * 64);
        }
    }

    return 0;
}