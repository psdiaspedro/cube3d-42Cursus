/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:23:35 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/28 10:37:13 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->map_line);
	game->map = NULL;
}

void	free_all(t_game *game)
{
	free_map(game);
	if (game->ceil_color)
		free(game->ceil_color);
	if (game->floor_color)
		free(game->floor_color);
	if (game->img.ea.path)
		free(game->img.ea.path);
	if (game->img.no.path)
		free(game->img.no.path);
	if (game->img.so.path)
		free(game->img.so.path);
	if (game->img.we.path)
		free(game->img.we.path);
	if (game->img.ea.img)
		mlx_destroy_image(game->mlx, game->img.ea.img);
	if (game->img.no.img)
		mlx_destroy_image(game->mlx, game->img.no.img);
	if (game->img.so.img)
		mlx_destroy_image(game->mlx, game->img.so.img);
	if (game->img.we.img)
		mlx_destroy_image(game->mlx, game->img.we.img);
	if (game->canvas.img)
		mlx_destroy_image(game->mlx, game->canvas.img);
	close(game->fd);
}

void	free_matrix(char **mat)
{
	int	x;

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

void	free_map_vars(char **aux, char **temp)
{
	free(*temp);
	free(*aux);
}
