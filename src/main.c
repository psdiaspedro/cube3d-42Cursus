/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:05:54 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/11 16:51:32 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_game	game;

	init_map(&game);
	if (!get_map_struct(argc, argv, &game))
		return (1);
	t_vec	cameraPixel;

	init_game(&game);
	init_images(&game);
	init_player(&game);
	run(&game);
	free_all(&game);
	return (0);
}
