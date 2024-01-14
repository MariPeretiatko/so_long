/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:56:01 by mperetia          #+#    #+#             */
/*   Updated: 2024/01/14 13:28:44 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_game(t_game *game, char *path)
{
	game->mlx = mlx_init();
	read_map(game, path);
	game->mlx_win = mlx_new_window(game->mlx, game->map.width * 32,
			game->map.height * 32 + 20, "SO_LONG");
	init_textures(game);
	init_counter(game);
	init_map(game);
	check_path_finder(game, path);
	check_map_error_count(game);
	add_counter(game);
	mlx_hook(game->mlx_win, 17, 1L << 0, exit_game, game);
	mlx_key_hook(game->mlx_win, key_action, game);
	mlx_loop(game->mlx);
	free(game);
}

void	init_textures(t_game *game)
{
	int		img_width;
	int		img_height;

	img_width = 32;
	img_height = 32;
	game->wall = mlx_xpm_file_to_image(game->mlx, PATH_WALL,
			&img_width, &img_height);
	check_map_name(game->wall, 2);
	game->floor = mlx_xpm_file_to_image(game->mlx, PATH_FLOOR,
			&img_width, &img_height);
	check_map_name(game->floor, 2);
	game->collectible = mlx_xpm_file_to_image(game->mlx, PATH_COLLECTIBLE,
			&img_width, &img_height);
	check_map_name(game->collectible, 2);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, animation_exit(0),
			&img_width, &img_height);
	check_map_name(game->exit.img, 2);
	game->character.img_right = mlx_xpm_file_to_image(game->mlx, PATH_CHARACTER_R,
			&img_width, &img_height);
	game->character.img_left = mlx_xpm_file_to_image(game->mlx, PATH_CHARACTER_L,
			&img_width, &img_height);
	check_map_name(game->character.img_right, 2);
}

void	init_player_exit(t_game *game, int i, int j)
{
	if (game->map.map[i * game->map.width + j] == 'P')
	{
		game->count_all.player += 1;
		game->character.x = j * 32;
		game->character.y = i * 32;
	}
	if (game->map.map[i * game->map.width + j] == 'E')
	{
		game->count_all.exit += 1;
		game->exit.x = j;
		game->exit.y = i;
	}
}

void	init_counter(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			init_player_exit(game, i, j);
			if (game->map.map[i * game->map.width + j] == 'C')
				game->count_all.collectible += 1;
			j++;
		}
		i++;
	}
	check_map_error_count(game);
}

void	add_counter(t_game *game)
{
	char	*str;
	char	*str_;
	int		x;

	str = ft_itoa_utils(game->character.move);
	str_ = NULL;
	x = game->map.height * 32 + 15;
	if (game->character.move >= 1)
	{
		str_ = ft_itoa_utils(game->character.move - 1);
		mlx_string_put(game->mlx, game->mlx_win, 10, x, BLACK, str_);
	}
	mlx_string_put(game->mlx, game->mlx_win, 10, x, BLUE, str);
	free(str_);
	free(str);
}
