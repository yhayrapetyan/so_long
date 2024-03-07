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
# include "./mlx/mlx.h"

//	VALIDATION
void	ft_error(char *message);
int		is_ber(char *str);

// HELPERS
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strchr(const char *s, int c);
int		ft_strlen(char *str);

#endif
