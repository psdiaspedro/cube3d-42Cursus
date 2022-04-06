/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 10:14:48 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/06 10:45:39 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	update_frame(t_game *game)
{
	draw_background(game);
	player_rotate(game);
	player_walk_up_down(game);
	player_walk_left_right(game);
}

void	run(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
	mlx_hook(game->win, KEY_PRESS, KEY_PRESS_MASK, press_key, game);
	mlx_hook(game->win, KEY_RELEASE, KEY_RELEASE_MASK, release_key, game);
	mlx_loop(game->mlx);
}
