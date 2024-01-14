/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:10:59 by mperetia          #+#    #+#             */
/*   Updated: 2024/01/14 13:35:59 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
	{
		ft_printf("problems with arguments");
		exit(0);
	}
	if (!(chaeck_map_name(av[1])))
	{
		ft_printf("Can't open file. The format is not supported!");
		exit(0);
	}
	if (ac == 2 && chaeck_map_name(av[1]))
	{
		game = ft_calloc(sizeof(t_game), 1);
		ft_init_game(game, av[1]);
	}
	return (0);
}
		// mlx_loop_hook(game->mlx, render_next_frame, game);
