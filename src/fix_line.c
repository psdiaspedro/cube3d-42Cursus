/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 11:10:19 by dalves-s          #+#    #+#             */
/*   Updated: 2022/05/02 11:41:00 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	change_char(char *aux, char c1, char c2, int jump)
{
	int first;
	int	i;

	i = 0;
	first = jump;
	if (!aux)
		return ;
	while (aux[i])
	{
		if (aux[i] == c1 && first == 0)
		{
			aux[i] = c2;
		}
		else if (aux[i] == c1)
		{
			first = 0;
		}
		i++;
	}
}

int	check_comma_aux(char *line, int i)
{
	int j;

	j = i;
	while (j)
	{
		if (line[j] != ' ' && line[j] != ',')
			break ;
		if (line[j] == ',')
			return (TRUE);
		j--;
	}
	if (j == 0)
		return (TRUE);
	j = i;
	while (line[j])
	{
		if (line[j] != ' ' && line[j] != ',')
			return (FALSE);
		if (line[j] == ',')
			break ;
		j++;
	}
	return (TRUE);
}

int	check_comma(char *line)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
    counter = 0;
	if (!line)
		return (FALSE);
	while (line[i])
	{
		if (line[i] == ',')
			counter++;
		if (line[i] == ' ' && check_comma_aux(line, i))
		{
			i++;
			continue ;
		}
		if (counter > 2 || (line[i] != ',' && !ft_isdigit(line[i])))
        {
			return (FALSE);
        }
		i++;
	}
	return (TRUE);
}

char	**fix_line(char *aux)
{
	char	**lines;
	int		i;

	if (aux[0] == ' ')
		return (NULL);
	i = 1;
	if (aux[0] == 'C' || aux[0] == 'F')
	{
		change_char(aux, ' ', 1, TRUE);
		lines = ft_split(aux, ' ');
		change_char(lines[1], 1, ' ', FALSE);
		if (!check_comma(lines[1]))
		{
			free_matrix(lines);
			return (NULL);
		}
	}
	else
		lines = ft_split(aux, ' ');
	return (lines);
}
