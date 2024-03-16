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
# define GREEN "\033[1;32m"


# define SPRITE_SIZE 32
# define SPEED 200
# define STR_COLOR 0xFFFFFF

# define WALL_PATH "./img/wall.xpm"
# define PLAYER_PATH "./img/player.xpm"
# define EMPTY_PATH "./img/empty.xpm"
# define COLLECTIBLE_PATH "./img/collectible.xpm"
# define EXIT_PATH "./img/exit.xpm"
# define FRAME1 "./img/enemy/frame1.xpm"
# define FRAME2 "./img/enemy/frame2.xpm"
# define FRAME3 "./img/enemy/frame3.xpm"
# define FRAME4 "./img/enemy/frame4.xpm"

# define KEY_PRESS 2
# define KEY_PRESS_MASK 1

# define DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_draw
{
	char	*line;
	char	**map;
}			t_draw;

typedef struct s_counter
{
	int	wall;
	int	collectible;
	int	exit;
	int	player;
	int	empty;
	int	enemy;
}	t_counter;

typedef struct s_enemy
{
	void	*frame1;
	void	*frame2;
	void	*frame3;
	void	*frame4;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_point		size;
	t_counter	counter;
	t_point		position;
	int			step;
	t_draw		draw;
	void		*wall;
	void		*player;
	void		*exit;
	void		*collectible;
	t_enemy		enemy;
	void		*empty;
}				t_game;

# ifdef __linux__
#  define UP_KEY    65362
#  define DOWN_KEY  65364
#  define LEFT_KEY  65361
#  define RIGHT_KEY 65363
#  define ESC		65307
#  define STR_X		16
#  define STR_Y		16

# elif defined(__APPLE__)
#  define UP_KEY    126
#  define DOWN_KEY  125
#  define LEFT_KEY  123
#  define RIGHT_KEY 124
#  define ESC		53
#  define STR_X		0
#  define STR_Y		0

# else
#  define UP_KEY    0
#  define DOWN_KEY  0
#  define LEFT_KEY  0
#  define RIGHT_KEY 0
#  define STR_X		0
#  define STR_Y		0
# endif

#endif
