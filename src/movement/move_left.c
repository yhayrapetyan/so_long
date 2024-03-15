/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:41:34 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 16:41:35 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *game)
{
	if (game->draw.map[game->position.y][game->position.x - 1] == '0')
		move_to_empty(game, game->position.y, game->position.x - 1, 'L');
	else if (game->draw.map[game->position.y][game->position.x - 1] == 'X')
		move_to_enemy(game);
	else if (game->draw.map[game->position.y][game->position.x - 1] == 'C')
		move_to_collectible(game, game->position.y, game->position.x - 1, 'L');
	else if (game->draw.map[game->position.y][game->position.x - 1] == 'E')
		move_to_exit(game, game->position.y, game->position.x - 1, 'L');
	else if (game->draw.map[game->position.y][game->position.x - 1] == 'P')
		move_to_empty(game, game->position.y, game->position.x - 1, 'L');
}
