/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 19:45:01 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/30 12:33:22 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_enemy_game(t_game *game)
{
	int	i;

	i = 0;
	game->enemy = (t_enemy **)malloc((game->count_all.enemy + 1)
			* sizeof(t_enemy *));
	while (i < game->count_all.enemy)
	{
		game->enemy[i] = malloc(game->count_all.enemy * sizeof(t_enemy));
		i++;
	}
}

void	init_enemy(t_game *game)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i * game->map.width + j] == 'S')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->floor, j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->enemy[count]->img, j * 32, i * 32);
				game->enemy[count]->x = j;
				game->enemy[count]->y = i;
				count++;
			}
			j++;
		}
		i++;
	}
}

void	init_textures_enemy(t_game *game, int img_width, int img_height)
{
	int	i;

	i = 0;
	while (i < game->count_all.enemy)
	{
		game->enemy[i]->img = mlx_xpm_file_to_image(game->mlx,
				animation_enemy(0), &img_width, &img_height);
		check_map_name(game->enemy[i]->img, 2);
		i++;
	}
}
