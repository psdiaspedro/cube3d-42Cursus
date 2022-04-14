/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:44:22 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/14 08:40:34 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_front(t_game *game, int line, int column)
{
	while (game->map[line][column])
	{
		if (game->map[line][column] == '1')
		{
			return (1);
		}
		column++;
	}
	printf("Chegou aqui");
	return (0);
}

int	check_back(t_game *game, int line, int column)
{
	while (column >= 0)
	{
		if (game->map[line][column] == '1')
			return (1);
		column--;
	}
	return (0);
}

int	check_up(t_game *game, int line, int column)
{
	while (line >= 0)
	{
		if (game->map[line][column] == '1')
			return (1);
		line--;
	}
	return (0);
}

int	check_bottom(t_game *game, int line, int column)
{
	while (game->map[line])
	{
		if (game->map[line][column] == '1')
			return (1);
		line++;
	}
	return (0);
}

int	check_wall(t_game *game, int line, int column)
{
	if (!check_front(game, line, column))
		return (0);
	if (!check_back(game, line, column))
		return (0);
	if (!check_up(game, line, column))
		return (0);
	if (!check_bottom(game, line, column))
		return (0);
	return (1);
}
