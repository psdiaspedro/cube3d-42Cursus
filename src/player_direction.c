/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_direction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 10:17:55 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/14 11:48:43 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	north(t_game *game, int x, int y)
{
	if (game->player.pos.y != -1.0f || game->player.pos.x != -1.0f)
	{
		free_all(game);
		ft_putendl_fd("Error\nGame must have just one player", 2);
		exit(0);
	}
	game->player.pos.y = y + 0.5f;
	game->player.pos.x = x + 0.5f;
	game->player.dir.y = -1;
	game->player.dir.x = 0;
	game->player.plane.x = 0.66;
	game->player.plane.y = 0;
	game->map[y][x] = FLOOR;
}

void	south(t_game *game, int x, int y)
{
	if (game->player.pos.y != -1.0f || game->player.pos.x != -1.0f)
	{
		free_all(game);
		ft_putendl_fd("Error\nGame must have just one player", 2);
		exit(0);
	}
	game->player.pos.y = y + 0.5f;
	game->player.pos.x = x + 0.5f;
	game->player.dir.y = 1;
	game->player.dir.x = 0;
	game->player.plane.x = -0.66;
	game->player.plane.y = 0;
	game->map[y][x] = FLOOR;
}

void	east(t_game *game, int x, int y)
{
	if (game->player.pos.y != -1.0f || game->player.pos.x != -1.0f)
	{
		free_all(game);
		ft_putendl_fd("ERROR\nGame must have just one player", 2);
		exit(0);
	}
	game->player.pos.y = y + 0.5f;
	game->player.pos.x = x + 0.5f;
	game->player.dir.y = 0;
	game->player.dir.x = 1;
	game->player.plane.x = 0;
	game->player.plane.y = 0.66;
	game->map[y][x] = FLOOR;
}

void	west(t_game *game, int x, int y)
{
	if (game->player.pos.y != -1.0f || game->player.pos.x != -1.0f)
	{
		free_all(game);
		ft_putendl_fd("Error\nGame must have just one player", 2);
		exit(0);
	}
	game->player.pos.y = y + 0.5f;
	game->player.pos.x = x + 0.5f;
	game->player.dir.y = 0;
	game->player.dir.x = -1;
	game->player.plane.x = 0;
	game->player.plane.y = -0.66;
	game->map[y][x] = FLOOR;
}
