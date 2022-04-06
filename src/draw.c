/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:00:54 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/05 14:06:04 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int offset = (y * data->line_length + x * (data->bits_per_pixel / 8));

	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}

int	get_pixel(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (((int)y) * data->line_length + (int)x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

void	draw_background(t_game *game)
{
	for(int coluna = 0; coluna < WIDTH; coluna++)
	{
		for (int linha = 0; linha < HEIGHT; linha++)
		{
			if (linha < HEIGHT / 2)
				my_mlx_pixel_put(&game->canvas,  coluna, linha, 211211211);
			else
				my_mlx_pixel_put(&game->canvas, coluna, linha, 210211211);
		}
	}
}

void	get_wall_size(t_game *game, t_rays *rays, int pixel)
{
	t_draw draw;

	draw.wall_line_height = fabs(HEIGHT / rays->perpendicular_dist);
	draw.start_line = HEIGHT / 2 - draw.wall_line_height / 2;
	if (draw.start_line < 0)
		draw.start_line = 0;
	draw.end_line = HEIGHT / 2 + draw.wall_line_height / 2;
	if (draw.end_line >= HEIGHT)
		draw.end_line = HEIGHT - 1;
	int sl = draw.start_line;
	while (sl < draw.end_line)
	{
		if (rays->hit_side == 0)
			my_mlx_pixel_put(&game->canvas, pixel, sl, 0XFF00);
		else
			my_mlx_pixel_put(&game->canvas, pixel, sl, 0X101000);
		sl++;
	}
}
