/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:38:12 by dalves-s          #+#    #+#             */
/*   Updated: 2022/05/04 10:04:42 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_rgb(char *rgb)
{
	char	**aux;
	char	*temp;
	int		color;
	int		i;

	aux = ft_split(rgb, ',');
	i = 0;
	while (aux[i])
	{
		temp = ft_strtrim(aux[i], " ");
		free(aux[i]);
		aux[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
	if (!aux[0] || !aux[1] || !aux[2] || ft_strlen(aux[0]) > 3)
	{
		free_matrix(aux);
		return (FALSE);
	}
	color = create_rgb(ft_atoi(aux[0]), ft_atoi(aux[1]), ft_atoi(aux[2]));
	free_matrix(aux);
	return (color);
}
