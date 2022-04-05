/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 18:03:28 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/05 09:56:16 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h" 

void	check_map_wall(t_maze *maze)
{
	int	i;

	i = 0;
	while (maze->lines[0][i] != '\0' && maze->lines[maze->m_height - 1][i] != '\0')
	{
		if (maze->lines[0][i] != '1' || maze->lines[maze->m_height - 1][i] != '1')
		{
			ft_putstr_fd("ERROR\nMap must be surrounded by wall\n", 1);
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i < maze->m_height)
	{
		if (maze->lines[i][0] != '1' || maze->lines[i][maze->m_width - 1] != '1')
		{
			ft_putstr_fd("ERROR\nMap must be surrounded by wall\n", 1);
			exit (1);
		}
		i++;
	}
}

// void	count_map_pce(t_maze *maze)
// {
// 	size_t	j;
// 	size_t	i;

// 	j = 0;
// 	while (maze->lines[j] != NULL)
// 	{
// 		i = 0;
// 		while (maze->lines[j][i] != '\0')
// 		{
// 			if (maze->lines[j][i] == 'P')
// 				maze->check_p++;
// 			if (maze->lines[j][i] == 'C')
// 				maze->check_c++;
// 			if (maze->lines[j][i] == 'E')
// 				maze->check_e++;
// 			i++;
// 		}
// 		j++;
// 	}
// }

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

void	check_map_content(char *line)
{
	int	column;

	column = 0;
	while (line[column])
	{
		if (line[column] != 'N' && line[column] != 'S'
			&& line[column] != 'E' && line[column] != 'W'
			&& line[column] != '1' && line[column] != '0')
		{
			ft_putstr_fd("ERROR\nIs there any wrong character on the maze \n", 1);
			exit (1);
		}
		column++;
	}
}

void	get_map_struct(char **argv, t)
{
	const char	*address;
	int			line;
	size_t		gnl_output;

	address = argv[1];
	line = 0;
	maze->fd = open(address, O_RDONLY);
	gnl_output = 1;
	while (gnl_output != 0)
	{
		gnl_output = get_next_line(maze->fd, &maze->lines[line]);
		maze->backup[line] = ft_strdup(maze->lines[line]);
		check_map_content(maze->lines[line]);
		maze->m_height++;
		printf("%s\n", maze->lines[line]);
		line++;
	}
	maze->m_width = ft_strlen(&maze->lines[0][0]);
	maze->lines[maze->m_height + 1] = NULL;
	check_map_wall(maze);
	// count_map_pce(maze);
	// check_error_pce(maze);
}
