#include "../so_long.h"

int graphics_render_tile(t_game *data)
{
    for (int b = 0; b <= data->height; b++)
    {
        for (int i = 0; i <= data->width; i++)
        {
            char block = get_block(&data, i, b);
            if (block == '1')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->floor, i * 256, b * 256);
            }
        }
    }

    return 0;
}