/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:37:38 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/07 14:37:40 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define RESET_COLOR "\033[0m"

# include <unistd.h>
# include <stdio.h>//maybe need to delete
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"

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

typedef struct s_draw
{
	char	*line;
	char	**map;
	int		height;
	int		weight;
}			t_draw;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_draw	draw;
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

//	VALIDATION
void	check_for_double_new_line(char	*str);
void	check_is_rectangle(char **str);
void	check_elements(char **str);
void	ft_error(char *message);
int		is_ber(char *str);

// HELPERS
int		ft_strcmp(const char *s1, const char *s2);
// int		ft_strchr(const char *s, int c);
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// MAIN FUNCTIONS
void	init_map(t_game *game, char *path);

#endif
