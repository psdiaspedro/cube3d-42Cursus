/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:05:54 by dalves-s          #+#    #+#             */
/*   Updated: 2022/05/04 11:18:56 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_path(t_game *game)
{
	int	fd;

	game->ccolor = get_rgb(game->ceil_color);
	game->fcolor = get_rgb(game->floor_color);
	if (game->fcolor == -1 || game->ccolor == -1)
		return (FALSE);
	fd = open(game->img.ea.path, O_RDWR);
	if (fd == -1)
		return (FALSE);
	close(fd);
	fd = open(game->img.no.path, O_RDWR);
	if (fd == -1)
		return (FALSE);
	close(fd);
	fd = open(game->img.so.path, O_RDWR);
	if (fd == -1)
		return (FALSE);
	close(fd);
	fd = open(game->img.we.path, O_RDWR);
	if (fd == -1)
		return (FALSE);
	close(fd);
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!get_map_struct(argc, argv, &game))
	{
		free_all(&game);
		return (TRUE);
	}
	if (!check_map_struct(&game, 0, 0))
		return (TRUE);
	if (!check_path(&game))
	{
		ft_putendl_fd("Error\nInvalid path! :(", 2);
		free_all(&game);
		return (TRUE);
	}
	init_player(&game);
	init_game(&game);
	if (!init_images(&game))
		return (TRUE);
	run(&game);
	free_all(&game);
	return (FALSE);
}
