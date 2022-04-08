/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:05:54 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/08 11:41:00 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>


int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2 || argc < 2)
	{
		ft_putendl_fd("ERROR:\nWrong number of arguments!:/", 2);
		return (1);
	}
	init_map(&game);
	get_map_struct(argv, &game);
	t_vec	cameraPixel;

	init_game(&game);
	init_images(&game);
	init_player(&game);
	run(&game);
	free_all(&game);
	return (0);
}
