/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/13 09:59:34 by paugusto         ###   ########.fr       */
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
	if (mat[0][0] == 'N')
			game->img.no.path = ft_strdup(mat[1]);
	else if (mat[0][0] == 'S')
		game->img.so.path = ft_strdup(mat[1]);
	else if (mat[0][0] == 'E')
		game->img.ea.path = ft_strdup(mat[1]);
	else if (mat[0][0] == 'W')
		game->img.we.path = ft_strdup(mat[1]);
	else if (mat[0][0] == 'C')
		game->ceil_color = ft_strdup(mat[1]);
	else if (mat[0][0] == 'F')
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
	char		*aux;
	char		*temp;
	char		*map;
	int			line;
	size_t		gnl_output;

	if (!map_validation(argc, game, argv[1]))
		return (0);
	gnl_output = 1;
	line = -1;
	map = ft_strdup("");
	while (gnl_output)
	{
		gnl_output = get_next_line(game->fd, &aux);
		temp = ft_strtrim(aux, " ");
		if (temp[0] == '1')
			get_map(&map, aux);
		if (aux[0] == '\0')
		{
			free_map_vars(&map, &aux, &temp);
			continue ;
		}
		if (numb_lines < 6)
			numb_lines = get_path(game, aux, numb_lines + 1);
		free_map_vars(&map, &aux, &temp);
	}
	game->map = ft_split(map, '\n');
	free(map);
	return (1);
}

void	get_map(char **map, char *aux)
{
	*map = ft_strjoin(*map, aux);
	*map = ft_strjoin(*map, "\n");
}
