/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_rectangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:19:43 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/14 15:19:44 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_is_rectangle(t_game *game)
{
	int	i;
	int	temp;

	i = 0;
	temp = ft_strlen(game->draw.map[i]);
	i++;
	while (game->draw.map[i])
	{
		if (ft_strlen(game->draw.map[i]) != temp)
		{
			free_split(game->draw.map);
			ft_error("Invalid map: not a rectangle\n");
		}
		i++;
	}
}
