#include "cub3d.h"

void	init_player(t_game *game)
{
	game->player.pos.x = 4;
	game->player.pos.y = 5;
	game->player.dir.x = 0;
	game->player.dir.y = -1;
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "raycasting");
}

void	init_images(t_game *game)
{
	game->canvas.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->canvas.addr = mlx_get_data_addr(game->canvas.img, &game->canvas.bits_per_pixel, &game->canvas.line_length, &game->canvas.endian);
}
