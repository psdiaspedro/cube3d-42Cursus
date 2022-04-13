/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dalves-s <dalves-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:05:54 by dalves-s          #+#    #+#             */
/*   Updated: 2022/04/12 20:08:31 by dalves-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	main(int argc, char **argv)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	if (!get_map_struct(argc, argv, &game, 0))
		return (1);
	if (!check_map_struct(&game, 0, 0))
	{
		ft_putendl_fd("ERROR\nMap must be surrounded by walls! :(", 2);
		free_all(&game);
		return (1);
	}
	init_game(&game);
	init_images(&game);
	init_player(&game);
	run(&game);
	free_all(&game);
	return (0);
}

// Criar contador de linha do mapa para alocação dinâmica