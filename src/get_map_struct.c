/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/26 12:41:23 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "get_next_line.h"

char	**fix_line(char *aux)
{
	char	**lines;
	int		i;

	i = 2;
	lines = ft_split(aux, ' ');
	if (lines[0] == "C" || lines[0] == "F")
	{
		while (lines[i] != NULL)
		{
				lines[1] = ft_strjoin(lines[1], lines[i]);
			i++;
		}
	}
	i = 0;
	while (lines[i])
		i++;
	if (i > 2)
		return (NULL);
	return (lines);
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
	if (!mat || !mat[1] || !check_index(mat[0]))
		return (FALSE);
	if (!check_repetition(game, mat))
		return (FALSE);
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
	return (numb_lines);
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

int	get_map_struct(int argc, char **argv, t_game *game, int numb_lines)
{
	int			line;

	if (!map_validation(argc, game, argv[1]))
		return (FALSE);
	game->gnl_output = 1;
	line = -1;
	while (game->gnl_output)
	{
		game->gnl_output = get_next_line(game->fd, &game->aux);
		game->temp = ft_strtrim(game->aux, " ");
		if (game->temp[0] == '1')
		{
			if (!get_map(game))
				return (FALSE);
			break ;
		}
		if (game->aux[0] == '\0')
		{
			free_map_vars(&game->map_line, &game->aux, &game->temp);
			continue ;
		}
		numb_lines = get_path(game, game->aux, numb_lines + 1);
		free_map_vars(&game->map_line, &game->aux, &game->temp);
		if (!numb_lines)
		{
			ft_putendl_fd("Error\nInvalid resource :(", 2);
			return (FALSE);
		}
	}
	if (!check_resource(game))
	{
		ft_putendl_fd("Error\nInvalid resource :(", 2);
		return (FALSE);
	}
	return (TRUE);
}

int    validate_char(char c, char *set)
{
    size_t    i;

    i = 0;
    while (set[i])
    {
        if (set[i] == c)
		{
            return (TRUE);
		}
        i++;
    }
	ft_putendl_fd("Error\nInvalid resource :(", 2);
	return (FALSE);
}

int	get_map(t_game *game)
{
	size_t	i;

	game->gnl_output = 1;
	game->map_line = ft_strdup("");
	i = 0;
	while (game->gnl_output)
	{
		if (!*game->aux)
			return (FALSE);
		game->map_line = ft_strjoin(game->map_line, game->aux);
		game->map_line = ft_strjoin(game->map_line, "\n");
		game->gnl_output = get_next_line(game->fd, &game->aux);
	}
	game->map_line = ft_strjoin(game->map_line, game->aux);
	game->map_line = ft_strjoin(game->map_line, "\n");
	while (game->map_line[i])
	{
		if(!validate_char(game->map_line[i], "01 \nWESN"))
		{
			return (FALSE);
		}
		i++;
	}
	game->map = ft_split(game->map_line, '\n');
	if (!game->map)
		return (FALSE);
	return (TRUE);
}
