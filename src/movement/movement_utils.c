/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuhayrap <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 16:41:45 by yuhayrap          #+#    #+#             */
/*   Updated: 2024/03/13 16:41:47 by yuhayrap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void change_position(t_game *game, char direction)
{
    if (direction == 'R')
        game->position.x++;
    else if (direction == 'L')
        game->position.x--;
    else if (direction == 'U')
        game->position.y--;
    else if (direction == 'D')
        game->position.y++;
}

void	move_to_empty(t_game *game, int	y, int x, char direction)
{
	pitw(game, y, x, 'P');
	if (game->draw.map[game->position.y][game->position.x] == 'E')
		pitw(game, game->position.y, game->position.x, 'E');
	else
		pitw(game, game->position.y, game->position.x, '0');
	change_position(game, direction);
	game->step++;
}

void	move_to_enemy(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free_split(game->draw.map);
	ft_error("You Lost\n");
}

void	move_to_collectible(t_game *game, int y, int x, char direction)
{
	pitw(game, y, x, 'P');
	if (game->draw.map[game->position.y][game->position.x] == 'E')
		pitw(game, game->position.y, game->position.x, 'E');
	else
		pitw(game, game->position.y, game->position.x, '0');
	game->draw.map[y][x] = '0';
    change_position(game, direction);
	game->step++;
	game->counter.collectible--;
}

void	move_to_exit(t_game *game, int y, int x, char direction)
{
	if (game->counter.collectible == 0)
	{
		free_split(game->draw.map);
		write(1, "You Win!\n", 9);
		system("leaks so_long");
		exit(0);
	}
	pitw(game, y, x, 'P');
	pitw(game, game->position.y, game->position.x, '0');
    change_position(game, direction);
	game->step++;
}