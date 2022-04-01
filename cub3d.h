#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <X11/X.h>
# include "./vectors/vec.h"
# include <stdio.h>
# include <math.h>

# define WIDTH 1200
# define HEIGHT 700

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
