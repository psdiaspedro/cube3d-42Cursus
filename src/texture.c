/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:08:53 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/28 10:43:00 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

//texel = texture pixel

/*
	- para a versão texturisada o core é o mesmo com diferença
	no final com um codigo a mais.

	- um loop no eixo y é necessario para passar por cada pixel para determinar
	qual texel da textura deve ser usado

	- cada pixel tem que ser desenhado separado


*/

void	solve_mirror(t_vec *ray_dir, t_rays *rays, t_draw *draw)
{
	if (rays->hit_side == 0 && ray_dir->x < 0)
		draw->tex_x = TEX_WIDTH - draw->tex_x - 1;
	if (rays->hit_side == 1 && ray_dir->y > 0)
		draw->tex_x = TEX_WIDTH - draw->tex_x - 1;
}

//pega a cordenada x da textura, que permanece a mesma
void	get_texture_x(t_game *game, t_vec *ray_dir, t_draw *draw, t_rays *rays)
{
	double	wall_x;

	if (rays->hit_side == 0)
	{
		if (ray_dir->x > 0)
			wall_x = fabs(game->player.pos.y + rays->perpendicular_dist \
			* ray_dir->y);
		else
			wall_x = fabs(game->player.pos.y - rays->perpendicular_dist \
			* ray_dir->y);
	}
	else
	{
		if (ray_dir->y > 0)
			wall_x = fabs(game->player.pos.x + rays->perpendicular_dist \
			* ray_dir->x);
		else
			wall_x = fabs(game->player.pos.x - rays->perpendicular_dist \
			* ray_dir->x);
	}
	wall_x -= floor(wall_x);
	draw->tex_x = (int)(wall_x * (double)TEX_WIDTH);
	solve_mirror(ray_dir, rays, draw);
}

t_data	*get_texture(t_game *game, t_vec *ray_dir, t_rays *rays)
{
	if (game->map[rays->map_pos.y][rays->map_pos.x] == WALL)
	{
		if (rays->hit_side == 0 && ray_dir->x > 0)
			return (&game->img.ea);
		if (rays->hit_side == 0 && ray_dir->x < 0)
			return (&game->img.we);
		if (rays->hit_side == 1 && ray_dir->y > 0)
			return (&game->img.so);
		if (rays->hit_side == 1 && ray_dir->y < 0)
			return (&game->img.no);
	}
	return ((t_data *)0);
}

/*
	agora que ja temos o x, precisamos de um loop no y
	(pois o x permanece o mesmo) tex_y
*/
void	get_texture_y(t_game *game, t_vec *ray_dir, t_draw *draw, t_rays *rays)
{
	int	sl;
	int	color;

	draw->step = 1 * TEX_HEIGHT / draw->wall_line_height;
	draw->tex_pos = (draw->start_line - HEIGHT / 2 \
	+ draw->wall_line_height / 2) * draw->step;
	draw->data = get_texture(game, ray_dir, rays);
	sl = draw->start_line;
	while (sl < draw->end_line)
	{
		draw->tex_y = (int)draw->tex_pos & (TEX_HEIGHT - 1);
		draw->tex_pos += draw->step;
		color = get_pixel(draw->data, \
		(t_vec){.x = draw->tex_x, .y = draw->tex_y});
		if (rays->hit_side == 1)
			color = 65280;
		my_mlx_pixel_put(&game->canvas, \
		(t_vec){.x = rays->rays, .y = sl}, color);
		sl++;
	}
}

void	get_wall_size(t_game *game, t_vec *ray_dir, t_rays *rays, int pixel)
{
	t_draw	draw;
	int		sl;
	int		color;

	draw.wall_line_height = fabs(HEIGHT / rays->perpendicular_dist);
	draw.start_line = HEIGHT / 2 - draw.wall_line_height / 2;
	if (draw.start_line < 0)
		draw.start_line = 0;
	draw.end_line = HEIGHT / 2 + draw.wall_line_height / 2;
	if (draw.end_line >= HEIGHT)
		draw.end_line = HEIGHT - 1;
	get_texture_x(game, ray_dir, &draw, rays);
	draw.step = 1.0f * TEX_HEIGHT / draw.wall_line_height;
	draw.tex_pos = (draw.start_line - HEIGHT / 2 \
	+ draw.wall_line_height / 2) * draw.step;
	draw.data = get_texture(game, ray_dir, rays);
	sl = draw.start_line;
	while (sl < draw.end_line)
	{
		draw.tex_y = (int)draw.tex_pos & (TEX_HEIGHT - 1);
		draw.tex_pos += draw.step;
		color = get_pixel(draw.data, (t_vec){.x = draw.tex_x, .y = draw.tex_y});
		my_mlx_pixel_put(&game->canvas, (t_vec){.x = pixel, .y = sl}, color);
		sl++;
	}
}
