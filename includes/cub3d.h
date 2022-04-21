/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:02:57 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/20 09:30:14 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <X11/X.h>
# include "../vectors/vec.h"
# include <stdio.h>
# include <libft.h>
# include <math.h>
# include <fcntl.h>

# define RIGHT_ARROW		65363
# define LEFT_ARROW			65361
# define WIDTH				1200
# define HEIGHT				700
# define ESC				0xff1b
# define PI					3.141592653589f
# define TEX_WIDTH			64
# define TEX_HEIGHT			64
# define MAP_WIDTH			24
# define MAP_HEIGHT			24
# define FLOOR				'0'
# define WALL				'1'

typedef struct s_data {
	void	*img;
	char	*addr;
	char	*path;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_img {
	t_data	no;
	t_data	so;
	t_data	we;
	t_data	ea;
}	t_img;

typedef struct s_draw{
	int		wall_line_height;
	int		start_line;
	int		end_line;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
	t_data	*data;
}	t_draw;

typedef struct s_buttons
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	exit;
	int	rotate_right;
	int	rotate_left;
	int	function;
}	t_buttons;

typedef struct s_rays{
	t_int_vec	map_pos;
	double		delta_x;
	double		delta_y;
	double		dist_x;
	double		dist_y;
	double		perpendicular_dist;
	int			rays;
	int			hit_side;
	int			step_x;
	int			step_y;
}	t_rays;

typedef struct s_player {
	t_vec		pos;
	t_vec		plane;
	t_vec		dir;
}	t_player;

typedef struct s_game{
	t_player	player;
	t_buttons	buttons;
	t_img		img;
	void		*mlx;
	int			fd;
	void		*win;
	char		**map;
	char		*floor_color;
	char		*ceil_color;
	int			ccolor;
	int			fcolor;
	char		*aux;
	char		*temp;
	char		*map_line;
	t_data		canvas;
}	t_game;

//Map and structure initializers
int		get_map_struct(int argc, char **argv, t_game *game, int numb_lines);
int		check_repetition(t_game *game, char **mat);
void	get_map(char **map, char *aux);
int		map_validation(int argc, t_game *game, char *address);
int		check_map_struct(t_game *game, int line, int column);
int		check_wall(t_game *game, int line, int column);
int		check_front(t_game *game, int line, int column);
int		check_back(t_game *game, int line, int column);
int		check_up(t_game *game, int line, int column);
int		check_bottom(t_game *game, int line, int column);
int		get_rgb(char *color);

//Program initializers
void	init_map(t_game *game);
void	init_game(t_game *game);
int		init_images(t_game *game);
void	init_player(t_game *game);
void	run(t_game *game);

//Release and end the program
void	free_all(t_game *game);
void	free_matrix(char **mat);
void	free_map_vars(char **map, char **aux, char **temp);
int		kill_window(t_game *game);

//player player_movement
void	change_direction(t_game *game, float rot_speed);
void	change_plane(t_game *game, float rot_speed);
void	player_rotate(t_game *game);
void	player_walk_left_right(t_game *game);
void	player_walk_up_down(t_game *game);

//vectors
float	mag_vec(t_vec *v);
t_vec	sum_vec(t_vec v1, t_vec v2);

//draw pixel
void	my_mlx_pixel_put(t_data *data, t_vec point, int color);
int		get_pixel(t_data *data, t_vec point);
void	draw_background(t_game *game);
void	get_wall_size(t_game *game, t_vec *ray_dir, t_rays *rays, int pixel);

//raycasting algorithm
void	calc_delta(t_game *game, t_vec *rayDir, t_rays *rays);
void	calc_dist(t_game *game, t_vec *rayDir, t_rays *rays);
void	dda(t_game *game, t_rays *rays);
void	perpendicular_dist(t_game *game, t_vec *rayDir, t_rays *rays);
void	raycasting(t_game *game, t_rays *rays, int pixel);

//hooks
int		press_key(int key_code, t_game *game);
int		release_key(int key_code, t_game *game);

//render
int		render(t_game *game);

//update
void	update_frame(t_game *game);

//player directions
void	north(t_game *game, int x, int y);
void	south(t_game *game, int x, int y);
void	east(t_game *game, int x, int y);
void	west(t_game *game, int x, int y);

//map
int		check_map_struct(t_game *game, int line, int column);
int		check_wall(t_game *game, int line, int column);

#endif
