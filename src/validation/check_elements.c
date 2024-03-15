/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:20:00 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/14 15:20:02 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count(t_game *game, char ch, int y, int x)
{
	if (ch == '1')
		game->counter.wall += 1;
	else if (ch == '0')
		game->counter.empty += 1;
	else if (ch == 'P')
	{
		game->counter.player += 1;
		game->position.x = x;
		game->position.y = y;
	}
	else if (ch == 'C')
		game->counter.collectible += 1;
	else if (ch == 'E')
		game->counter.exit += 1;
	else if (ch == 'X')
		game->counter.enemy += 1;
	else
	{
		free_split(game->draw.map);
		ft_error("Invalid map: invalid elements in map\n");
	}
}

static t_counter	init_counter(void)
{
	t_counter	counter;

	counter.wall = 0;
	counter.empty = 0;
	counter.player = 0;
	counter.enemy = 0;
	counter.exit = 0;
	counter.collectible = 0;
	return (counter);
}

void	check_elements(t_game *game)
{
	int			i;
	int			j;

	i = 0;
	game->counter = init_counter();
	while (game->draw.map[i])
	{
		j = 0;
		while (game->draw.map[i][j])
		{
			count(game, game->draw.map[i][j], i, j);
			j++;
		}
		i++;
	}
	if (game->counter.player != 1 || game->counter.exit != 1 || \
		game->counter.collectible < 1)
	{
		free_split(game->draw.map);
		ft_error("Invalid map: invalid elements count in map\n");
	}
}
