/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 10:11:23 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/28 11:41:15 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_repetition(t_game *game, char **mat)
{
	if (!ft_strncmp(mat[0], "NO", -1) && game->img.no.path)
		return (FALSE);
	if (!ft_strncmp(mat[0], "SO", -1) && game->img.so.path)
		return (FALSE);
	if (!ft_strncmp(mat[0], "EA", -1) && game->img.ea.path)
		return (FALSE);
	if (!ft_strncmp(mat[0], "WE", -1) && game->img.we.path)
		return (FALSE);
	if (!ft_strncmp(mat[0], "C", -1) && game->ceil_color)
		return (FALSE);
	if (!ft_strncmp(mat[0], "F", -1) && game->floor_color)
		return (FALSE);
	return (TRUE);
}

int	check_resource(t_game *game)
{
	if (!game->img.no.path || !game->img.so.path)
		return (FALSE);
	if (!game->img.ea.path || !game->img.we.path)
		return (FALSE);
	if (!game->ceil_color || !game->floor_color)
		return (FALSE);
	if (!game->map)
		return (FALSE);
	return (TRUE);
}

int	validate_char(char c, char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
