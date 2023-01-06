#include "../so_long.h"

int graphics_cache_assets(t_game *cache)
{
    void *mlx = cache->mlx;
    cache->floor = mlx_png_file_to_image(mlx, "../assets/Tile.png", 256, 256);
    cache->wall = mlx_png_file_to_image(mlx, "../assets/Grass.png", 256, 256);
    cache->exit = mlx_png_file_to_image(mlx, "../assets/Door.png", 256, 256);
    cache->item = mlx_png_file_to_image(mlx, "../assets/Collectible_Tile.png", 256, 256);
    cache->player = mlx_png_file_to_image(mlx, "../assets/Collectible_Tile.png", 256, 256);

    return 0;
}