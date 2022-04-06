//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:02:02 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/05 14:08:40 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	calc_delta(t_game *game, t_vec *ray_dir, t_rays *rays)
{
	rays->delta_x = 10000000;
    if (ray_dir->x != 0)
        rays->delta_x = fabs(1 / ray_dir->x);
    rays->delta_y = 10000000;
    if (ray_dir->y != 0)
        rays->delta_y = fabs(1 / ray_dir->y);
	rays->map_pos.x = (int)floor(game->player.pos.x);
	rays->map_pos.y = (int)floor(game->player.pos.y);
}

void	calc_dist(t_game *game, t_vec *ray_dir, t_rays *rays)
{
	if (ray_dir->x < 0)
	{
		rays->dist_x = (game->player.pos.x - rays->map_pos.x) * rays->delta_x;
		rays->step_x = -1;
	}
	else
	{
		rays->dist_x = (rays->map_pos.x + 1 - game->player.pos.x) * rays->delta_x;
		rays->step_x = 1;
	}
	if (ray_dir->y < 0)
	{
		rays->dist_y = (game->player.pos.y - rays->map_pos.y) * rays->delta_y;
		rays->step_y = -1;
	}
	else
	{
		rays->step_y = 1;
		rays->dist_y = (rays->map_pos.y + 1 - game->player.pos.y) * rays->delta_y;
	}
}

void	dda(t_game *game, t_rays *rays)
{

	while (game->map[rays->map_pos.y][rays->map_pos.x] == 0)
	{
		if (rays->dist_x < rays->dist_y)
		{
			rays->map_pos.x += rays->step_x;
			rays->dist_x += rays->delta_x;
			rays->hit_side = 0;
		}
		else
		{
			rays->map_pos.y += rays->step_y;
			rays->dist_y += rays->delta_y;
			rays->hit_side = 1;
		}
	}
}

void	perpendicular_dist(t_game *game, t_vec *ray_dir, t_rays *rays)
{
	if (rays->hit_side == 0)
		rays->perpendicular_dist = (fabs(rays->map_pos.x - game->player.pos.x + ((1 - rays->step_x) / 2)) / ray_dir->x);
	else
		rays->perpendicular_dist = (fabs(rays->map_pos.y - game->player.pos.y + ((1 - rays->step_y) / 2)) / ray_dir->y);
}

void	raycasting(t_game *game, t_rays *rays, int pixel)
{
	float	multiplier;
	t_vec	camera_pixel;
	t_vec	ray_dir;

	camera_pixel = game->player.plane;
	multiplier = 2 * (pixel / (double)WIDTH) - 1;
	vec_scale(&camera_pixel, multiplier);
	ray_dir = sum_vec(camera_pixel, game->player.dir);
	calc_delta(game, &ray_dir, rays);
	calc_dist(game, &ray_dir, rays);
	dda(game, rays);
	perpendicular_dist(game, &ray_dir, rays);
	get_wall_size(game, rays, pixel);
}
