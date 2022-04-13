/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 08:44:22 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/12 10:05:23 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_wall(t_game *game, int line, int column)
{
	if(!check_front(game, line, column))
		return (0);
	if(!check_back(game, line, column))
		return (0);
	if(!check_up(game, line, column))
		return (0);
	if(!check_bottom(game, line, column))
		return (0);
	return (1);
}

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

int	check_map_struct(t_game *game, int line, int column)
{
	while (game->map[line])
	{
		column = 0;
		while (game->map[line][column] == ' ' || game->map[line][column] == '1')
		{
			printf("%c", game->map[line][column]);
			column++;
		}
		while (game->map[line][column])
		{			
			if (game->map[line][column] != ' ' && game->map[line][column] != '1')
			{
				if (!check_wall(game, line, column))
					return (0);
			}		
			printf("%c", game->map[line][column]);
			column++;
		}
		printf("\n");
		line++;
	}
	return (1);
}

// Verificar se temos todos os paths e cores no arquivo;
// Verificar se tem um dos caracteres do player N/S/W/E;