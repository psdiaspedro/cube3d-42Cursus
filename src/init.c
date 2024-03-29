/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:06:03 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/26 11:04:22 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_no_player(t_game *game)
{
	free_all(game);
	ft_putendl_fd("Error\nGame must have a player", 2);
	exit(0);
}

void	init_player(t_game *game)
{
	int	y;
	int	x;

	game->player.pos.y = -1.0f;
	game->player.pos.x = -1.0f;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N')
				north(game, x, y);
			if (game->map[y][x] == 'S')
				south(game, x, y);
			if (game->map[y][x] == 'E')
				east(game, x, y);
			if (game->map[y][x] == 'W')
				west(game, x, y);
			x++;
		}
		y++;
	}
	if (game->player.pos.y == -1.0f || game->player.pos.x == -1.0f)
		error_no_player(game);
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
		free_all(game);
		ft_putendl_fd("Error\nImage doesn't exist", 2);
		exit(0);
	}
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	return (FALSE);
}

int	init_images(t_game *game)
{
	game->canvas.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->canvas.addr = mlx_get_data_addr(\
	game->canvas.img, &game->canvas.bits_per_pixel, \
	&game->canvas.line_length, &game->canvas.endian);
	open_xpm_file(game, &game->img.no, game->img.no.path);
	open_xpm_file(game, &game->img.so, game->img.so.path);
	open_xpm_file(game, &game->img.we, game->img.we.path);
	open_xpm_file(game, &game->img.ea, game->img.ea.path);
	return (TRUE);
}
