/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:37:24 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/26 12:05:53 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_map_struct(t_game *game, int line, int column)
{
	while (game->map[line])
	{
		column = 0;
		while (game->map[line][column] == ' ' || game->map[line][column] == '1')
		{
			column++;
		}
		while (game->map[line][column])
		{
			if (game->map[line][column] != ' ' \
			&& game->map[line][column] != '1')
			{
				if (!check_wall(game, line, column))
					return (FALSE);
			}
			column++;
		}
		line++;
	}
	return (TRUE);
}
