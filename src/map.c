/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:50:06 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/30 12:05:14 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*remove_slash_n(char *str)
{
	int		i;
	int		j;
	int		count;
	char	*new_str;

	i = 0;
	j = 0;
	count = count_slash_n(str);
	new_str = malloc(sizeof(new_str) * (ft_strlen(str) + 1 - count));
	i = 0;
	while (str[j])
	{
		if (str[j] != '\n')
		{
			new_str[i] = str[j];
			i++;
		}
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}

int	chaeck_map_name(const char *av)
{
	char	*name_map;

	name_map = ft_strrchr(av, '.');
	if (name_map)
		return (ft_strcmp(name_map, ".ber") == 0);
	return (0);
}

//&&  chaeck_map_name(name_map))
void	read_map(t_game *game, char *path)
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
	check_map_name(map, 1);
	game->map.map = remove_slash_n(map);
	free(map);
	check_map_form(game, game->map.width = lines, game->map.height = colums);
	close(fd);
}

void	init_player_exit_map(t_game *game, int i, int j)
{
	if (game->map.map[i * game->map.width + j] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, j * 32, i * 32);
	else if (game->map.map[i * game->map.width + j] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->exit.img, j * 32, i * 32);
		game->map.map[i * game->map.width + j] = '1';
	}
	else if (game->map.map[i * game->map.width + j] == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor,
			j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->character.img,
			j * 32, i * 32);
	}
}

void	init_map(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i * game->map.width + j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->wall, j * 32, i * 32);
			else if (game->map.map[i * game->map.width + j] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->floor, j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->collectible, j * 32, i * 32);
			}
			init_player_exit_map(game, i, j);
			j++;
		}
		i++;
	}
}
