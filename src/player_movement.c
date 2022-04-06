/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:32:16 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/05 13:57:13 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	player_walk_up_down(t_game *game)
{
	t_vec	velocity;
	int		speed;

	speed = 5;
	velocity = game->player.dir;
	if (game->buttons.up)
		vec_scale(&velocity, 0.1f);
	else if (game->buttons.down)
		vec_scale(&velocity, -0.1f);
	else
		vec_scale(&velocity, 0);
	if (game->map[(int)game->player.pos.y] \
	[(int)(game->player.pos.x + velocity.x * 5)] == 0)
		game->player.pos.x += velocity.x;
	if (game->map[(int)(game->player.pos.y + velocity.y * 5)] \
	[(int)game->player.pos.x] == 0)
		game->player.pos.y += velocity.y;
}

void	player_walk_left_right(t_game *game)
{
	t_vec	strafe_velocity;
	double	old_dir_x;

	strafe_velocity = game->player.dir;
	old_dir_x = strafe_velocity.x;
	strafe_velocity.x = strafe_velocity.x * cos(PI / 2) - \
	strafe_velocity.y * sin(PI / 2);
	strafe_velocity.y = old_dir_x * sin(PI / 2) + strafe_velocity.y * \
	cos(PI / 2);
	if (game->buttons.right)
		vec_scale(&strafe_velocity, 0.1f);
	else if (game->buttons.left)
		vec_scale(&strafe_velocity, -0.1f);
	else
		vec_scale(&strafe_velocity, 0);
	if (game->map[(int)game->player.pos.y] \
	[(int)(game->player.pos.x + strafe_velocity.x * 5)] == 0)
		game->player.pos.x += strafe_velocity.x;
	if (game->map[(int)(game->player.pos.y + strafe_velocity.y * 5)] \
	[(int)game->player.pos.x] == 0)
		game->player.pos.y += strafe_velocity.y;
}

void	player_rotate(t_game *game)
{
	float	rot_speed;

	if (game->buttons.rotate_right)
		rot_speed = 0.1f;
	else if (game->buttons.rotate_left)
		rot_speed = -0.1f;
	else
		rot_speed = 0;
	if (game->buttons.rotate_right && game->buttons.rotate_left)
		rot_speed = 0;
	if (rot_speed)
	{
		change_direction(game, rot_speed);
		change_plane(game, rot_speed);
	}
}

void	change_direction(t_game *game, float rot_speed)
{
	double	old_dir_x;

	old_dir_x = game->player.dir.x;
	game->player.dir.x = game->player.dir.x * \
	cos(rot_speed) - game->player.dir.y * sin(rot_speed);
	game->player.dir.y = old_dir_x * sin(rot_speed) + \
	game->player.dir.y * cos(rot_speed);
}

void	change_plane(t_game *game, float rot_speed)
{
	double	old_plane_x;

	old_plane_x = game->player.plane.x;
	game->player.plane.x = game->player.plane.x * cos(rot_speed) - \
	game->player.plane.y * sin(rot_speed);
	game->player.plane.y = old_plane_x * sin(rot_speed) + \
	game->player.plane.y * cos(rot_speed);
}
