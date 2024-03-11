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
# include <stdio.h>//maybe need to delete
# include <stdlib.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "so_long_utils.h"
# include "./get_next_line/get_next_line.h"


//	VALIDATION
void	check_for_double_new_line(char	*str);
void	is_surrounded_by_walls(char **str);
void	check_is_rectangle(char **str);
void	check_elements(char **str);
void	ft_error(char *message);
int		is_ber(char *str);

// HELPERS
int		ft_strcmp(const char *s1, const char *s2);
// int		ft_strchr(const char *s, int c);
void	play_game(void); // delete
void	free_split(char **str); // maybe delete
void	ft_putnbr_fd(int n, int fd);
int		ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

// MAIN FUNCTIONS
void	init_map(t_game *game, char *path);
void	init_window(t_game *game);
void	init_images(t_game *game);
void	create_map(t_game *game);

#endif
