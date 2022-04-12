/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:00:54 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/11 21:40:01 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_data *data, t_vec point, int color)
{
	char	*dst;

	dst = data->addr + (((int)point.y) * data->line_length + ((int)point.x) \
	* (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_pixel(t_data *data, t_vec point)
{
	char	*dst;

	dst = data->addr + (((int)point.y) * data->line_length + ((int)point.x) \
	* (data->bits_per_pixel / 8));
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
				my_mlx_pixel_put(&game->canvas, (t_vec){.x = col, .y = row}, \
				211211211);
			else
				my_mlx_pixel_put(&game->canvas, (t_vec){.x = col, .y = row}, \
				210211211);
			row++;
		}
		col++;
	}
}
