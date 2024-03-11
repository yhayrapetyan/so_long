/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:38:14 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/11 13:38:15 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_UTILS_H
# define SO_LONG_UTILS_H

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET_COLOR "\033[0m"

# define SPRITE_SIZE 32
# define WALL_PATH "./img/wall.xpm"
# define PLAYER_PATH "./img/player.xpm"
# define EMPTY_PATH "./img/empty.xpm"
# define COLLECTIBLE_PATH "./img/collectible.xpm"
# define EXIT_PATH "./img/exit.xpm"
# define ENEMY_PATH "./img/enemy.xpm"

typedef struct s_img
{
	void	*ptr;
	int		*pixels;
	int		line_size;
	int		mem;
	int		x;
	int		y;
	int		movements;
}	t_img;

typedef struct s_resolution
{
	int	x;
	int	y;
}			t_resolution;

typedef struct s_draw
{
	char	*line;
	char	**map;
}			t_draw;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_draw	draw;
	t_img	wall;
	t_img	player;
	t_img	exit;
	t_img	collectible;
	t_img	enemy;
	t_img	empty;
}				t_game;

typedef struct s_counter
{
	int	wall;
	int	collectible;
	int	exit;
	int	player;
	int	empty;
	int	enemy;
}	t_counter;

# ifdef __linux__
#  define UP_KEY    65362
#  define DOWN_KEY  65364
#  define LEFT_KEY  65361
#  define RIGHT_KEY 65363

# elif defined(__APPLE__)
#  define UP_KEY    126
#  define DOWN_KEY  125
#  define LEFT_KEY  123
#  define RIGHT_KEY 124

# else
#  define UP_KEY    0
#  define DOWN_KEY  0
#  define LEFT_KEY  0
#  define RIGHT_KEY 0
# endif

#endif
