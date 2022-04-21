/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:05:54 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/20 10:23:56 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_path(t_game *game)
{
	int	fd;

	game->ccolor = get_rgb(game->ceil_color);
	game->fcolor = get_rgb(game->floor_color);
	if (!game->fcolor || !game->ccolor)
		return (0);
	fd = open(game->img.ea.path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(game->fd);
	fd = open(game->img.no.path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(game->fd);
	fd = open(game->img.so.path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(game->fd);
	fd = open(game->img.we.path, O_RDONLY);
	if (fd < 0)
		return (0);
	close(game->fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!get_map_struct(argc, argv, &game, 0))
		return (1);
	if (!check_map_struct(&game, 0, 0))
	{
		ft_putendl_fd("Error\nMap must be surrounded by walls! :(", 2);
		free_all(&game);
		return (1);
	}
	if (!check_path(&game))
	{
		ft_putendl_fd("Error\nInvalid path! :(", 2);
		free_all(&game);
		return (1);
	}
	init_player(&game);
	init_game(&game);
	if (!init_images(&game))
		return (1);
	run(&game);
	free_all(&game);
	return (0);
}
