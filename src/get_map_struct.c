/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2022/05/04 11:01:40 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "get_next_line.h"

int	get_map_struct_aux(t_game *game)
{
	if (game->temp[0] == '1')
	{
		if (!get_map(game))
		{
			free_map_vars(&game->aux, &game->temp);
			while (game->gnl_output)
			{
				game->gnl_output = get_next_line(game->fd, &game->aux);
				free_map_vars(&game->aux, &game->temp);
			}
			return (FALSE);
		}
		free_map_vars(&game->aux, &game->temp);
		return (BREAK);
	}
	if (game->aux[0] == '\0')
	{
		free_map_vars(&game->aux, &game->temp);
		return (CONTINUE);
	}
	return (TRUE);
}

int	get_map_struct_aux_2(t_game *game, int ret)
{
	game->map_path = TRUE;
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
		game->map_path = get_path(game, game->aux);
		free_map_vars(&game->aux, &game->temp);
	}
	free_map_vars(&game->aux, &game->temp);
	if (!game->map_path)
		return (FALSE);
	return (TRUE);
}

int	get_map_struct(int argc, char **argv, t_game *game)
{
	int	ret;

	ret = 0;
	if (!map_validation(argc, game, argv[1]))
		return (FALSE);
	game->gnl_output = 1;
	if (!get_map_struct_aux_2(game, ret))
	{
		free_map_vars(&game->aux, &game->temp);
		ft_putendl_fd("Error\nInvalid resource :(", 2);
		return (FALSE);
	}
	free_map_vars(&game->aux, &game->temp);
	if (!check_resource(game))
	{
		ft_putendl_fd("Error\nInvalid resource :(", 2);
		return (FALSE);
	}
	return (TRUE);
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
			free_matrix(checker);
			checker = NULL;
			free_map_vars(&game->aux, &game->temp);
			return (FALSE);
		}
		free_matrix(checker);
		checker = NULL;
		if (*game->aux)
		{
			game->map_line = ft_strjoin(game->map_line, game->aux);
			game->map_line = ft_strjoin(game->map_line, "\n");
		}
		free_map_vars(&game->aux, &game->temp);
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
	{
		free(game->map_line);
		return (FALSE);
	}
	game->map_line = ft_strjoin(game->map_line, game->aux);
	game->map_line = ft_strjoin(game->map_line, "\n");
	while (game->map_line[i])
	{
		if (!validate_char(game->map_line[i], "01 \nWESN"))
		{
			free(game->map_line);
			return (FALSE);
		}
		i++;
	}
	game->map = ft_split(game->map_line, '\n');
	if (!game->map)
		return (FALSE);
	return (TRUE);
}
