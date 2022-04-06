/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:45:00 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/06 12:08:05 by paugusto         ###   ########.fr       */
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

int	render(t_game *game)
{
	t_rays	rays;
	int		pixel;

	update_frame(game);
	pixel = -1;
	while (++pixel < WIDTH)
		raycasting(game, &rays, pixel);
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.img, 0, 0);
}
