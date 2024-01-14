/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 15:38:21 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/28 22:14:08 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_left(t_game *game)
{
	if ((game->map.map[game->character.y / 32 * game->map.width
				+ (game->character.x / 32 - 1)]) == 'C')
	{
		game->map.map[game->character.y / 32 * game->map.width
			+ (game->character.x / 32 - 1)] = '0';
		game->character.collect++;
	}
	if ((game->map.map[game->character.y / 32 * game->map.width
				+ (game->character.x / 32 - 1)]) == 'S')
		game->character.state = 1;
	game->character.x -= 32;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character.img,
		game->character.x, game->character.y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->character.x + 32, game->character.y);
	game->character.move++;
	printf("Step = %d\n", game->character.move);
}

void	move_right(t_game *game)
{
	if ((game->map.map[game->character.y / 32 * game->map.width
				+ (game->character.x / 32 + 1)]) == 'C')
	{
		game->map.map[game->character.y / 32 * game->map.width
			+ (game->character.x / 32 + 1)] = '0';
		game->character.collect++;
	}
	if ((game->map.map[game->character.y / 32 * game->map.width
				+ (game->character.x / 32 + 1)]) == 'S')
		game->character.state = 1;
	game->character.x += 32;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character.img,
		game->character.x, game->character.y);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->character.x - 32, game->character.y);
	game->character.move++;
	printf("Step = %d\n", game->character.move);
}

void	move_up(t_game *game)
{
	if ((game->map.map[(game->character.y / 32 - 1) * game->map.width
				+ game->character.x / 32]) == 'C')
	{
		game->map.map[(game->character.y / 32 - 1) * game->map.width
			+ game->character.x / 32] = '0';
		game->character.collect++;
	}
	if ((game->map.map[(game->character.y / 32 - 1) * game->map.width
				+ game->character.x / 32]) == 'S')
		game->character.state = 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character.img,
		game->character.x, game->character.y -= 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->character.x, game->character.y + 32);
	game->character.move++;
	printf("Step = %d\n", game->character.move);
}

void	move_down(t_game *game)
{
	if ((game->map.map[(game->character.y / 32 + 1) * game->map.width
				+ game->character.x / 32]) == 'C')
	{
		game->map.map[(game->character.y / 32 + 1) * game->map.width
			+ game->character.x / 32] = '0';
		game->character.collect++;
	}
	if ((game->map.map[(game->character.y / 32 + 1) * game->map.width
				+ game->character.x / 32]) == 'S')
		game->character.state = 1;
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character.img,
		game->character.x, game->character.y += 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->character.x, game->character.y - 32);
	game->character.move++;
	printf("Step = %d\n", game->character.move);
}
