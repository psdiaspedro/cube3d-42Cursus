/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:44:22 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/26 11:04:22 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

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

int	check_left_bottom_diagonal(t_game *game, int line, int column)
{
	while (game->map[line] && game->map[line][column])
	{
		if (game->map[line][column] == ' ')
			return (FALSE);
		line++;
		column--;
		if (game->map[line] && game->map[line][column]
			&& game->map[line][column] == '1')
			return (TRUE);
	}
	return (FALSE);
}

int	check_left_up_diagonal(t_game *game, int line, int column)
{
	while (game->map[line] && game->map[line][column])
	{
		if (game->map[line][column] == ' ')
			return (FALSE);
		line--;
		column--;
		if (game->map[line] && game->map[line][column]
			&& game->map[line][column] == '1')
			return (TRUE);
	}
	return (FALSE);
}

int	check_right_up_diagonal(t_game *game, int line, int column)
{
	while (game->map[line] && game->map[line][column])
	{
		if (game->map[line][column] == ' ')
			return (FALSE);
		line--;
		column++;
		if (game->map[line] && game->map[line][column]
			&& game->map[line][column] == '1')
			return (TRUE);
	}
	return (FALSE);
}

int	check_right_bottom_diagonal(t_game *game, int line, int column)
{
	while (game->map[line] && game->map[line][column])
	{
		if (game->map[line][column] == ' ')
			return (FALSE);
		line++;
		column++;
		if (game->map[line] && game->map[line][column]
			&& game->map[line][column] == '1')
			return (TRUE);
	}
	return (FALSE);
}

int	check_wall(t_game *game, int line, int column)
{
	if (!check_front(game, line, column))
		return (FALSE);
	if (!check_back(game, line, column))
		return (FALSE);
	if (!check_up(game, line, column))
		return (FALSE);
	if (!check_bottom(game, line, column))
		return (FALSE);
	if (!check_left_bottom_diagonal(game, line, column))
		return (FALSE);
	if (!check_left_up_diagonal(game, line, column))
		return (FALSE);
	if (!check_right_up_diagonal(game, line, column))
		return (FALSE);
	if (!check_right_bottom_diagonal(game, line, column))
		return (FALSE);
	return (TRUE);
}
