/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:02:57 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/05 10:19:31 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <X11/X.h>
# include "../vectors/vec.h"
# include <stdio.h>
# include <math.h>

# define WIDTH			1200
# define HEIGHT			700
# define KeyPress		2
# define KeyRelease		3
# define KeyPressMask	(1L<<0)
# define KeyReleaseMask	(1L<<1)
# define ESC 			0xff1b
# define PI 			3.141592653589f

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct s_draw{
	int	wall_line_height;
	int start_line;
	int end_line;
} t_draw;

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

typedef struct	s_player {
	t_vec		pos;
	t_vec		plane;
	t_vec		dir;
} t_player;

typedef struct s_game{
	t_player	player;
	t_buttons	buttons;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	void		*mlx;
	void		*win;
	t_data		canvas;
	int			map[10][10];
}	t_game;

void	init_game(t_game *game);
void	init_images(t_game *game);
void	run(t_game *game);
void	init_player(t_game *game);

#endif
