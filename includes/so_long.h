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

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../mlx/mlx.h"
# include "so_long_utils.h"
# include "get_next_line.h"

//	VALIDATION
int		is_ber(char *str);
void	ft_error(char *message);
void	check_elements(t_game *game);
void	is_map_playable(t_game *game);
void	check_is_rectangle(t_game *game);
void	is_larger_than_screen(t_game *game);
void	is_surrounded_by_walls(t_game *game);
void	check_for_double_new_line(t_game *game);
void	check_is_playable(char **str, t_game *game);

// HELPERS
char	*ft_itoa(int n);
int		ft_strlen(char *str);
void	free_split(char **str);
int		ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_strcpy(char *dest, char *src);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strtrim_end(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	flood_fill(char **tab, t_point size, t_point cur, char to_fill);

// MAIN FUNCTIONS
void	end_game(t_game *game);
int		close_win(t_game *game);
void	create_map(t_game *game);
void	init_window(t_game *game);
void	init_images(t_game *game);
void	move_to_enemy(t_game *game);
int		enemy_animation(t_game *game);
void	init_map(t_game *game, char *path);
int		movement(int keycode, t_game *game);
void	pitw(t_game *game, int i, int j, char element);
void	move_to(t_game *game, int y, int x, char direction);
void	move_to_exit(t_game *game, int y, int x, char direction);
void	move_to_empty(t_game *game, int y, int x, char direction);
void	move_to_collectible(t_game *game, int y, int x, char direction);

#endif
