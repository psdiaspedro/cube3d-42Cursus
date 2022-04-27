/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 08:37:24 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/27 10:26:02 by dalves-s         ###   ########.fr       */
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

int	check_front(t_game *game, int line, int column)
{
	while (game->map[line][column])
	{
		if (game->map[line][column] == '1')
		{
			return (TRUE);
		}
		column++;
	}
	return (FALSE);
}

int	check_back(t_game *game, int line, int column)
{
	while (column >= 0)
	{
		if (game->map[line][column] == '1')
			return (TRUE);
		column--;
	}
	return (FALSE);
}

int	check_up(t_game *game, int line, int column)
{
	while (line >= 0)
	{
		if (game->map[line][column] == '1')
			return (TRUE);
		line--;
	}
	return (FALSE);
}

int	check_bottom(t_game *game, int line, int column)
{
	while (game->map[line])
	{
		if (game->map[line][column] == '1')
			return (TRUE);
		line++;
	}
	return (FALSE);
}
