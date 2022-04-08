/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/08 12:13:28 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>
#include "get_next_line.h"

// void	check_error_pce(t_maze *maze)
// {
// 	if (maze->check_p != 1 || maze->check_e != 1 || maze->check_c < 1)
// 	{
// 		if (maze->check_p != 1)
// 			ft_putstr_fd("ERROR\nMap must include 1 player (only 1)\n", 1);
// 		if (maze->check_e != 1)
// 			ft_putstr_fd("ERROR\nMap must include 1 exit point (only 1)\n", 1);
// 		if (maze->check_c < 1)
// 			ft_putstr_fd("ERROR\nMap must include at least 1 collectable", 1);
// 		exit (0);
// 	}
// }

// void	check_map_content(char *line)
// {
// 	int	column;

// 	column = 0;
// 	while (line[column])
// 	{
// 		if (line[column] != 'N' && line[column] != 'S'
// 			&& line[column] != 'E' && line[column] != 'W'
// 			&& line[column] != '1' && line[column] != '0')
// 		{
// 			ft_putstr_fd("ERROR\nIs there any wrong character on the maze \n", 1);
// 			exit (1);
// 		}
// 		column++;
// 	}
// }

char	**fix_line(char *aux)
{
	char	*temp;
	char	**lines;
	int		i;

	i = 2;
	temp = ft_strtrim(aux," ");
	lines = ft_split(temp, ' ');
	while (lines[i] != NULL)
	{
			lines[1] = ft_strjoin(lines[1], lines[i]);
		i++;
	}
	return (lines);
}

// void	get_path(t_game *game)
// {
	
// }

void	get_map_struct(char **argv, t_game *game)
{
	const char	*address;
	char		*aux;
	char		**mat;
	int			line;
	size_t		gnl_output;
	int			numb_lines;

	address = argv[1];
	line = 0;
	game->fd = open(address, O_RDONLY);
	gnl_output = 1;
	numb_lines = 0;
	while (gnl_output)
	{
		gnl_output = get_next_line(game->fd, &aux);
		if (aux[0] == '\0')
			continue ;
		if (numb_lines < 6)
		{
			mat = fix_line(aux);
			numb_lines++;
			// get_path(&game);
		}
		if (mat[0][0] == 'N')
		{
			game->no = ft_strdup(mat[1]);
			printf("N %s\n", game->no);
		}
		else if (mat[0][0] == 'S')
		{
			game->so = ft_strdup(mat[1]);
			printf("S %s\n", game->so);
		}
		else if (mat[0][0] == 'E')
		{
			game->ea = ft_strdup(mat[1]);
			printf("E %s\n", game->ea);
		}
		else if (mat[0][0] == 'W')
		{
			game->we = ft_strdup(mat[1]);
			printf("W %s\n", game->we);
		}
		else if (mat[0][0] == 'C')
		{
			game->ceil_color = ft_strdup(mat[1]);
			printf("C %s\n", game->ceil_color);
		}
		else if (mat[0][0] == 'F')
		{
			game->floor_color = ft_strdup(mat[1]);
			printf("F %s\n", game->floor_color);
		}
		else
		{
			game->map[line] = ft_strdup(aux);
			printf("MAP %s\n", game->map[line]);
			line++;
		}
		mat[0][0] = 'D';
	}
	free(mat);
	free(aux);
}
