/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:07:26 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/30 12:36:29 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_animation_enemy(t_game *game, int img_width, int img_height)
{
	int		i;

	i = 0;
	while (i < game->count_all.enemy)
	{
		mlx_destroy_image(game->mlx, game->enemy[i]->img);
		game->enemy[i]->img = mlx_xpm_file_to_image(game->mlx,
				animation_enemy(game->i), &img_width, &img_height);
		check_map_name(game->enemy[i]->img, 2);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			game->enemy[i]->x * 32, game->enemy[i]->y * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy[i]->img,
			game->enemy[i]->x * 32, game->enemy[i]->y * 32);
		i++;
	}
}

void	ft_animation_exit(t_game *game, int img_width, int img_height)
{
	mlx_destroy_image(game->mlx, game->exit.img);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, animation_exit(game->i),
			&img_width, &img_height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
		game->exit.x * 32, game->exit.y * 32);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit.img,
		game->exit.x * 32, game->exit.y * 32);
}

void	add_game_over(t_game *game)
{
	int		x;
	int		y;

	x = (game->map.width * 32) / 2 - 30;
	y = game->map.height * 32 + 15;
	mlx_string_put(game->mlx, game->mlx_win, x, y, RED, "GAME OVER");
}
// void	ft_animation_death(t_game *game, int img_width, int img_height)
// {
// 	mlx_destroy_image(game->mlx, game->character.img);
// 	game->character.img = mlx_xpm_file_to_image(game->mlx,
// 			animation_death(game->i), &img_width, &img_height);
// 	mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
// 		32, 32);
// 	mlx_put_image_to_window(game->mlx, game->mlx_win, game->character.img,
// 		32, 32);
// 	// mlx_destroy_image(game->mlx, game->character.img);
// 	// mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
// 	// 	32, 32);
// 	// game->character.img = mlx_xpm_file_to_image(game->mlx,
// 	// 		animation_death(game->i), &img_width, &img_height);
// 	// mlx_put_image_to_window(game->mlx, game->mlx_win, game->character.img,
// 	// 	32, 32);
// }

int	render_next_frame(t_game *game)
{
	int							img_width;
	int							img_height;
	struct timeval				tv;
	static unsigned long long	diff;
	static unsigned long long	last_time;

	img_width = 32;
	img_height = 32;
	gettimeofday(&tv, NULL);
	diff += (tv.tv_sec * 1000 + (tv.tv_usec / 1000)) - last_time;
	last_time = (tv.tv_sec * 1000 + (tv.tv_usec / 1000));
	if (diff < 180)
		return (0);
	game->i++;
	if (game->i == 4)
		game->i = 0;
	ft_animation_exit(game, img_width, img_height);
	ft_animation_enemy(game, img_width, img_height);
	diff = 0;
	return (0);
}

	// if (game->character.state != 1)
	// {
	// }