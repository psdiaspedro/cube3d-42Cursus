/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:37:49 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/07 13:37:57 by paugusto         ###   ########.fr       */
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
