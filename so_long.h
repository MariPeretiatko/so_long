/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperetia <mperetia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 00:32:25 by mperetia          #+#    #+#             */
/*   Updated: 2023/10/30 12:38:18 by mperetia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define PATH_FLOOR "textures/floor/floor.xpm"
# define PATH_CHARACTER_L "textures/character/Idle-1.xpm"
# define PATH_WALL "textures/wall/wall_tmp.xpm"
# define PATH_ENEMY02 "textures/enemy/slime02.xpm"
# define PATH_COLLECTIBLE "textures/collectible/Icon211.xpm"

# define KEY_A 0
# define KEY_W 13
# define KEY_D 2
# define KEY_S 1
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53

# define GREEN 0x3bf200
# define BLUE 0x1a8cff
# define BLACK 0x000000
# define RED 0xe10146

# include "MiniLibX/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <sys/time.h>
# include <time.h>
# include <stdio.h>
# include "inc/libft/libft.h"
# include "inc/get_next_line/get_next_line.h"
# include "inc/ft_printf/ft_printf.h"
// # include <stdio.h>

enum e_pathExit{
	PATH_EXIT = 0,
	PATH_EXIT_1,
	PATH_EXIT_2,
	PATH_EXIT_3
};

enum e_pathEnemy{
	PATH_ENEMY = 0,
	PATH_ENEMY_1,
	PATH_ENEMY_2,
	PATH_ENEMY_3
};

enum e_pathDeath{
	PATH_DEATH = 0,
	PATH_DEATH_1,
	PATH_DEATH_2,
	PATH_DEATH_3
};

typedef struct s_enemy
{
	void	*img;
	int		x;
	int		y;
}	t_enemy;

typedef struct s_character
{
	void	*img;
	int		move;
	char	*str;
	int		collect;
	int		x;
	int		y;
	int		state;
}	t_character;

typedef struct s_map
{
	char	*map;
	int		width;
	int		height;
}	t_map;

typedef struct s_exit
{
	void	*img;
	int		x;
	int		y;
}	t_exit;

typedef struct s_count
{
	int	exit;
	int	collectible;
	int	player;
	int	enemy;
}	t_count;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	t_map		map;
	t_map		map_ckeck;
	void		*wall;
	void		*floor;
	t_exit		exit;
	void		*collectible;
	t_character	character;
	t_count		count_all;
	t_enemy		**enemy;
	int			i;
}	t_game;

int		ft_strcmp(char *s1, char *s2);
char	*animation_exit(enum e_pathExit p);
char	*animation_enemy(enum e_pathEnemy p);
char	*animation_death(enum e_pathDeath p);
int		render_next_frame(t_game *game);
void	init_counter(t_game *game);
void	check_map_error_count(t_game *game);
void	init_textures(t_game *game);
void	init_map(t_game *game);
int		key_action(int keycode, t_game *game);
int		key_hook(int keycode, t_game *game);
void	add_counter(t_game *game);
void	read_map(t_game *game, char *path);
int		chaeck_map_name(const char *av);
char	*remove_slash_n(char *str);
int		exit_game(void);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
char	*ft_itoa_utils(int num);
void	check_map_form(t_game *game, int lines, int colums);
void	ft_init_game(t_game *game, char *path);
int		open_exit(t_game *game);
void	check_path_finder(t_game *game, char *path);
int		count_slash_n(char *str);
void	init_enemy_game(t_game *game);
void	init_enemy(t_game *game);
void	add_game_over(t_game *game);
void	check_map_name(char *map, int flag);
void	init_textures_enemy(t_game *game, int img_width, int img_height);

#endif