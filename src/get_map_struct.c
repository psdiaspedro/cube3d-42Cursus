/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/27 11:51:10 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "get_next_line.h"

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

int	get_map_struct_aux(t_game *game)
{
	if (game->temp[0] == '1')
	{
		if (!get_map(game))
		{
			ft_putendl_fd("Error\nInvalid resource :(", 2);
			return (FALSE);
		}
		return (BREAK);
	}
	if (game->aux[0] == '\0')
	{
		free_map_vars(&game->map_line, &game->aux, &game->temp);
		return (CONTINUE);
	}
}

int	get_map_struct(int argc, char **argv, t_game *game, int numb_lines)
{
	int	ret;

	ret = 0;
	if (!map_validation(argc, game, argv[1]))
		return (FALSE);
	game->gnl_output = 1;
	while (game->gnl_output)
	{
		game->gnl_output = get_next_line(game->fd, &game->aux);
		game->temp = ft_strtrim(game->aux, " ");
		ret = get_map_struct_aux(game);
		if (ret == FALSE)
			return (FALSE);
		else if (ret == BREAK)
			break ;
		else if (ret == CONTINUE)
			continue ;
		numb_lines = get_path(game, game->aux, numb_lines + 1);
		free_map_vars(&game->map_line, &game->aux, &game->temp);
		if (!numb_lines)
		{
			ft_putendl_fd("Error\nInvalid resource :(", 2);
			return (FALSE);
		}
	}
	free(game->temp);
	if (!check_resource(game))
	{
		ft_putendl_fd("Error\nInvalid resource :(", 2);
		return (FALSE);
	}
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

int	get_map_aux(t_game *game)
{
	char	**checker;

	while (game->gnl_output)
	{
		checker = ft_split(game->map_line, '\n');
		if (!*game->aux
			&& validate_char('0', checker[matrix_length(checker) - 1]))
		{
			free(checker);
			checker = NULL;
			return (FALSE);
		}
		free(checker);
		checker = NULL;
		if (*game->aux)
			game->map_line = ft_strjoin(game->map_line, game->aux);
			game->map_line = ft_strjoin(game->map_line, "\n");
		free(game->aux);
		game->gnl_output = get_next_line(game->fd, &game->aux);
	}
	return (TRUE);
}

int	get_map(t_game *game)
{
	size_t	i;

	game->gnl_output = 1;
	game->map_line = ft_strdup("");
	i = 0;
	if (!get_map_aux(game))
		return (FALSE);
	game->map_line = ft_strjoin(game->map_line, game->aux);
	game->map_line = ft_strjoin(game->map_line, "\n");
	while (game->map_line[i])
	{
		if (!validate_char(game->map_line[i], "01 \nWESN"))
		{
			return (FALSE);
		}
		i++;
	}
	game->map = ft_split(game->map_line, '\n');
	if (!game->map)
		return (FALSE);
	free(game->aux);
	return (TRUE);
}
