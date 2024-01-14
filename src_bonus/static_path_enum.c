/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_path_enum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 01:12:54 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/30 12:36:52 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*animation_exit(enum e_pathExit p)
{
	static char	*path[] = {
		"textures/exit/portal.xpm",
		"textures/exit/portal-1.xpm",
		"textures/exit/portal-2.xpm",
		"textures/exit/portal-3.xpm"
	};

	return (path[p]);
}

char	*animation_enemy(enum e_pathEnemy p)
{
	static char	*path[] = {
		"textures/enemy/slime00.xpm",
		"textures/enemy/slime01.xpm",
		"textures/enemy/slime02.xpm",
		"textures/enemy/slime03.xpm"
	};

	return (path[p]);
}

char	*animation_death(enum e_pathDeath p)
{
	static char	*path[] = {
		"textures/character/death/death00.xpm",
		"textures/character/death/death01.xpm",
		"textures/character/death/death02.xpm",
		"textures/character/death/death03.xpm",
		"textures/character/death/death04.xpm"
	};

	return (path[p]);
}
