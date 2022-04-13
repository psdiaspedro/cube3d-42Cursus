/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:03 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/11 15:40:47 by dalves-s         ###   ########.fr       */
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
	int trash;

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

	open_xpm_file(game, &game->img.no, "./imgs/no_redbrick.xpm");
	open_xpm_file(game, &game->img.so, "./imgs/so_redbrick.xpm");
	open_xpm_file(game, &game->img.we, "./imgs/we_redbrick.xpm");
	open_xpm_file(game, &game->img.ea, "./imgs/ea_redbrick.xpm");

}

void	init_map(t_game *game)
{
	// Put the number of map lines instead of 50
	game->map = ft_calloc(sizeof(char*), 50);
}