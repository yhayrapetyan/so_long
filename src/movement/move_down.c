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

static void	move_to_empty(t_game *game)
{
	pitw(game, game->position.y + 1, game->position.x, 'P');
	if (game->draw.map[game->position.y][game->position.x] == 'E')
		pitw(game, game->position.y, game->position.x, 'E');
	else
		pitw(game, game->position.y, game->position.x, '0');
	game->position.y++;
	game->step++;
}

static void	move_to_enemy(t_game *game)
{
	//temp solution
	mlx_destroy_window(game->mlx, game->win);
	free_split(game->draw.map);
	ft_error("You Lost\n");
}

static void	move_to_collectible(t_game *game)
{
	pitw(game, game->position.y + 1, game->position.x, 'P');
	pitw(game, game->position.y, game->position.x, '0');
	game->draw.map[game->position.y + 1][game->position.x] = '0';
	game->position.y++;
	game->step++;
	game->counter.collectible--;
}

static void	move_to_exit(t_game *game)
{
	if (game->counter.collectible == 0)
	{
		//temp solution
		free_split(game->draw.map);
		write(1, "You Win!\n", 9);
		system("leaks so_long");
		exit(0);
	}
	pitw(game, game->position.y + 1, game->position.x, 'P');
	pitw(game, game->position.y, game->position.x, '0');
	game->position.y++;
	game->step++;
}

void	move_down(t_game *game)
{
	if (game->draw.map[game->position.y + 1][game->position.x] == '0')
		move_to_empty(game);
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'X')
		move_to_enemy(game);
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'C')
		move_to_collectible(game);
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'E')
		move_to_exit(game);
	else if (game->draw.map[game->position.y + 1][game->position.x] == 'P')
		move_to_empty(game);
}
