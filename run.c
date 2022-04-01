#include "cub3d.h"

void    change_direction(t_game *game, float rot_speed)
{
    double    old_dir_x;

    old_dir_x = game->player.dir.x;
    game->player.dir.x = game->player.dir.x * \
    cos(rot_speed) - game->player.dir.y * sin(rot_speed);
    game->player.dir.y = old_dir_x * sin(rot_speed) + \
    game->player.dir.y * cos(rot_speed);
}

void    change_plane(t_game *game, float rot_speed)
{
    double    old_plane_x;

    old_plane_x = game->player.plane.x;
    game->player.plane.x = game->player.plane.x * cos(rot_speed) - \
    game->player.plane.y * sin(rot_speed);
    game->player.plane.y = old_plane_x * sin(rot_speed) + \
    game->player.plane.y * cos(rot_speed);
}

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

float	mag_vec(t_vec *v)
{
	float hypotenuse;

	hypotenuse = sqrt((v->x * v->x) + (v->y * v->y));
	return (hypotenuse);
}

t_vec sum_vec(t_vec v1, t_vec v2)
{
	t_vec sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	return (sum);
}

void	calc_delta(t_game *game, t_vec *rayDir, t_rays *rays)
{
	rays->delta_x = 10000000;
    if (rayDir->x != 0)
        rays->delta_x = fabs(1 / rayDir->x);
    rays->delta_y = 10000000;
    if (rayDir->y != 0)
        rays->delta_y = fabs(1 / rayDir->y);
	rays->map_pos.x = (int)floor(game->player.pos.x);
	rays->map_pos.y = (int)floor(game->player.pos.y);
}

void	calc_dist(t_game *game, t_vec *rayDir, t_rays *rays)
{
	if (rayDir->x < 0)
	{
		rays->dist_x = (game->player.pos.x - rays->map_pos.x) * rays->delta_x;
		rays->step_x = -1;
	}
	else
	{
		rays->dist_x = (rays->map_pos.x + 1 - game->player.pos.x) * rays->delta_x;
		rays->step_x = 1;
	}
	if (rayDir->y < 0)
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
			rays->hit_side = 0; //horizontal
		}
		else
		{
			rays->map_pos.y += rays->step_y;
			rays->dist_y += rays->delta_y;
			rays->hit_side = 1; //vertical
		}
	}
}

void	perpendicular_dist(t_game *game, t_vec *rayDir, t_rays *rays)
{
	if (rays->hit_side == 0)
		rays->perpendicular_dist = (fabs(rays->map_pos.x - game->player.pos.x + ((1 - rays->step_x) / 2)) / rayDir->x);
	else
		rays->perpendicular_dist = (fabs(rays->map_pos.y - game->player.pos.y + ((1 - rays->step_y) / 2)) / rayDir->y);
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

int	render(t_game *game)
{
	float	multiplier;
	t_vec	cameraPixel;
	t_vec	rayDir;
	t_rays	rays;

	draw_background(game);
	change_direction(game, -0.01);
	change_plane(game, -0.01);
	for (int pixel = 0; pixel < WIDTH; pixel ++)
	{
		cameraPixel = game->player.plane;
		multiplier = 2 * (pixel / (double)WIDTH) - 1;
		vec_scale(&cameraPixel, multiplier);
		rayDir = sum_vec(cameraPixel, game->player.dir);

		//calculo dos raios e o desenho da parede
		calc_delta(game, &rayDir, &rays);
		calc_dist(game, &rayDir, &rays);
		dda(game, &rays);
		perpendicular_dist(game, &rayDir, &rays);
		get_wall_size(game, &rays, pixel);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->canvas.img, 0, 0);
}

void	run(t_game *game)
{
	mlx_loop_hook(game->mlx, &render, game);
	mlx_loop(game->mlx);
}
