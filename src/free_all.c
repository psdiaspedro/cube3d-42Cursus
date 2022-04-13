/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:23:35 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/12 20:32:08 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_all(t_game *game)
{
	int x;

	x = 0;
	if (!game->map)
		return ;
	while (game->map[x])
	{
		free(game->map[x]);
		x++;
	}
	free(game->map);
	game->map = NULL;
	free(game->ceil_color);
	free(game->floor_color);
	free(game->img.ea.addr);
	free(game->img.no.addr);
	free(game->img.so.addr);
	free(game->img.we.addr);
	free(game->img.ea.path);
	free(game->img.no.path);
	free(game->img.so.path);
	free(game->img.we.path);
	free(game->canvas.img);
	free(game->img.ea.img);
	free(game->img.no.img);
	free(game->img.we.img);
	free(game->img.so.img);
}

void	free_matrix(char **mat)
{
	int x;

	x = 0;
	if (!mat)
		return ;
	while (mat[x])
	{
		free(mat[x]);
		x++;
	}
	free(mat);
}

void	free_map_vars(char **map, char **aux, char **temp)
{
	free(*temp);
	// free(*map);
	free(*aux);
}