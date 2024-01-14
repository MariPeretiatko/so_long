/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:20:16 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/29 22:06:38 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	read_map_tmp(t_game *game, char *path)
{
	int		lines;
	int		colums;
	char	*line;
	char	*map;
	int		fd;

	lines = 0;
	colums = 0;
	map = NULL;
	fd = open(path, O_RDONLY);
	while (fd)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		lines = ft_strlen(line);
		map = ft_strjoin_g(map, line);
		free(line);
		colums++;
	}
	game->map_ckeck.map = remove_slash_n(map);
	game->map_ckeck.width = lines;
	game->map_ckeck.height = colums;
	free(map);
	close(fd);
}

int	flood_fill(t_game *game, int x, int y)
{
	static int		coins = 0;
	static int		found_exit = 0;

	if (game->map_ckeck.map[y * game->map_ckeck.width + x] == '1'
		|| game->map_ckeck.map[y * game->map_ckeck.width + x] == 'S')
		return (0);
	else if (game->map_ckeck.map[y * game->map_ckeck.width + x] == 'C')
		coins += 1;
	else if (game->map_ckeck.map[y * game->map_ckeck.width + x] == 'E')
	{
		found_exit = 1;
		return (0);
	}
	game->map_ckeck.map[y * game->map_ckeck.width + x] = '1';
	flood_fill(game, x + 1, y);
	flood_fill(game, x - 1, y);
	flood_fill(game, x, y + 1);
	flood_fill(game, x, y - 1);
	return (coins == game->count_all.collectible && found_exit);
}

void	check_path_finder(t_game *game, char *path)
{
	read_map_tmp(game, path);
	if (!flood_fill(game, game->character.x / 32, game->character.y / 32))
	{
		ft_printf("Error map - path finding problem\n");
		exit_game();
	}
}
