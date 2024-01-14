/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:27:52 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/27 22:23:04 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int		x;
	int		y;
	int		width;

	x = game->character.x / 32;
	y = game->character.y / 32;
	width = game->map.width;
	if ((KEY_A == keycode || KEY_LEFT == keycode)
		&& (game->map.map[y * width + (x - 1)]) != '1')
		move_left(game);
	if ((KEY_D == keycode || KEY_RIGHT == keycode)
		&& (game->map.map[y * width + (x + 1)]) != '1')
		move_right(game);
	if ((KEY_W == keycode || KEY_UP == keycode)
		&& (game->map.map[(y - 1) * width + x]) != '1')
		move_up(game);
	if ((KEY_S == keycode || KEY_DOWN == keycode)
		&& (game->map.map[(y + 1) * width + x]) != '1')
		move_down(game);
	add_counter(game);
	if (open_exit(game) || KEY_ESC == keycode)
		exit_game();
	return (0);
}

int	key_action(int keycode, t_game *game)
{
	if (KEY_A == keycode || KEY_LEFT == keycode || KEY_D == keycode
		|| KEY_RIGHT == keycode || KEY_W == keycode || KEY_UP == keycode
		|| KEY_S == keycode || KEY_DOWN == keycode || KEY_ESC == keycode)
		key_hook(keycode, game);
	return (0);
}
