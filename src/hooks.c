/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:38:53 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/28 10:42:00 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	press_key(int key_code, t_game *game)
{
	if (key_code == 'w')
		game->buttons.up = 1;
	if (key_code == 'a')
		game->buttons.left = 1;
	if (key_code == 's')
		game->buttons.down = 1;
	if (key_code == 'd')
		game->buttons.right = 1;
	if (key_code == ' ')
		game->buttons.function = 1;
	if (key_code == ESC)
	{
		game->buttons.exit = 1;
		kill_window(game);
	}
	if (key_code == RIGHT_ARROW)
		game->buttons.rotate_right = 1;
	if (key_code == LEFT_ARROW)
		game->buttons.rotate_left = 1;
	return (0);
}

int	release_key(int key_code, t_game *game)
{
	if (key_code == 'w')
		game->buttons.up = 0;
	if (key_code == 'a')
		game->buttons.left = 0;
	if (key_code == 's')
		game->buttons.down = 0;
	if (key_code == 'd')
		game->buttons.right = 0;
	if (key_code == ' ')
		game->buttons.function = 0;
	if (key_code == ESC)
		game->buttons.exit = 0;
	if (key_code == RIGHT_ARROW)
		game->buttons.rotate_right = 0;
	if (key_code == LEFT_ARROW)
		game->buttons.rotate_left = 0;
	return (0);
}
