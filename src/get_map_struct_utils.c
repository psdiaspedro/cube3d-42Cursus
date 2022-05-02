/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:36:23 by dalves-s          #+#    #+#             */
/*   Updated: 2022/05/02 11:27:23 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	matrix_length(char **mat)
{
	int	length;

	length = 0;
	while (mat[length])
		length++;
	return (length);
}

int	check_index(char *mat)
{
	if (!ft_strncmp(mat, "NO", -1))
		return (TRUE);
	else if (!ft_strncmp(mat, "SO", -1))
		return (TRUE);
	else if (!ft_strncmp(mat, "EA", -1))
		return (TRUE);
	else if (!ft_strncmp(mat, "WE", -1))
		return (TRUE);
	else if (!ft_strncmp(mat, "C", -1))
		return (TRUE);
	else if (!ft_strncmp(mat, "F", -1))
		return (TRUE);
	return (FALSE);
}

int	get_path(t_game *game, char *aux, int numb_lines)
{
	char	**mat;

	mat = fix_line(aux);
	if (!mat || !mat[1] || !check_index(mat[0])
		|| !check_repetition(game, mat))
	{
		free_matrix(mat);
		return (FALSE);
	}
	if (!ft_strncmp(mat[0], "NO", -1))
		game->img.no.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "SO", -1))
		game->img.so.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "EA", -1))
		game->img.ea.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "WE", -1))
		game->img.we.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "C", -1))
		game->ceil_color = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "F", -1))
		game->floor_color = ft_strdup(mat[1]);
	free_matrix(mat);
	return (TRUE);
}

int	map_validation(int argc, t_game *game, char *address)
{
	game->fd = open(address, O_RDONLY);
	if (argc > 2 || argc < 2)
	{
		ft_putendl_fd("Error\nWrong number of arguments! :(", 2);
		return (FALSE);
	}
	if (game->fd < 0)
	{
		ft_putendl_fd("Error\nInvalid map path! :(", 2);
		return (FALSE);
	}
	return (TRUE);
}
