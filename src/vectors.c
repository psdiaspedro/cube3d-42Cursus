/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:59:04 by paugusto          #+#    #+#             */
/*   Updated: 2022/04/05 13:59:09 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	mag_vec(t_vec *v)
{
	float hypotenuse;

	hypotenuse = sqrt((v->x * v->x) + (v->y * v->y));
	return (hypotenuse);
}

t_vec sum_vec(t_vec v1, t_vec v2)
{
	t_vec sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	return (sum);
}
