/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:57:25 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/27 22:44:13 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_game(void)
{
	exit(0);
	return (0);
}

int	open_exit(t_game *game)
{
	if (game->character.collect == game->count_all.collectible)
		game->map.map[game->exit.y * game->map.width + game->exit.x] = 'E';
	if (((game->character.collect == game->count_all.collectible)
			&& game->character.x / 32 == game->exit.x
			&& game->character.y / 32 == game->exit.y))
		return (1);
	return (0);
}
