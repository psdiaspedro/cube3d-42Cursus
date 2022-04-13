/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:03 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/13 08:57:34 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	open_xpm_file(t_game *game, t_data *data, char *filename)
{
	int	trash;

	data->img = mlx_xpm_file_to_image(game->mlx, filename, &trash, &trash);
	if (!data->img)
	{
		printf("alo");
		exit(0);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	return (0);
}

void	init_images(t_game *game)
{
	game->canvas.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->canvas.addr = mlx_get_data_addr(\
	game->canvas.img, &game->canvas.bits_per_pixel, \
	&game->canvas.line_length, &game->canvas.endian);

	open_xpm_file(game, &game->img.no, game->img.no.path);
	open_xpm_file(game, &game->img.so, game->img.so.path);
	open_xpm_file(game, &game->img.we, game->img.we.path);
	open_xpm_file(game, &game->img.ea, game->img.ea.path);
}
