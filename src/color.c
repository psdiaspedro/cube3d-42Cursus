/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:38:12 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/13 11:38:48 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	get_rgb(char *color)
{
	char	**aux;
	int		col;

	aux = ft_split(color, ',');
	col = create_rgb(ft_atoi(aux[0]), ft_atoi(aux[1]), ft_atoi(aux[2]));
	free_matrix(aux);
	return(col);
}
