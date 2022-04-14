/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:38:12 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/14 08:28:57 by paugusto         ###   ########.fr       */
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
	int		color;

	aux = ft_split(rgb, ',');
	color = create_rgb(ft_atoi(aux[0]), ft_atoi(aux[1]), ft_atoi(aux[2]));
	free_matrix(aux);
	return (color);
}
