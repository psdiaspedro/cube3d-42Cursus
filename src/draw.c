/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:00:54 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/07 13:45:30 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int *)dst = color;
}

int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (((int)y) * data->line_length + (int)x * \
	(data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	draw_background(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (col < WIDTH)
	{
		row = 0;
		while (row < HEIGHT)
		{
			if (row < HEIGHT / 2)
				my_mlx_pixel_put(&game->canvas, col, row, 211211211);
			else
				my_mlx_pixel_put(&game->canvas, col, row, 210211211);
			row++;
		}
		col++;
	}
}

void	get_wall_size(t_game *game, t_rays *rays, int pixel)
{
	t_draw	draw;
	int		sl;

	draw.wall_line_height = fabs(HEIGHT / rays->perpendicular_dist);
	draw.start_line = HEIGHT / 2 - draw.wall_line_height / 2;
	if (draw.start_line < 0)
		draw.start_line = 0;
	draw.end_line = HEIGHT / 2 + draw.wall_line_height / 2;
	if (draw.end_line >= HEIGHT)
		draw.end_line = HEIGHT - 1;
	sl = draw.start_line;
	while (sl < draw.end_line)
	{
		if (rays->hit_side == 0)
			my_mlx_pixel_put(&game->canvas, pixel, sl, 0XFF00);
		else
			my_mlx_pixel_put(&game->canvas, pixel, sl, 0X101000);
		sl++;
	}
}
