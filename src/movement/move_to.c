/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:28:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 14:28:32 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to(t_game *game, int y, int x, char direction)
{
	if (game->draw.map[y][x] == '0')
		move_to_empty(game, y, x, direction);
	else if (game->draw.map[y][x] == 'X')
		move_to_enemy(game);
	else if (game->draw.map[y][x] == 'C')
		move_to_collectible(game, y, x, direction);
	else if (game->draw.map[y][x] == 'E')
		move_to_exit(game, y, x, direction);
	else if (game->draw.map[y][x] == 'P')
		move_to_empty(game, y, x, direction);
}
