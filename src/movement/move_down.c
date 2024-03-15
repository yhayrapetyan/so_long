/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_down.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:41:26 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 16:41:27 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_game *game)
{
	if (game->draw.map[game->position.y + 1][game->position.x] == '0')
		move_to_empty(game, game->position.y + 1, game->position.x, 'D');
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'X')
		move_to_enemy(game);
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'C')
		move_to_collectible(game, game->position.y + 1, game->position.x, 'D');
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'E')
		move_to_exit(game, game->position.y + 1, game->position.x, 'D');
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'P')
		move_to_empty(game, game->position.y + 1, game->position.x, 'D');
}
