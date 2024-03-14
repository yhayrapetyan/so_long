/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded_by_walls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:20:22 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/14 15:20:24 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_horizontal_wall(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

//need to check for NULL maybe
void	is_surrounded_by_walls(t_game *game)
{
	int	i;

	i = 0;
	if (!is_horizontal_wall(game->draw.map[i]))
	{
		free_split(game->draw.map);
		ft_error("Invalid map: map is not surounded by walls\n");
	}
	while (game->draw.map[i])
	{
		if (game->draw.map[i][0] != '1' || \
			game->draw.map[i][game->size.x - 1] != '1')
		{
			free_split(game->draw.map);
			ft_error("Invalid map: map is not surounded by walls\n");
		}
		i++;
	}
	if (!is_horizontal_wall(game->draw.map[i - 1]))
	{
		free_split(game->draw.map);
		ft_error("Invalid map: map is not surounded by walls\n");
	}
}
