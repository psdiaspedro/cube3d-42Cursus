/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:14:48 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/14 08:50:34 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	kill_window(t_game *game)
{
	free_all(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}

void	run(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
	mlx_hook(game->win, 2, (1L << 0), press_key, game);
	mlx_hook(game->win, 3, (1L << 1), release_key, game);
	mlx_hook(game->win, 17, 0L, kill_window, game);
	mlx_loop(game->mlx);
}
