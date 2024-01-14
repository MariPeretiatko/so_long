/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 02:32:32 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/30 12:33:42 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_map_error_count(t_game *game)
{
	int	flag;

	flag = 0;
	if (game->count_all.exit != 1)
	{
		ft_printf("Error with counter exit\n");
		flag++;
	}
	if (game->count_all.player != 1)
	{
		ft_printf("Error with counter player\n");
		flag++;
	}
	if (game->count_all.collectible < 1)
	{
		ft_printf("Error with counter collectible\n");
		flag++;
	}
	if (flag != 0)
	{
		ft_printf("Error map\n");
		exit(0);
	}
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (i == 0 && (game->map.map[i * game->map.width + j]) != '1')
				return (1);
			if (i == game->map.height - 1
				&& (game->map.map[i * game->map.width + j]) != '1')
				return (1);
			if (j == 0 && (game->map.map[i * game->map.width + j]) != '1')
				return (1);
			if (j == game->map.width - 1
				&& (game->map.map[i * game->map.width + j]) != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_symbols(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.map[i * game->map.width + j] != '1'
				&& game->map.map[i * game->map.width + j] != '0'
				&& game->map.map[i * game->map.width + j] != 'P'
				&& game->map.map[i * game->map.width + j] != 'E'
				&& game->map.map[i * game->map.width + j] != 'C'
				&& game->map.map[i * game->map.width + j] != 'S')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map_form(t_game *game, int lines, int colums)
{
	if ((int)ft_strlen(game->map.map) != (lines * colums))
	{
		ft_printf("error map - map doesnt have rectangle form");
		exit_game();
	}
	if (check_walls(game))
	{
		ft_printf("error map - problem with walls");
		exit_game();
	}
	if (check_symbols(game))
	{
		ft_printf("error map - prohibited symbols in the map");
		exit_game();
	}
}

void	check_map_name(char *map, int flag)
{
	if (!map && flag == 1)
	{
		ft_printf("Problem with map\n");
		exit_game();
	}
	if (!map && flag == 2)
	{
		ft_printf("Problem with path textures\n");
		exit_game();
	}
}
