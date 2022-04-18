/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/16 22:56:43 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "get_next_line.h"

char	**fix_line(char *aux)
{
	char	*temp;
	char	**lines;
	int		i;

	i = 2;
	temp = ft_strtrim(aux, " ");
	lines = ft_split(temp, ' ');
	while (lines[i] != NULL)
	{
			lines[1] = ft_strjoin(lines[1], lines[i]);
		i++;
	}
	free(temp);
	return (lines);
}

int	get_path(t_game *game, char *aux, int numb_lines)
{
	char	**mat;

	mat = fix_line(aux);
	if (!mat[1] || !ft_strchr("NSEWCF", mat[0][0]))
		return (-1);
	if (!ft_strncmp(mat[0], "NO", 2))
		game->img.no.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "SO", 2))
		game->img.so.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "EA", 2))
		game->img.ea.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "WE", 2))
		game->img.we.path = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "C", 1))
		game->ceil_color = ft_strdup(mat[1]);
	else if (!ft_strncmp(mat[0], "F", 1))
		game->floor_color = ft_strdup(mat[1]);
	mat[0][0] = 'D';
	free_matrix(mat);
	return (numb_lines);
}

int	map_validation(int argc, t_game *game, char *address)
{
	game->fd = open(address, O_RDONLY);
	if (argc > 2 || argc < 2)
	{
		ft_putendl_fd("ERROR:\nWrong number of arguments! :(", 2);
		return (0);
	}
	if (game->fd < 0)
	{
		ft_putendl_fd("ERROR:\nInvalid map path! :(", 2);
		return (0);
	}
	return (1);
}

int	get_map_struct(int argc, char **argv, t_game *game, int numb_lines)
{
	int			line;
	size_t		gnl_output;

	if (!map_validation(argc, game, argv[1]))
		return (0);
	gnl_output = 1;
	line = -1;
	game->map_line = ft_strdup("");
	while (gnl_output)
	{
		gnl_output = get_next_line(game->fd, &game->aux);
		game->temp = ft_strtrim(game->aux, " ");
		if (game->temp[0] == '1')
			get_map(&game->map_line, game->aux);
		if (game->aux[0] == '\0')
		{
			free_map_vars(&game->map_line, &game->aux, &game->temp);
			continue ;
		}
		if (numb_lines < 6)
			numb_lines = get_path(game, game->aux, numb_lines + 1);
		free_map_vars(&game->map_line, &game->aux, &game->temp);
		if (numb_lines == -1)
		{
			ft_putendl_fd("Error\nColor do not exist :(", 2);
			return (0);
		}
	}
	game->map = ft_split(game->map_line, '\n');
	return (1);
}

void	get_map(char **map_line, char *aux)
{
	*map_line = ft_strjoin(*map_line, aux);
	*map_line = ft_strjoin(*map_line, "\n");
}
