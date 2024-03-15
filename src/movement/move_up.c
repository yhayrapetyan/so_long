/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 14:28:30 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 14:28:32 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_game *game)
{
	if (game->draw.map[game->position.y - 1][game->position.x] == '0')
		move_to_empty(game, game->position.y - 1, game->position.x, 'U');
	else if (game->draw.map[game->position.y - 1][game->position.x] == 'X')
		move_to_enemy(game);
	else if (game->draw.map[game->position.y - 1][game->position.x] == 'C')
		move_to_collectible(game, game->position.y - 1, game->position.x, 'U');
	else if (game->draw.map[game->position.y - 1][game->position.x] == 'E')
		move_to_exit(game, game->position.y - 1, game->position.x, 'U');
	else if (game->draw.map[game->position.y - 1][game->position.x] == 'P')
		move_to_empty(game, game->position.y - 1, game->position.x, 'U');
}
